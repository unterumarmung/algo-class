#pragma once

#include <algorithm>   // std::min_element, std::swap
#include <functional>  // std::less
#include <iterator>    // std::begin, std::end, std::distance
#include <list>
#include <vector>

#include "util.hpp"

template <typename Range, typename Comparator = std::less<>>
void selection_sort(Range& range, const Comparator& comparator = {}) {
    for (auto it = std::begin(range); it != std::end(range); ++it) {
        auto current_minimal = std::min_element(it, std::end(range), comparator);

        std::swap(*it, *current_minimal);
    }
}

template <typename Range, typename Comparator = std::less<>>
void insertion_sort(Range& range, const Comparator& comparator = {}) {
    auto begin = std::begin(range);

    for (auto it = std::next(begin); it != std::end(range); ++it) {
        auto inner_it = it;

        while (inner_it > begin && comparator(*inner_it, *std::prev(inner_it))) {
            std::swap(*std::prev(inner_it), *inner_it);
            inner_it = std::prev(inner_it);
        }
    }
}

namespace details {
void merge(auto first, auto middle, const auto last, auto const& comparator) {
    const auto initial_first = first;
    const auto initial_middle = middle;
    const auto size = std::distance(first, last);
    using value_type = typename std::iterator_traits<decltype(first)>::value_type;

    // Buffer for merging
    std::vector<value_type> buffer;
    buffer.reserve(size);

    while (first != initial_middle && middle != last) {
        if (comparator(*first, *middle)) {
            buffer.emplace_back(std::move(*first));
            first++;
        } else {
            buffer.emplace_back(std::move(*middle));
            middle++;
        }
    }

    while (first != initial_middle) {
        buffer.emplace_back(std::move(*first));
        first++;
    }
    while (middle != last) {
        buffer.emplace_back(std::move(*middle));
        middle++;
    }

    std::copy(std::make_move_iterator(buffer.begin()), std::make_move_iterator(buffer.end()), initial_first);
}

void merge_sort(auto first, auto last, auto const& comparator) {
    const auto size = std::distance(first, last);

    if (size <= 1) {
        // Nothing to sort
        return;
    }

    const auto middle_point = size / 2;
    const auto middle_it = first + middle_point;
    merge_sort(first, middle_it, comparator);
    merge_sort(middle_it, last, comparator);
    merge(first, middle_it, last, comparator);
}
}  // namespace details

template <typename Range, typename Comparator = std::less<>>
void merge_sort(Range& range, const Comparator& comparator = {}) {
    details::merge_sort(std::begin(range), std::end(range), comparator);
}

namespace details {
void merge(auto first, auto middle, const auto last, auto const& comparator, auto& buffer) {
    const auto initial_first = first;
    const auto initial_middle = middle;

    // Resets the size, but the capacity is not changed
    buffer.clear();

    while (first != initial_middle && middle != last) {
        if (comparator(*first, *middle)) {
            buffer.emplace_back(std::move(*first));
            first++;
        } else {
            buffer.emplace_back(std::move(*middle));
            middle++;
        }
    }

    while (first != initial_middle) {
        buffer.emplace_back(std::move(*first));
        first++;
    }
    while (middle != last) {
        buffer.emplace_back(std::move(*middle));
        middle++;
    }

    std::copy(std::make_move_iterator(buffer.begin()), std::make_move_iterator(buffer.end()), initial_first);
}

void merge_sort(auto first, auto last, auto const& comparator, auto& buffer) {
    const auto size = std::distance(first, last);

    if (size <= 1) {
        // Nothing to sort
        return;
    }

    const auto middle_point = size / 2;
    const auto middle_it = first + middle_point;
    merge_sort(first, middle_it, comparator, buffer);
    merge_sort(middle_it, last, comparator, buffer);
    merge(first, middle_it, last, comparator, buffer);
}
}  // namespace details

