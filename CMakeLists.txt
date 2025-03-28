cmake_minimum_required(VERSION 3.30)
project(leetcode_cpp)

# set cpp standard
set(CMAKE_CXX_STANDARD 23)

# add Google Test
add_subdirectory(third_party/gtest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# problems libraries
add_library(problem2780_lib src/p2780/Solution.cpp src/p2780/Solution.h)

# add main executable
add_executable(leetcode_cpp main.cpp)
target_link_libraries(leetcode_cpp problem2780_lib)

# enable testing
enable_testing()

# add test executable
add_executable(leetcode_cpp_tests
        tests/p2780/SolutionTest.cpp
)
target_link_libraries(leetcode_cpp_tests
        GTest::gtest
        GTest::gtest_main
        problem2780_lib
        pthread
)

# add tests
include(GoogleTest)
gtest_discover_tests(leetcode_cpp_tests)