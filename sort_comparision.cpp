#include <iostream>
#include <vector>
#include <functional>

void bubbleSort(std::vector<int> vec);
void selectionSort(std::vector<int> vec);
void insertionSort(std::vector<int> vec);
void mergeSort(std::vector<int> vec);
void quickSort(std::vector<int> vec);


void printVector(const std::vector<int> &vec);
std::vector<int> merge(
    const std::vector<int> &left, 
    const std::vector<int> &right);
std::vector<int> splitForMergeSort(std::vector<int> &vec);

int main() {

  std::vector<int> vec1{3, 7 ,4, 5, 2, 1, 6};
  std::vector<int> vec2{6, 5, 4, 3, 2 ,1, 0};

  std::cout << "Input numbers: \n";
  printVector(vec1);
  printVector(vec2);
  std::cout << std::endl;

  std::cout << "Bubble sort: \n";
  bubbleSort(vec1);
  bubbleSort(vec2); 
  std::cout << std::endl;

  std::cout << "Selection sort: \n";
  selectionSort(vec1);
  selectionSort(vec2);
  std::cout << std::endl;

  std::cout << "Insertion sort: \n";
  insertionSort(vec1);
  insertionSort(vec2);
  std::cout << std::endl;

  std::cout << "Merge sort: \n";
  mergeSort(vec1);
  mergeSort(vec2);
  std::cout << std::endl;


}

void printVector(const std::vector<int> &vec) {
  for (const auto &elem:vec) {
    std::cout << elem << " ";
  }
  std::cout << '\n';
}

void bubbleSort(std::vector<int> vec) {
  for (size_t x = 0; x < vec.size(); ++x) {
    for (size_t y = 1; y < vec.size() - x; ++ y) {
      if (vec.at(y-1) > vec.at(y)) {
        std::swap(vec.at(y-1), vec.at(y));
      }
    }
  }
  printVector(vec);
}

void selectionSort(std::vector<int> vec) {
  int minimum, indexOfMinimum;
  for (size_t x = 0; x < vec.size(); ++x) {
    minimum = vec.at(x);
    indexOfMinimum = x;
    for (size_t y = x+1; y < vec.size(); ++y) {
      if (vec.at(y) < minimum) {
        minimum = vec.at(y);
        indexOfMinimum = y;
      }
    }
    std::swap(vec.at(x), vec.at(indexOfMinimum));
  }
  printVector(vec);
}

void insertionSort(std::vector<int> vec) {
  for (size_t x = 1; x < vec.size(); ++x) {
    for(size_t y = x; y>0; --y) {
      if (vec.at(y-1) > vec.at(y)) {
        std::swap(vec.at(y-1), vec.at(y));
      } else {
        break;
      }
    }
  }
  printVector(vec);
}
/////////////////////////////////////////////////////////////////////
// Merge Sort
/////////////////////////////////////////////////////////////////////

void mergeSort(std::vector<int> vec) {
  std::vector<int> sorted = splitForMergeSort(vec);
  printVector(sorted);
}

std::vector<int> splitForMergeSort(std::vector<int> &vec) {
    if (vec.size() == 1) {
        return vec;
    }
    // Splitting array into two parts
    size_t middle = vec.size()/2;
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

void quickSort(std::vector<int> vec) {
  std::vector<int> sorted;
  printVector(sorted);
}
