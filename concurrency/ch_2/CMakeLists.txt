cmake_minimum_required(VERSION 3.3)
project(concurrency_ch_2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES ch_2_main.cpp 2_1.cpp 2_1.h 2_3.cpp 2_3.h 2_4.cpp 2_4.h)
add_executable(concurrency_ch_2 ${SOURCE_FILES})