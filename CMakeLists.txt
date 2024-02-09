# CMake Version
cmake_minimum_required(VERSION 3.27.8)
# Project Name
project(mkr_common_lib)

# C++ Version
set(CMAKE_CXX_STANDARD 20)

# Compiler Flags
set(CMAKE_CXX_FLAGS "-std=c++20 -O3")

# mkr Engine
set(SRC_DIR "src/")
file(GLOB_RECURSE SRC_FILES LIST_DIRECTORIES true CONFIGURE_DEPENDS
        "${SRC_DIR}/*.h"
        "${SRC_DIR}/*.c"
        "${SRC_DIR}/*.hpp"
        "${SRC_DIR}/*.cpp")
add_library(${PROJECT_NAME} ${SRC_FILES})

# Target
set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)
target_include_directories(${PROJECT_NAME} PUBLIC ${SRC_DIR})

# Test
enable_testing()
add_subdirectory(test)