cmake_minimum_required(VERSION 3.16)
project(algo-class)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

# Add CSV library

FetchContent_Declare(csv
        URL https://github.com/vincentlaucsb/csv-parser/archive/refs/tags/2.1.3.tar.gz
        )

FetchContent_GetProperties(csv)
if(NOT csv_POPULATED)
    FetchContent_Populate(csv)
    add_subdirectory(${csv_SOURCE_DIR} ${csv_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

# Add Catch2 library

set(CATCH_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/third-party/catch)

add_subdirectory(sort)
