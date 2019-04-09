#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include <iostream>
#include <vector>

std::vector<int> quickSort(std::vector<int> vec);

void quickSortElements(std::vector<int> &vec, size_t leftIndex,
                       size_t right_index);
size_t partitionWithLamutoSelection(std::vector<int> &vec, size_t leftIndex,
                                    size_t rightIndex);
size_t partitionWithHoareSelection(std::vector<int> &vec, size_t leftIndex,
                                   size_t rightIndex);
#endif