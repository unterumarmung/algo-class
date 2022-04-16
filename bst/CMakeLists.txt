set(BST_SOURCES main.cpp)
set(BST_HEADERS tree.hpp util.hpp)
set(BST_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(bst ${BST_SOURCES} ${BST_HEADERS})
