#include "merge_sort.h"

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