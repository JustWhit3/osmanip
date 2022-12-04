# Project settings
cmake_minimum_required( VERSION 3.15 )

project( osmanip-dependencies-termcolor
    VERSION 1.0
    DESCRIPTION "Build system for osmanip termcolor dependency."
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
find_package( termcolor )

if( NOT termcolor_FOUND )
    include(FetchContent)
    FetchContent_Declare(
      termcolor
      GIT_REPOSITORY "https://github.com/ikalnytskyi/termcolor"
      GIT_TAG master
    )
    message( STATUS "Fetching termcolor..." )
    FetchContent_MakeAvailable( termcolor )
endif()