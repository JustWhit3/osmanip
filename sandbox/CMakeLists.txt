cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 17)
project(osmanip_redirection)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/bin")
set(OSMANIP_DIR "${CMAKE_CURRENT_LIST_DIR}/../")

# This runs `make all` before configuring CMake
# Can't use install.sh unless it can run silently (without interaction from user)
message(STATUS "Building libosmanip")
execute_process(COMMAND python sandbox/scripts/setup.py
        OUTPUT_VARIABLE PROCESS_OUTPUT
        WORKING_DIRECTORY ${OSMANIP_DIR}
        )
message(STATUS ${PROCESS_OUTPUT})

message(STATUS "Looking for libosmanip.a")
find_library(OSMANIP_LIB NAMES osmanip libosmanip losmanip
        PATHS "${OSMANIP_DIR}" "${OSMANIP_DIR}/lib"
        PATH_SUFFIXES "a" REQUIRED
        )

file(GLOB_RECURSE PROJECT_SOURCES
        "${CMAKE_CURRENT_LIST_DIR}/src/*.h"
        "${CMAKE_CURRENT_LIST_DIR}/src/*.cpp"
        )

list(APPEND PROJECT_SOURCES
        "${CMAKE_CURRENT_LIST_DIR}/main.cpp"
        )

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC
        "."
        "${OSMANIP_DIR}/include"
        "${OSMANIP_DIR}/src"
        "${OSMANIP_DIR}/lib"
        )

target_link_libraries(${PROJECT_NAME}
        ${OSMANIP_LIB}
        "pthread"
        )