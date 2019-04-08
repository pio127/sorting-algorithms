#!/bin/bash

clang-cl test_sorting_algorithms.cpp -c -std:c++14
clang-cl src/sorting_algorithms.cpp -c -std:c++14
clang-cl test_main.obj test_sorting_algorithms.obj sorting_algorithms.obj -std:c++14 -o  tests && ./tests