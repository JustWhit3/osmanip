# Project settings
cmake_minimum_required( VERSION 3.15 )

project( osmanip-build
    VERSION 1.0
    DESCRIPTION "Build system for osmanip."
    LANGUAGES CXX
)

# Error if building out of a build directory
file( TO_CMAKE_PATH "${PROJECT_BINARY_DIR}/CMakeLists.txt" LOC_PATH )
if( EXISTS "${LOC_PATH}" )
    message( FATAL_ERROR "You cannot build in a source directory (or any directory with "
                         "CMakeLists.txt file). Please make a build subdirectory. Feel free to "
                         "remove CMakeCache.txt and CMakeFiles." )
endif()

# Info about the build type
if( CMAKE_BUILD_TYPE STREQUAL "Debug" )
    message( STATUS "Build type: DEBUG" )
    add_compile_definitions( DEBUG_OSMANIP )
else()
    message( STATUS "Build type: RELEASE" )
endif()

# Set compiler options
set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_CXX_STANDARD_REQUIRED ON )
set( CMAKE_CXX_EXTENSIONS OFF )

# Include directories
include_directories( ${CMAKE_CURRENT_SOURCE_DIR}/include )

# Fetching deps
add_subdirectory( deps )

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

# Creating the static library
file( GLOB_RECURSE SRC_FILES 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/manipulators/*.cpp 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/graphics/*.cpp 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/utility/*.cpp 
)
add_library( osmanip STATIC ${SRC_FILES} )
add_library( osmanip::osmanip ALIAS osmanip )

# Adding cppcheck properties
find_program( CPPCHECK_FOUND cppcheck )
if ( CPPCHECK_FOUND AND CMAKE_BUILD_TYPE STREQUAL "Debug" )
    set( cppcheck_options "--enable=warning" "--inconclusive" "--force" "--inline-suppr" )
    set_target_properties( osmanip PROPERTIES CXX_CPPCHECK "${CPPCHECK_FOUND}" )
endif()

# Format the code
if( CMAKE_BUILD_TYPE STREQUAL "Debug" )
    option( FORMAT "Format the code using clang-format" ON )
    if( FORMAT )
        find_program( CLANG_FORMAT_EXECUTABLE clang-format )
        if( CLANG_FORMAT_EXECUTABLE )
            message( STATUS "clang-format found: ${CLANG_FORMAT_EXECUTABLE}" )
            file( GLOB_RECURSE SOURCE_FILES
                ${CMAKE_SOURCE_DIR}/src/**/*.cpp
                ${CMAKE_SOURCE_DIR}/include/osmanip/**/*.hpp
                ${CMAKE_SOURCE_DIR}/test/unit_tests/**/*.cpp
                ${CMAKE_SOURCE_DIR}/examples/**/*.cpp
            )
            add_custom_target(format
                COMMAND ${CLANG_FORMAT_EXECUTABLE}
                -i
                ${SOURCE_FILES}
            )
            add_dependencies( osmanip format )
        else()
            message(STATUS "clang-format not found. Skipping code formatting.")
        endif()
    endif()
    
endif()

# Compiling unit tests 
if( CMAKE_BUILD_TYPE STREQUAL "Debug" )
    add_subdirectory( test/unit_tests )
else()
    message( STATUS "Skipping tests." )
endif()

# Compiling examples
add_subdirectory( examples )

# Setting installation paths
target_include_directories( osmanip INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include>
)

# Installing headers
INSTALL(
    DIRECTORY include/osmanip
    DESTINATION include
)

# Creating the package files
install( 
    TARGETS osmanip
    EXPORT osmanipTargets
    DESTINATION lib
)

install(
    EXPORT osmanipTargets
    FILE osmanipTargets.cmake
    NAMESPACE osmanip::
    DESTINATION lib/cmake/osmanip
)

# Configure package files
include( CMakePackageConfigHelpers )

configure_package_config_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/cmake/Config.cmake.in
    "${CMAKE_CURRENT_BINARY_DIR}/osmanipConfig.cmake"
    INSTALL_DESTINATION "lib/cmake/osmanip"
    NO_SET_AND_CHECK_MACRO
    NO_CHECK_REQUIRED_COMPONENTS_MACRO
)

write_basic_package_version_file(
  "${CMAKE_CURRENT_BINARY_DIR}/osmanipConfigVersion.cmake"
  VERSION "${Tutorial_VERSION_MAJOR}.${Tutorial_VERSION_MINOR}"
  COMPATIBILITY AnyNewerVersion
)

install( FILES
    ${CMAKE_CURRENT_BINARY_DIR}/osmanipConfig.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/osmanipConfigVersion.cmake
    DESTINATION lib/cmake/osmanip
)

export( EXPORT osmanipTargets
    FILE "${CMAKE_CURRENT_BINARY_DIR}/osmanipTargets.cmake"
)