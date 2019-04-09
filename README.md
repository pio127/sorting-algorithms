# Sorting algorithms
[![Build Status](https://travis-ci.com/pio127/sorting-algorithms.svg?branch=master)](https://travis-ci.com/pio127/sorting-algorithms)

Basic sorting algorithms implementations with Catch2 library used for unit testing.
Uses Clang compiler and works under Linux and Windows.
## Install
First run only(preparing catch2 library object file):
```
chmod +x ./PREPARE_CATCH2_FOR_TESTING.sh RUN_TEST.sh
./PREPARE_CATCH2_FOR_TESTING.sh
```
After any change in source code(tested code):
```
./RUN_TEST.sh
