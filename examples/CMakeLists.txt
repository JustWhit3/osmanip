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

# Adding specific compiler flags
if( CMAKE_CXX_COMPILER_ID STREQUAL "MSVC" )
    set( COMPILE_FLAGS "/Wall /Yd /Oy /Gw" )
else()
    if( CMAKE_BUILD_TYPE STREQUAL "Debug" )
        set( COMPILE_FLAGS "-Wall -Wextra -pedantic -Wno-reorder -fno-omit-frame-pointer -fdata-sections -g" )
    else()
        set( COMPILE_FLAGS "-Wall -Wextra -pedantic -Wno-reorder -fdata-sections" )
    endif()
endif()
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${COMPILE_FLAGS}" )

# Create a function to launch executables
function( launch_exec )

    # Declare executables vars
    set( GRAPHICS "osmanip_graphics" )
    set( MANIPULATORS "osmanip_manipulators" )
    set( PROGRESSBAR "osmanip_progressbar" )
    set( REDIRECTION "osmanip_redirection" )

    # Create executables
    add_executable( ${GRAPHICS} graphics.cpp )
    add_executable( ${MANIPULATORS} manipulators.cpp )
    add_executable( ${PROGRESSBAR} progressbar.cpp )
    add_executable( ${REDIRECTION} redirection.cpp )

    # Adding cppcheck properties
    find_program( CPPCHECK_FOUND cppcheck )
    if ( CPPCHECK_FOUND AND CMAKE_BUILD_TYPE STREQUAL "Debug" )
        set( cppcheck_options "--enable=warning" "--inconclusive" "--force" "--inline-suppr" )
        set_target_properties( ${GRAPHICS} PROPERTIES CXX_CPPCHECK "${CPPCHECK_FOUND}" )
        set_target_properties( ${MANIPULATORS} PROPERTIES CXX_CPPCHECK "${CPPCHECK_FOUND}" )
        set_target_properties( ${PROGRESSBAR} PROPERTIES CXX_CPPCHECK "${CPPCHECK_FOUND}" )
        set_target_properties( ${REDIRECTION} PROPERTIES CXX_CPPCHECK "${CPPCHECK_FOUND}" )
    endif()

    # Link to osmanip
    target_link_libraries( ${MANIPULATORS} PRIVATE osmanip::osmanip )
    target_link_libraries( ${PROGRESSBAR} PRIVATE osmanip::osmanip )
    target_link_libraries( ${GRAPHICS} PRIVATE osmanip::osmanip )
    target_link_libraries( ${REDIRECTION} PRIVATE osmanip::osmanip )

    # Link to pthreads
    find_package( Threads )
    target_link_libraries( ${PROGRESSBAR} PRIVATE Threads::Threads )
    target_link_libraries( ${REDIRECTION} PRIVATE Threads::Threads )
endfunction()

# Compile for every compiler except clang 14
if ( CMAKE_CXX_COMPILER_ID STREQUAL "Clang" AND NOT ${CMAKE_CXX_COMPILER_VERSION} VERSION_GREATER_EQUAL "14.0.0" )
    launch_exec()
endif()

if ( NOT CMAKE_CXX_COMPILER_ID STREQUAL "Clang" )
    launch_exec()
endif()