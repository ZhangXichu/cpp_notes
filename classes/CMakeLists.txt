cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 20)

project(classes)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}")
message(STATUS "CMAKE_SOURCE_DIR = ${CMAKE_SOURCE_DIR}")

# Include the directory containing header files
include_directories(${CMAKE_SOURCE_DIR})

add_executable(handle handle.cpp)
add_executable(handle_p handle_p.cpp)
