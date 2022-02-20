set(SORT_SOURCES main.cpp)
set(SORT_HEADERS sort.hpp util.hpp)
set(SORT_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(sort ${SORT_SOURCES} ${SORT_HEADERS})

target_link_libraries(sort PRIVATE csv)

add_subdirectory(test)
