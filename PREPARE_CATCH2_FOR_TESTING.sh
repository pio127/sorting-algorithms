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

if ! [ -x "$(command -v $compiler)" ]; then
	echo "Warning: no $compiler found" >&2
  compiler="g++"
elif ! [ -x "$(command -v $compiler)" ]; then
  echo "Error: no clang or gcc compiler found!"
fi
echo "Compiler used: $compiler"

# Compiling test main for the first time
$compiler test_main.cpp -c $cpp14_flag

if [ $? -eq 0 ]; then
  echo "Success: Catch2 build on $OS and is ready for running tests  
       (use RUN_TEST.sh from now on)"
fi
