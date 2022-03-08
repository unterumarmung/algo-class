#pragma once

#include <algorithm>  // std::reverse
#include <numeric>    // std::iota
#include <random>
#include <vector>

template <typename ValueType = int>
auto generate_unsorted_vector(size_t size) {
    std::vector<ValueType> v(size);
    std::iota(v.begin(), v.end(), 0);
    std::reverse(v.begin(), v.end());

    return v;
}

inline auto get_random_value = std::minstd_rand(42);
