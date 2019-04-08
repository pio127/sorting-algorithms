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
  cpp14_flag="-std:c++14"
elif [ "$OS" = "Linux" ]; then
  compiler="clang++"
  cpp14_flag="-std=c++14"
else
 echo "Unknown system"
 exit 1
fi

$compiler test_sorting_algorithms.cpp -c $cpp14_flag
$compiler src/sorting_algorithms.cpp -c $cpp14_flag
$compiler test_main.obj test_sorting_algorithms.obj sorting_algorithms.obj $cpp14_flag -o  tests && ./tests