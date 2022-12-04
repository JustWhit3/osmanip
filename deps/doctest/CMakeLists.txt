# Project settings
cmake_minimum_required( VERSION 3.15 )

project( osmanip-dependencies-doctest
    VERSION 1.0
    DESCRIPTION "Build system for osmanip doctest dependency."
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
find_package( doctest )

if( NOT doctest_FOUND )
    include(FetchContent)
    FetchContent_Declare(
      doctest
      GIT_REPOSITORY "https://github.com/doctest/doctest"
      GIT_TAG master
    )
    message( STATUS "Fetching doctest..." )
    FetchContent_MakeAvailable( doctest )
endif()