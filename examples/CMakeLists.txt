# CMake project settings
cmake_minimum_required( VERSION 3.15 )

project( osmanip-examples
    VERSION 1.0
    DESCRIPTION "Build system for osmanip examples."
    LANGUAGES CXX
)

# Error if building out of a build directory
file( TO_CMAKE_PATH "${PROJECT_BINARY_DIR}/CMakeLists.txt" LOC_PATH )
if( EXISTS "${LOC_PATH}" )
    message( FATAL_ERROR "You cannot build in a source directory (or any directory with "
                         "CMakeLists.txt file). Please make a build subdirectory. Feel free to "
                         "remove CMakeCache.txt and CMakeFiles." )
endif()

# Directories
include_directories( ${CMAKE_CURRENT_SOURCE_DIR}/.. )

# Set compiler options
set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_CXX_STANDARD_REQUIRED ON )
set( CMAKE_CXX_EXTENSIONS OFF )

# Declare executables vars
if( WIN32 )
    set( MANIPULATORS "manipulators.exe" )
    set( PROGRESSBAR "progressbar.exe" )
    set( REDIRECTION "redirection.exe" )
else()
    set( GRAPHICS "graphics" )
    set( MANIPULATORS "manipulators" )
    set( PROGRESSBAR "progressbar" )
    set( REDIRECTION "redirection" )
endif()

# Create executables
add_executable( ${GRAPHICS} graphics.cpp )
add_executable( ${MANIPULATORS} manipulators.cpp )
add_executable( ${PROGRESSBAR} progressbar.cpp )
add_executable( ${REDIRECTION} redirection.cpp )

# Adding specific compiler flags
if( CMAKE_CXX_COMPILER_ID STREQUAL "MSVC" )
    set( COMPILE_FLAGS "/Wall /Yd" )
else()
    set( COMPILE_FLAGS "-Wall -Wextra -pedantic -Wno-reorder" )
endif()
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${COMPILE_FLAGS}")

# Link to osmanip
target_link_libraries( ${MANIPULATORS} PUBLIC osmanip::osmanip )
target_link_libraries( ${GRAPHICS} PUBLIC osmanip::osmanip )
target_link_libraries( ${PROGRESSBAR} PUBLIC osmanip::osmanip )
target_link_libraries( ${REDIRECTION} PUBLIC osmanip::osmanip )

# Link to arsenalgear
find_package( arsenalgear )
target_link_libraries( ${MANIPULATORS} PRIVATE arsenalgear::arsenalgear )

# Link to Threads
find_package( Threads )
target_link_libraries( ${PROGRESSBAR} PUBLIC Threads::Threads )
target_link_libraries( ${REDIRECTION} PUBLIC Threads::Threads )