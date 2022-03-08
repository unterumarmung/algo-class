#include <iostream>

#include "sort.hpp"
#include "util.hpp"

int main() {
    auto vec = generate_unsorted_vector(1000);

    heap_sort(vec);

    for (auto i : vec) {
        std::cout << i << " ";
    }
}
