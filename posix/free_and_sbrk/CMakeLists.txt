cmake_minimum_required(VERSION 3.22)

project(free_and_sbrk VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(free_and_sbrk free_and_sbrk.cpp)

target_include_directories(free_and_sbrk PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})