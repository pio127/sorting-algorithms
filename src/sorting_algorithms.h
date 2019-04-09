#ifndef SORTING_ALGORITHMS_H
#define SORTING_ALGORITHMS_H

#include <iostream>
#include <vector>

std::vector<int> bubbleSort(std::vector<int> vec);
std::vector<int> selectionSort(std::vector<int> vec);
std::vector<int> insertionSort(std::vector<int> vec);
std::vector<int> mergeSort(std::vector<int> vec);
std::vector<int> quickSort(std::vector<int> vec);

void printVector(const std::vector<int> &vec);
std::vector<int> merge(const std::vector<int> &left,
                       const std::vector<int> &right);
std::vector<int> splitForMergeSort(std::vector<int> &vec);
void quickSortElements(std::vector<int> &vec, size_t leftIndex,
                       size_t right_index);
size_t partitionLamutoMethod(std::vector<int> &vec, size_t leftIndex,
                         size_t rightIndex);
size_t partitionHoareSelection(std::vector<int> &vec, size_t leftIndex,
                         size_t rightIndex);

#endif
