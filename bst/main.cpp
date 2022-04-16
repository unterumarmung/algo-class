#include <algorithm>
#include <functional>
#include <iomanip>
#include <iostream>
#include <vector>

#include "tree.hpp"
#include "util.hpp"

int main() {
    const auto size = get_random_int(5, 100);
    const auto v = generate_random_vector(size);

    std::cout << "Generated random vector of " << size << " elements: " << std::endl;
    print_vector(v);
    std::cout << std::endl;

    binary_search_tree<int> tree(v);

    auto node_visitor = [](const auto* node) { std::cout << node->get_value() << ' '; };

    std::cout << "Generated tree: " << std::endl;
    tree.visit_inorder(node_visitor);

    using namespace std::placeholders;
    const auto is_in_tree = std::bind(&decltype(tree)::contains, &tree, _1);
    const bool all_values_from_vector_in_tree = std::all_of(v.begin(), v.end(), is_in_tree);
    std::cout << std::endl;

    std::cout << "The tree contains all the values from the vector: " << std::boolalpha
              << all_values_from_vector_in_tree << std::endl;
}
