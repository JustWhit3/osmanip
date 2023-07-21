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

# Create executables
set( UNIT "osmanip_unit_tests" )
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
    set( COMPILE_FLAGS "/Wall /Yd /Oy" )
else()
    if( CMAKE_BUILD_TYPE STREQUAL "Debug" )
        set( COMPILE_FLAGS "-Wall -Wextra -pedantic -Wno-reorder -fsanitize=address,undefined -fno-omit-frame-pointer -g" )
    else()
        set( COMPILE_FLAGS "-Wall -Wextra -pedantic -Wno-reorder -fsanitize=address,undefined -fno-omit-frame-pointer" )
    endif()
endif()
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${COMPILE_FLAGS}" )

# Adding cppcheck properties
if( CMAKE_BUILD_TYPE STREQUAL "Debug" )
    set( cppcheck cppcheck "--enable=warning" "--inconclusive" "--force" "--inline-suppr" )
    set_target_properties( ${UNIT} PROPERTIES CXX_CPPCHECK ${cppcheck})
endif()

# Link to doctest
find_package( doctest )
target_link_libraries( ${UNIT} PUBLIC doctest::doctest )

# Link to arsenalgear
find_package( arsenalgear )
target_link_libraries( ${UNIT} PUBLIC arsenalgear::arsenalgear )
target_link_libraries( ${UNIT} PRIVATE osmanip::osmanip )