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

# Include directories
include_directories( "." )

# Fetching deps
add_subdirectory( deps )

# Creating the static library
file( GLOB_RECURSE source src/*cpp )
add_library( osmanip STATIC ${source} )
add_library( osmanip::osmanip ALIAS osmanip )

# Compiling unit tests
add_subdirectory( test/unit_tests )

# Compiling examples
add_subdirectory( examples )

# Installing headers
if( UNIX )
    set( INSTALLATION_DIR_INCLUDE /usr/include )
elseif( APPLE )
    set( INSTALLATION_DIR_INCLUDE /usr/local/include )
elseif( WIN32 )
    set( WIN_INSTALLATION_DIR_INCLUDE "" CACHE STRING "Installation directory for Windows OSs." )
    set( INSTALLATION_DIR_INCLUDE ${WIN_INSTALLATION_DIR_INCLUDE} )
endif()

INSTALL(
    DIRECTORY include/manipulators include/progressbar include/utility include/graphics
    DESTINATION ${INSTALLATION_DIR_INCLUDE}/osmanip
)

# Creating the library dir
if( UNIX )
    set( INSTALLATION_DIR_LIB /usr/lib )
elseif( APPLE )
    set( INSTALLATION_DIR_LIB /usr/local/lib )
elseif( WIN32 )
    set( WIN_INSTALLATION_DIR_LIB "" CACHE STRING "Installation directory for Windows OSs." )
    set( INSTALLATION_DIR_LIB ${WIN_INSTALLATION_DIR_LIB} )
endif()

# Creating the package files
install( 
    TARGETS osmanip
    EXPORT osmanipTargets
    DESTINATION ${INSTALLATION_DIR_LIB}
)

install(
    EXPORT osmanipTargets
    FILE osmanipTargets.cmake
    NAMESPACE osmanip::
    DESTINATION ${INSTALLATION_DIR_LIB}/cmake/osmanip
)

# Configure package files
include( CMakePackageConfigHelpers )

configure_package_config_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/cmake/Config.cmake.in
    "${CMAKE_CURRENT_BINARY_DIR}/osmanipConfig.cmake"
    INSTALL_DESTINATION "${INSTALLATION_DIR_LIB}/cmake/osmanip"
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
    DESTINATION ${INSTALLATION_DIR_LIB}/cmake/osmanip
)

export( EXPORT osmanipTargets
    FILE "${CMAKE_CURRENT_BINARY_DIR}/osmanipTargets.cmake"
)