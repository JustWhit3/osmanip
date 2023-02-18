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

# Set compiler options
set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_CXX_STANDARD_REQUIRED ON )
set( CMAKE_CXX_EXTENSIONS OFF )

# Include directories
include_directories( ${CMAKE_CURRENT_SOURCE_DIR} )
include_directories( ${CMAKE_CURRENT_SOURCE_DIR}/include )

# Fetching deps
add_subdirectory( deps )
include_directories( ${CMAKE_CURRENT_BINARY_DIR}/_deps/arsenalgear-src/include )


# Creating the static library
add_library( osmanip STATIC
    src/graphics/canvas.cpp
    src/graphics/plot_2D.cpp
    src/manipulators/cursor.cpp
    src/manipulators/colsty.cpp
    src/manipulators/decorator.cpp
    src/manipulators/common.cpp
    src/utility/iostream.cpp
    src/utility/strings.cpp
    src/utility/output_redirector.cpp
    src/utility/sstream.cpp
    src/utility/windows.cpp
)
add_library( osmanip::osmanip ALIAS osmanip )

# Compiling unit tests 
option( OSMANIP_TESTS "Enable / disable tests." ON )
if( OSMANIP_TESTS )
    add_subdirectory( test/unit_tests )
else()
    message( STATUS "Skipping tests." )
endif()

# Compiling examples
#add_subdirectory( examples )

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