template <typename Range, typename Comparator = std::less<>>
void merge_sort_optimized(Range& range, const Comparator& comparator = {}) {
    const auto size = std::distance(std::begin(range), std::end(range));
    // Buffer for merging
    std::vector<typename Range::value_type> buffer;
    buffer.reserve(size);
    details::merge_sort(std::begin(range), std::end(range), comparator, buffer);
}

namespace heap {

inline size_t get_parent(size_t i) noexcept { return (i - 1) / 2; }

inline size_t get_left_child(size_t i) noexcept { return 2 * i + 1; }

inline size_t get_right_child(size_t i) noexcept { return 2 * i + 2; }

void sift_down(auto& array, size_t index, size_t size, const auto& comparator) {
    while (get_left_child(index) < size) {
        auto new_index = get_left_child(index);

        const auto right_child_exists = [size](const auto index) { return get_right_child(index) < size; };

        const auto compare_right_and_left = [&array, &comparator](const auto index) {
            return comparator(array[get_right_child(index)], array[get_left_child(index)]);
        };

        if (right_child_exists(index) && compare_right_and_left(index)) {
            new_index = get_right_child(index);
        }

        const auto is_less_or_equal = [&comparator](const auto& lhs, const auto& rhs) {
            return comparator(lhs, rhs) && !comparator(rhs, lhs);
        };

        if (is_less_or_equal(array[index], array[new_index])) {
            break;
        }

        std::swap(array[index], array[new_index]);

        index = new_index;
    }
}

void make_heap(auto& array, const auto& comparator) {
    for (int64_t i = std::size(array) / 2; i >= 0; --i) {
        sift_down(array, i, std::size(array), comparator);
    }
}

}  // namespace heap

template <typename Range, typename Comparator = std::less<>>
void heap_sort(Range& range, const Comparator& comparator = {}) {
    const auto total_size = std::size(range);

    if (total_size == 0) {
        return;
    }

    const auto opposite_comparator = [&comparator](auto&& lhs, auto&& rhs) { return comparator(rhs, lhs); };

    heap::make_heap(range, opposite_comparator);

    auto heap_size = total_size;
    for (size_t i = 0; i < total_size - 1; ++i) {
        std::swap(range[0], range[total_size - i - 1]);
        heap_size--;
        heap::sift_down(range, 0, heap_size, opposite_comparator);
    }
}

namespace quick {

template <typename Iter>
Iter partition(Iter first, Iter last, const auto& comparator) {
    const auto size = std::distance(first, last);
    const auto& pivot = *(first + get_random_value() % size);

    auto left = first;
    auto right = std::prev(last);

    while (left <= right) {
        while (comparator(*left, pivot)) {
            ++left;
        }
        while (comparator(pivot, *right)) {
            --right;
        }
        if (left >= right) {
            break;
        }
        std::swap(*left, *right);
        left++;
        right--;
    }

    return right + 1;
}

template <typename Iter>
void sort(Iter first, Iter last, const auto& comparator) {
    if (first < std::prev(last)) {
        auto middle = quick::partition(first, last, comparator);
        quick::sort(first, middle, comparator);
        quick::sort(middle, last, comparator);
    }
}

}  // namespace quick

template <typename Range, typename Comparator = std::less<>>
void quick_sort(Range& range, const Comparator& comparator = {}) {
    quick::sort(std::begin(range), std::end(range), comparator);
}

template <typename Range, typename Comparator = std::less<>>
void bucket_sort(Range& range, const Comparator& comparator = {}) {
    using value_type = typename std::iterator_traits<decltype(std::begin(range))>::value_type;
    std::vector<std::list<value_type>> buckets(std::size(range));

    auto min = *std::min_element(std::begin(range), std::end(range), comparator);

    for (auto&& element : range) {
        const auto k = static_cast<size_t>((element - min) / std::size(range));
        buckets[k].push_back(element);
    }

    for (auto&& bucket : buckets) {
        bucket.sort(comparator);
    }

    auto iter = std::begin(range);

    for (auto&& bucket : buckets) {
        for (auto&& element : bucket) {
            *iter = element;
            iter++;
        }
    }
}
