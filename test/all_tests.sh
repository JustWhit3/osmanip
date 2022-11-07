#!/bin/bash

# Compiling
echo ""
echo "======================================================"
echo "     Compiling"
echo "======================================================"
echo ""
make

# System tests
if [ "$1" == "system" ] || [ "$1" == "" ]; then
  echo ""
  ./bin/manipulators
  ./bin/progressbar
  ./bin/redirection
  ./bin/graphics
fi

# Memory tests
if [ "$1" == "memory" ] || [ "$1" == "" ]; then
  echo ""
  echo "======================================================"
  echo "     MEMORY TESTS"
  echo "======================================================"
  ./test/profiling.sh memcheck ./bin/graphics
  ./test/profiling.sh memcheck ./bin/manipulators
  ./test/profiling.sh memcheck ./bin/progressbar
  ./test/profiling.sh memcheck ./bin/redirection
fi

# Threading tests
if [ "$1" == "threading" ] || [ "$1" == "" ]; then
  echo ""
  echo "======================================================"
  echo "     THREADING TESTS"
  echo "======================================================"
  echo ""
  ./test/profiling.sh helgrind ./bin/graphic
  ./test/profiling.sh helgrind ./bin/manipulators
  ./test/profiling.sh helgrind ./bin/progressbar
  ./test/profiling.sh helgrind ./bin/redirection
fi

# Unit tests
if [ "$1" == "unit" ] || [ "$1" == "" ]; then
  echo ""
  echo "======================================================"
  echo "     UNIT TESTS"
  echo "======================================================"
  echo ""
  ./bin/tests
fi

# Include tests
if [ "$1" == "include" ] || [ "$1" == "" ]; then
  echo ""
  echo "======================================================"
  echo "     INCLUDE TESTS"
  echo "======================================================"
  echo ""
  ./test/include_tests.sh graphics/canvas.hpp
  ./test/include_tests.sh graphics/plot_2D.hpp
  ./test/include_tests.sh manipulators/colsty.hpp
  ./test/include_tests.sh manipulators/common.hpp
  ./test/include_tests.sh manipulators/cursor.hpp
  ./test/include_tests.sh manipulators/decorator.hpp
  ./test/include_tests.sh progressbar/multi_progress_bar.hpp
  ./test/include_tests.sh progressbar/progress_bar.hpp
  ./test/include_tests.sh utility/iostream.hpp
  ./test/include_tests.sh utility/options.hpp
  ./test/include_tests.sh utility/output_redirector.hpp
  ./test/include_tests.sh utility/sstream.hpp
  ./test/include_tests.sh utility/strings.hpp
  ./test/include_tests.sh utility/windows.hpp
fi

# Cppcheck
if [ "$1" == "cppcheck" ] || [ "$1" == "" ]; then
  echo ""
  echo "======================================================"
  echo "     CPPCHECK TESTS"
  echo "======================================================"
  echo ""
  cppcheck include/graphics/* include/manipulators/* include/progressbar/* include/utility/* src/graphics/* src/manipulators/* src/progressbar/* src/utility/*
fi

# IWYU
if [ "$1" == "IWYU" ] || [ "$1" == "" ]; then
  echo ""
  echo "======================================================"
  echo "     IWYU TESTS"
  echo "======================================================"
  echo ""
  ./test/IWYU.sh
fi