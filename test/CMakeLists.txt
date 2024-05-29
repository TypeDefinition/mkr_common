cmake_minimum_required(VERSION 3.27.8)
project(mkr_common_test)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(UT_DIR "ut")
file(GLOB_RECURSE UT_FILES LIST_DIRECTORIES true CONFIGURE_DEPENDS
        "${UT_DIR}/*.h"
        "${UT_DIR}/*.c"
        "${UT_DIR}/*.hpp"
        "${UT_DIR}/*.cpp")
add_executable(${PROJECT_NAME} ${UT_FILES})

include(FetchContent)
FetchContent_Declare(google_test GIT_REPOSITORY https://github.com/google/googletest.git GIT_TAG main)
FetchContent_MakeAvailable(google_test)

target_link_libraries(${PROJECT_NAME} PUBLIC gtest_main mkr_common)

add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})
