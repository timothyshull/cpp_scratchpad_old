cmake_minimum_required(VERSION 3.3)
project(concurrency_ch_1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES ch_1_main.cpp 1_1.cpp 1_1.h)
add_executable(concurrency_ch_1 ${SOURCE_FILES})