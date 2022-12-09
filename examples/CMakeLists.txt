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
include_directories( ${CMAKE_CURRENT_SOURCE_DIR}/../include )

# Set compiler options
set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_CXX_STANDARD_REQUIRED ON )
set( CMAKE_CXX_EXTENSIONS OFF )

# Declare executables vars
if( WIN32 )
    set( GRAPHICS "osmanip_graphics.exe" )
    set( MANIPULATORS "osmanip_manipulators.exe" )
    set( PROGRESSBAR "osmanip_progressbar.exe" )
    set( REDIRECTION "osmanip_redirection.exe" )
else()
    set( GRAPHICS "osmanip_graphics" )
    set( MANIPULATORS "osmanip_manipulators" )
    set( PROGRESSBAR "osmanip_progressbar" )
    set( REDIRECTION "osmanip_redirection" )
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
target_link_libraries( ${MANIPULATORS} PRIVATE osmanip::osmanip )
target_link_libraries( ${GRAPHICS} PRIVATE osmanip::osmanip )
target_link_libraries( ${PROGRESSBAR} PRIVATE osmanip::osmanip )
target_link_libraries( ${REDIRECTION} PRIVATE osmanip::osmanip )

# Link to arsenalgear
find_package( arsenalgear )
target_link_libraries( ${MANIPULATORS} PUBLIC arsenalgear::arsenalgear )

# Link to Threads
find_package( Threads )
target_link_libraries( ${PROGRESSBAR} PUBLIC Threads::Threads )
target_link_libraries( ${REDIRECTION} PUBLIC Threads::Threads )