#pragma once

#include <algorithm>  // std::iota, std::reverse
#include <vector>

template <typename ValueType = int>
auto generate_unsorted_vector(size_t size) {
    std::vector<ValueType> v(size);
    std::iota(v.begin(), v.end(), 0);
    std::reverse(v.begin(), v.end());

    return v;
}
