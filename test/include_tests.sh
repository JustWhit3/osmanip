#!/bin/bash

# $1: the input .cpp file to be tested for include. Use complete path in string format.

#====================================================
#     Multiple include tests
#====================================================
touch include_one.hpp
echo "#ifndef INCLUDE_ONE" >> include_one.hpp
echo "#define INCLUDE_ONE" >> include_one.hpp
echo "#include <osmanip/${1}>" >> include_one.hpp
echo "#endif" >> include_one.hpp
touch include_two.hpp
echo "#ifndef INCLUDE_TWO" >> include_two.hpp
echo "#define INCLUDE_TWO" >> include_two.hpp
echo "#include <osmanip/${1}>" >> include_two.hpp
echo "#endif" >> include_two.hpp
touch multiple_include.cpp
echo "#include \"include_one.hpp\"" >> multiple_include.cpp
echo "#include \"include_two.hpp\"" >> multiple_include.cpp
echo "int main() {}" >> multiple_include.cpp
g++ -std=c++17 multiple_include.cpp
rm include_one.hpp
rm include_two.hpp
rm multiple_include.cpp
rm a.out