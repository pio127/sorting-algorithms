#include "quick_sort.h"

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
    size_t pivotPosition =
        partitionWithHoareSelection(vec, leftIndex, rightIndex);
    quickSortElements(vec, leftIndex, pivotPosition);
    quickSortElements(vec, pivotPosition + 1, rightIndex);
  }
}

size_t partitionWithHoareSelection(std::vector<int> &vec, size_t leftIndex,
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
    // Swap these elements if i and j did not meet.
    if (i < j) {
      std::swap(vec[i], vec[j]);
      i++;
      j--;
    } else {
      return j;
    }
  }
}