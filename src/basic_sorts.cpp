#include "basic_sorts.h"

/////////////////////////////////////////////////////////////////////
// Bubble Sort
/////////////////////////////////////////////////////////////////////
std::vector<int> bubbleSort(std::vector<int> vec) {
  for (size_t x = 0; x < vec.size(); ++x) {
    for (size_t y = 1; y < vec.size() - x; ++y) {
      if (vec.at(y - 1) > vec.at(y)) {
        std::swap(vec.at(y - 1), vec.at(y));
      }
    }
  }
  return vec;
}

/////////////////////////////////////////////////////////////////////
// Selection Sort
/////////////////////////////////////////////////////////////////////
std::vector<int> selectionSort(std::vector<int> vec) {
  int minimum, indexOfMinimum;
  for (size_t x = 0; x < vec.size(); ++x) {
    minimum = vec.at(x);
    indexOfMinimum = x;
    for (size_t y = x + 1; y < vec.size(); ++y) {
      if (vec.at(y) < minimum) {
        minimum = vec.at(y);
        indexOfMinimum = y;
      }
    }
    std::swap(vec.at(x), vec.at(indexOfMinimum));
  }
  return vec;
}

/////////////////////////////////////////////////////////////////////
// Insertion Sort
/////////////////////////////////////////////////////////////////////
std::vector<int> insertionSort(std::vector<int> vec) {
  for (size_t x = 1; x < vec.size(); ++x) {
    for (size_t y = x; y > 0; --y) {
      if (vec.at(y - 1) > vec.at(y)) {
        std::swap(vec.at(y - 1), vec.at(y));
      } else {
        break;
      }
    }
  }
  return vec;
}