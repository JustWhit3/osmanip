#!/bin/bash

# Variables
declare -a header_files=(
  "graphics/canvas.hpp"
  "graphics/plot_2D.hpp"
  "manipulators/colsty.hpp"
  "manipulators/common.hpp"
  "manipulators/cursor.hpp"
  "manipulators/decorator.hpp"
  "progressbar/multi_progress_bar.hpp"
  "progressbar/progress_bar.hpp"
  "utility/output_redirector.hpp"
  "utility/options.hpp"
  "utility/iostream.hpp"
  "utility/sstream.hpp"
  "utility/strings.hpp"
  "utility/windows.hpp"
)

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
)

# Header files check
echo ""
echo "======================================================"
echo "     Header files check"
echo "======================================================"
echo ""
for header in "${header_files[@]}"; do
  include-what-you-use \
    -std=c++17 \
    -I/usr/lib/llvm-14/lib/clang/14.0.0/include \
    include/"$header"

  echo ""
  echo "--------------------------------------------------"
  echo ""
done

# Source code check
echo ""
echo "======================================================"
echo "     Source code check"
echo "======================================================"
echo ""
for source in "${source_files[@]}"; do
  include-what-you-use \
    -std=c++17 \
    -I/usr/lib/llvm-14/lib/clang/14.0.0/include \
    src/"$source"

  echo ""
  echo "--------------------------------------------------"
  echo ""
done
