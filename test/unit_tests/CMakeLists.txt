# CMake project settings
cmake_minimum_required( VERSION 3.15 )

project( osmanip-unit-tests
    VERSION 1.0
    DESCRIPTION "Build system for osmanip unit tests."
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

# Other settings for paths
include_directories( ${CMAKE_CURRENT_SOURCE_DIR}/../../include )

# Declare executables vars
if( WIN32 )
    set( UNIT "osmanip_unit_tests.exe" )
else()
    set( UNIT "osmanip_unit_tests" )
endif()

# Create executables
add_executable( ${UNIT} 
    graphics/tests_canvas.cpp 
    graphics/tests_plot_2D.cpp
    manipulators/tests_cursor.cpp 
    manipulators/tests_common.cpp 
    manipulators/tests_colsty.cpp 
    manipulators/tests_decorator.cpp
    progressbar/tests_progress_bar.cpp
    progressbar/tests_multi_progress_bar.cpp
    utility/tests_windows.cpp
    utility/tests_strings.cpp
    utility/tests_output_redirector.cpp
)

# Adding specific compiler flags
if( CMAKE_CXX_COMPILER_ID STREQUAL "MSVC" )
    set( COMPILE_FLAGS "/Wall /Yd" )
else()
    set( COMPILE_FLAGS "-Wall -Wextra -pedantic -Wno-reorder" )
endif()
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${COMPILE_FLAGS}")

# Adding linker flags
find_package( doctest )
target_link_libraries( ${UNIT} PRIVATE doctest::doctest )
find_package( arsenalgear )
target_link_libraries( ${UNIT} PRIVATE arsenalgear::arsenalgear )
target_link_libraries( ${UNIT} PUBLIC osmanip::osmanip )