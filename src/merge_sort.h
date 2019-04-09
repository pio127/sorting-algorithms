#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include <iostream>
#include <vector>

std::vector<int> mergeSort(std::vector<int> vec);
std::vector<int> merge(const std::vector<int> &left,
                       const std::vector<int> &right);
std::vector<int> splitForMergeSort(std::vector<int> &vec);

#endif