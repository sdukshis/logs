cmake_minimum_required(VERSION 3.0)

project(logs CXX)

add_definitions(
    -Wall
    -Wextra
    -Werror
    -std=c++14
)

include_directories(include)

add_executable(test_log src/registry.cpp tests/test.cpp)
