#include "catch.hpp"
#include "src/sorting_algorithms.h"

TEST_CASE("Sort algorithm tested:") {
  // Input unsorted arrays
  std::vector<int> unsorted1{4, 3, 2, 6, 1, 5, 7};
  std::vector<int> unsorted2{9, 8, 7, 6, 5, 4, 3, 2, 1};

  // Output sorted arrays
  std::vector<int> sorted1{1, 2, 3, 4, 5, 6, 7};
  std::vector<int> sorted2{1, 2, 3, 4, 5, 6, 7, 8 ,9};

  SECTION("Bubble sort") {
    REQUIRE(bubbleSort(unsorted1) == sorted1);
    REQUIRE(bubbleSort(unsorted2) == sorted2);
  }
  SECTION("Insertion sort") {
    REQUIRE(insertionSort(unsorted1) == sorted1);
    REQUIRE(insertionSort(unsorted2) == sorted2);
  }
  SECTION("Selection sort") {
    REQUIRE(selectionSort(unsorted1) == sorted1);
    REQUIRE(selectionSort(unsorted2) == sorted2);
  }
  SECTION("Merge sort") {
    REQUIRE(mergeSort(unsorted1) == sorted1);
    REQUIRE(mergeSort(unsorted2) == sorted2);
  }
  SECTION("Quick sort") {
    REQUIRE(quickSort(unsorted1) == sorted1);
    REQUIRE(quickSort(unsorted2) == sorted2);
  }
  
}