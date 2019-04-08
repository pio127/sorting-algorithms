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
  object_file_extension=".obj"
elif [ "$OS" = "Linux" ]; then
  compiler="clang++"
  cpp14_flag="-std=c++14"
  object_file_extension=".o"
else
 echo "Unknown system"
 exit 1
fi

$compiler test_sorting_algorithms.cpp -c $cpp14_flag
$compiler src/sorting_algorithms.cpp -c $cpp14_flag
$compiler test_main$object_file_extension \
test_sorting_algorithms$object_file_extension \
sorting_algorithms$object_file_extension $cpp14_flag -o  tests && ./tests