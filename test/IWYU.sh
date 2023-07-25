#!/bin/bash

# Variables
declare -a source_files=(
  "graphics/canvas.cpp"
  "graphics/plot_2D.cpp"
  "manipulators/colsty.cpp"
  "manipulators/common.cpp"
  "manipulators/cursor.cpp"
  "manipulators/decorator.cpp"
  "utility/output_redirector.cpp"
  "utility/iostream.cpp"
  "utility/sstream.cpp"
  "utility/strings.cpp"
  "utility/windows.cpp"
  "utility/generic.cpp"
)

# Source code check
echo ""
echo "======================================================"
echo "     IWYU Checks"
echo "======================================================"
echo ""
for source in "${source_files[@]}"; do
  include-what-you-use \
    -std=c++17 \
    -I/usr/lib/llvm-14/lib/clang/14.0.0/include \
    -Iinclude \
    src/"$source"

  echo ""
  echo "--------------------------------------------------"
  echo ""
done
