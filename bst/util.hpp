#pragma once

#include <iostream>
#include <random>
#include <vector>

inline int get_random_int(int first, int last) {
    static std::random_device dev;
    static std::mt19937 rng(dev());
    std::uniform_int_distribution d(first, last);  // distribution in range [1, 6]

    return d(rng);
}

inline std::vector<int> generate_random_vector(int size) {
    std::vector<int> v(size);

    for (auto& el : v) {
        el = get_random_int(0, 255);
    }

    return v;
}

inline void print_vector(const std::vector<int>& v) {
    std::cout << "[";
    for (auto it = v.begin(); it != v.end(); ++it) {
        std::cout << *it;
        if (const bool is_last = it == std::prev(v.end()); !is_last) {
            std::cout << ", ";
        }
    }
    std::cout << "]";
}
