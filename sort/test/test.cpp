#define CATCH_CONFIG_MAIN

#include <algorithm>
#include <catch.hpp>
#include <sort.hpp>
#include <string>
#include <util.hpp>

TEST_CASE("sort") {
    SECTION("selection_sort") {
        auto v = generate_unsorted_vector(1000);
        REQUIRE(!std::is_sorted(v.begin(), v.end()));

        selection_sort(v);

        REQUIRE(std::is_sorted(v.begin(), v.end()));
    }
    SECTION("insertion_sort") {
        auto v = generate_unsorted_vector(1000);
        REQUIRE(!std::is_sorted(v.begin(), v.end()));

        insertion_sort(v);

        REQUIRE(std::is_sorted(v.begin(), v.end()));
    }
    SECTION("insertion_sort") {
        auto v = generate_unsorted_vector(1000);
        REQUIRE(!std::is_sorted(v.begin(), v.end()));

        merge_sort(v);

        REQUIRE(std::is_sorted(v.begin(), v.end()));
    }
}
