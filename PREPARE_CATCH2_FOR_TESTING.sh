#!/bin/bash

check_OS="$(uname -s)"
case "${check_OS}" in
    Linux*)     OS=Linux;;
    CYGWIN*)    OS=Windows;;
    MINGW*)     OS=Windows;;
esac

echo "System recognized: $OS"

if [ "$OS" = "Windows" ]; then
  compiler="clang-cl"
elif [ "$OS" = "Linux" ]; then
  compiler="clang++"
else
 echo "Unknown system"
 exit 1
fi

$compiler test_main.cpp -c -std:c++14
$compiler src/sorting_algorithms.cpp -c -std:c++14
$compiler test_sorting_algorithms.cpp -c -std:c++14
$compiler test_main.obj test_sorting_algorithms.obj sorting_algorithms.obj -std:c++14 -o tests

if [ $? -eq 0 ]; then
  echo "Success: Catch2 build on $OS and is ready for runnig tests(use RUN_TEST.sh from now on)"
fi
