# CMake project settings
cmake_minimum_required( VERSION 3.15 )

project( osmanip-benchmarks
    VERSION 1.0
    DESCRIPTION "Build system for osmanip benchmarks."
    LANGUAGES CXX
)

# Error if building out of a build directory
file( TO_CMAKE_PATH "${PROJECT_BINARY_DIR}/CMakeLists.txt" LOC_PATH )
if( EXISTS "${LOC_PATH}" )
    message( FATAL_ERROR "You cannot build in a source directory (or any directory with "
                         "CMakeLists.txt file). Please make a build subdirectory. Feel free to "
                         "remove CMakeCache.txt and CMakeFiles." )
endif()

# Set compiler options
set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_CXX_STANDARD_REQUIRED ON )
set( CMAKE_CXX_EXTENSIONS OFF )

# Fetching dependencies
add_subdirectory( deps )

# Other settings for paths
include_directories( ../.. )

# Creating the static library
file( GLOB_RECURSE source ../../src/*cpp )
add_library( osmanip STATIC ${source} )
add_library( osmanip::osmanip ALIAS osmanip )

# Create executables
if( WIN32 )
    set( MANIPULATORS "manipulators.exe" )
else()
    set( MANIPULATORS "manipulators" )
endif()

add_executable( ${MANIPULATORS} src/manipulators.cpp )

# Adding specific compiler flags
if( CMAKE_CXX_COMPILER_ID STREQUAL "MSVC" )
    set( COMPILE_FLAGS "/Wall /Yd /OX /O1" )
else()
    set( COMPILE_FLAGS "-Wall -Wextra -pedantic -Wno-reorder -Wno-unused-function -Wno-unused-parameter -O3 -O1 -falign-functions=32" )
endif()
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${COMPILE_FLAGS}")

# Linking to osmanip
target_link_libraries( ${MANIPULATORS} PUBLIC osmanip::osmanip )

# Linking to benchmark
find_package( benchmark )
target_link_libraries( ${MANIPULATORS} PUBLIC benchmark::benchmark )

# Linking to other deps
target_link_libraries( ${MANIPULATORS} PRIVATE termcolor::termcolor )