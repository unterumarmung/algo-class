#pragma once

#include <concepts>
#include <memory>
#include <type_traits>
template <typename T>
struct binary_search_tree {
    using value_type = T;

    /// @brief copy constructor from any container
    /// @attention enabled only for the containers with the same value_type
    // clang-format off
    template <typename Container>
        requires std::same_as<
                            typename std::remove_cvref_t<Container>::value_type,
                            typename binary_search_tree::value_type
                          >
        // clang-format on
        constexpr binary_search_tree(Container&& c) {
        for (auto&& el : c) {
            insert(el);
        }
    }

    constexpr bool contains(const T& value) { return find(root.get(), value) != nullptr; }

    constexpr bool insert(const T& value) {
        if (root == nullptr) {
            root = std::make_unique<node>(value, nullptr);
            return true;
        }

        auto* current = root.get();
        while (current) {
            if (value > current->value) {
                if (current->right == nullptr) {
                    current->right = std::make_unique<node>(value, current);
                    return true;
                }
                current = current->right.get();
                continue;
            }

            if (value < current->value) {
                if (current->left == nullptr) {
                    current->left = std::make_unique<node>(value, current);
                    return true;
                }
                current = current->left.get();
                continue;
            }

            // At this point we have the node which value is the same with the target
            // That's why we exit -> we do not need to paste the same value twice
            break;
        }
        return false;
    }

    class node {
        T value;
        std::unique_ptr<node> left = nullptr;
        std::unique_ptr<node> right = nullptr;
        node* parent;

        template <std::invocable<node*> Func>
        void visit_inorder(Func&& func) {
            if (left) {
                left->visit_inorder(func);
            }
            func(this);
            if (right) {
                right->visit_inorder(func);
            }
        }
        friend binary_search_tree;

       public:
        constexpr node(T value, node* parent) : value(std::move(value)), parent(parent) {}
        const T& get_value() const { return value; }
    };

    template <std::invocable<node*> Func>
    void visit_inorder(Func&& func) {
        if (root) {
            root->visit_inorder(func);
        }
    }

   private:
    node* find(node* current, const T& value) {
        if (!root || current->value == value) {
            return current;
        }

        if (current->value < value) {
            return find(current->right.get(), value);
        }

        return find(current->left.get(), value);
    }

    std::unique_ptr<node> root;
};
