#include "sorting_algorithms.h"

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

/////////////////////////////////////////////////////////////////////
// Merge Sort
/////////////////////////////////////////////////////////////////////
std::vector<int> mergeSort(std::vector<int> vec) {
  std::vector<int> sorted = splitForMergeSort(vec);
  return sorted;
}

std::vector<int> splitForMergeSort(std::vector<int> &vec) {
  if (vec.size() == 1) {
    return vec;
  }
  // Splitting array into two parts
  size_t middle = vec.size() / 2;
  std::vector<int> left(vec.begin(), vec.begin() + middle);
  std::vector<int> right(vec.begin() + middle, vec.end());

  left = splitForMergeSort(left);
  right = splitForMergeSort(right);

  return merge(left, right);
}

std::vector<int> merge(const std::vector<int> &left,
                       const std::vector<int> &right) {

  std::vector<int> merged{};
  size_t leftIndex{0};
  size_t rightIndex{0};

  // Comparing elements from right and left array until one of them
  // has reached the end.
  while (leftIndex < left.size() && rightIndex < right.size()) {
    if (left.at(leftIndex) < right.at(rightIndex)) {
      merged.emplace_back(left.at(leftIndex));
      leftIndex++;
    } else {
      merged.emplace_back(right.at(rightIndex));
      rightIndex++;
    }
  }

  // Adding rest of elements from the second(left or right) array.
  if (leftIndex != left.size()) {
    while (leftIndex < left.size()) {
      merged.emplace_back(left.at(leftIndex));
      leftIndex++;
    }
  } else {
    while (rightIndex < right.size()) {
      merged.emplace_back(right.at(rightIndex));
      rightIndex++;
    }
  }
  return merged;
}

/////////////////////////////////////////////////////////////////////
// Quick Sort
/////////////////////////////////////////////////////////////////////
std::vector<int> quickSort(std::vector<int> vec) {
  quickSortElements(vec, 0, vec.size() - 1);
  return vec;
}

void quickSortElements(std::vector<int> &vec, size_t leftIndex,
                       size_t rightIndex) {
  if (leftIndex < rightIndex) {
    size_t pivotPosition = partitionHoareSelection(vec, leftIndex, rightIndex);
    quickSortElements(vec, leftIndex, pivotPosition);
    quickSortElements(vec, pivotPosition + 1, rightIndex);
  }
}

size_t partitionHoareSelection(std::vector<int> &vec, size_t leftIndex,
                            size_t rightIndex) {
  size_t pivot = vec.at(leftIndex);
  int i = leftIndex;
  int j = rightIndex;

  while (true) {
    // Iterate vector from both sides until there is element greater than
    // pivot on the left part and lesser than pivot on the right.
    while (vec.at(j) > pivot) {
      j--;
    }
    while (vec.at(i) < pivot) {
      i++;
    }
    // Swap these elements if did not meet.
    if (i < j){
      std::swap(vec[i], vec[j]);
      i++;
      j--;
    } else {
      return j;
    }
  }
}