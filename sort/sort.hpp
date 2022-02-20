#pragma once

#include <algorithm>   // std::min_element, std::swap
#include <functional>  // std::less
#include <iterator>    // std::begin, std::end, std::distance

/// @brief Implementation of swap with ADL enabled
void adl_swap(auto&& lhs, auto&& rhs) {
    using std::swap;
    swap(lhs, rhs);
}

template <typename Range, typename Comparator = std::less<>>
void selection_sort(Range& range, const Comparator& comparator = {}) {
    for (auto it = std::begin(range); it != std::end(range); ++it) {
        auto current_minimal = std::min_element(it, std::end(range), comparator);

        adl_swap(*it, *current_minimal);
    }
}

template <typename Range, typename Comparator = std::less<>>
void insertion_sort(Range& range, const Comparator& comparator = {}) {
    auto begin = std::begin(range);

    for (auto it = std::next(begin); it != std::end(range); ++it) {
        auto inner_it = it;

        while (inner_it > begin && comparator(*inner_it, *std::prev(inner_it))) {
            adl_swap(*std::prev(inner_it), *inner_it);
            inner_it = std::prev(inner_it);
        }
    }
}

namespace details {
void merge(auto first, auto middle, const auto last, auto const& comparator) {
    const auto initial_first = first;
    const auto initial_middle = middle;
    const auto size = std::distance(first, last);
    using value_type = std::iterator_traits<decltype(first)>::value_type;

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