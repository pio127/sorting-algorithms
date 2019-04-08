#include "catch.hpp"
#include "src/sorting_algorithms.h"

TEST_CASE("Testing all sorting algorithms") {
    std::vector<int> unsorted{4, 3, 2, 1};
    std::vector<int> sorted{1, 2, 3, 4};
    REQUIRE(bubbleSort(unsorted) == sorted);
    REQUIRE(mergeSort(unsorted) == sorted);
}