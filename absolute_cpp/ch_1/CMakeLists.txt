cmake_minimum_required(VERSION 3.3)
project(ch_1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES ch_1_main.cpp 1_1.cpp 1_1.h 1_2.cpp 1_2.h)
add_executable(ch_1 ${SOURCE_FILES})