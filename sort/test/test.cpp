#define CATCH_CONFIG_MAIN

#include <algorithm>
#include <catch.hpp>
#include <sort.hpp>
#include <string>
#include <util.hpp>

TEST_CASE("selection_sort") {
    auto v = generate_unsorted_vector(1000);
    REQUIRE(!std::is_sorted(v.begin(), v.end()));

    selection_sort(v);

    REQUIRE(std::is_sorted(v.begin(), v.end()));
}
TEST_CASE("insertion_sort") {
    auto v = generate_unsorted_vector(1000);
    REQUIRE(!std::is_sorted(v.begin(), v.end()));

    insertion_sort(v);

    REQUIRE(std::is_sorted(v.begin(), v.end()));
}
TEST_CASE("merge_sort") {
    auto v = generate_unsorted_vector(1000);
    REQUIRE(!std::is_sorted(v.begin(), v.end()));

    merge_sort(v);

    REQUIRE(std::is_sorted(v.begin(), v.end()));
}
TEST_CASE("merge_sort_optimized") {
    auto v = generate_unsorted_vector(1000);
    REQUIRE(!std::is_sorted(v.begin(), v.end()));

    merge_sort_optimized(v);

    REQUIRE(std::is_sorted(v.begin(), v.end()));
}
TEST_CASE("heap_sort") {
    auto v = generate_unsorted_vector(1000);
    REQUIRE(!std::is_sorted(v.begin(), v.end()));

    heap_sort(v);

    REQUIRE(std::is_sorted(v.begin(), v.end()));
}
TEST_CASE("quick_sort") {
    auto v = generate_unsorted_vector(1000);
    REQUIRE(!std::is_sorted(v.begin(), v.end()));

    quick_sort(v);

    REQUIRE(std::is_sorted(v.begin(), v.end()));
}
TEST_CASE("bucket_sort") {
    auto v = generate_unsorted_vector(1000);
    REQUIRE(!std::is_sorted(v.begin(), v.end()));

    bucket_sort(v);

    REQUIRE(std::is_sorted(v.begin(), v.end()));
}
