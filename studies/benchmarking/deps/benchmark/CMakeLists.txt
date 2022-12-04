# Project settings
cmake_minimum_required( VERSION 3.15 )

project( osmanip-dependencies-benchmark
    VERSION 1.0
    DESCRIPTION "Build system for osmanip benchmark dependency."
    LANGUAGES CXX
)

# Error if building out of a build directory
file( TO_CMAKE_PATH "${PROJECT_BINARY_DIR}/CMakeLists.txt" LOC_PATH )
if( EXISTS "${LOC_PATH}" )
    message( FATAL_ERROR "You cannot build in a source directory (or any directory with "
                         "CMakeLists.txt file). Please make a build subdirectory. Feel free to "
                         "remove CMakeCache.txt and CMakeFiles." )
endif()

# Fetch the package
find_package( benchmark )

if( NOT benchmark_FOUND )
    include(FetchContent)
    FetchContent_Declare(
      benchmark
      GIT_REPOSITORY "https://github.com/google/benchmark"
      GIT_TAG main
    )
    message( STATUS "Fetching benchmark..." )
    FetchContent_MakeAvailable( benchmark )
endif()