#include <array>
#include <chrono>
#include <fstream>
#include <iostream>
#include <map>
#include <utility>

#include "sort.hpp"
#include "util.hpp"

auto run_sort(auto sort_fun, auto& vec) {
    using namespace std::chrono;

    auto begin = high_resolution_clock::now();

    sort_fun(vec, {});

    auto end = high_resolution_clock::now();

    return duration_cast<nanoseconds>(end - begin);
}

struct ElementCountWithTime {
    int element_count;
    int64_t time_ns;
};

using result_type = std::map<std::string_view, std::vector<ElementCountWithTime>>;

void dump_csv(const result_type& result) {
    // header
    std::ofstream ss("output.csv");
    ss << "SortName,";
    for (auto&& el : result.begin()->second) {
        ss << el.element_count << ",";
    }
    ss << std::endl;
    for (auto&& [sort_name, sort_data] : result) {
        ss << sort_name << ",";
        for (auto&& [element_count, time] : sort_data) {
            ss << time << ",";
        }
        ss << std::endl;
    }
}

int main() {
    using sort_type = std::vector<int>;
    std::array sorters = {
#define SORT(sort_name) std::pair{&sort_name<sort_type>, #sort_name},
#include "sort.def"
#undef SORT
    };

    result_type result;

    for (int order = 100; order <= 100'000; order *= 10) {
        for (int element_count = order; element_count < order * 10; element_count += order) {
            std::cout << "ELEMENT COUNT: " << element_count << "\n\n";
            for (auto&& [sort_fun, sort_name] : sorters) {
                auto vec = generate_unsorted_vector(element_count);
                auto time = run_sort(sort_fun, vec);

                result[sort_name].push_back({element_count, time.count()});
            }
        }
    }
    dump_csv(result);
}
