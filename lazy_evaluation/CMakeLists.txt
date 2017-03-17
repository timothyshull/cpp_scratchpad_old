cmake_minimum_required(VERSION 3.4)
project(lazy_evaluation)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp simple_suspension.h susp.h stream.h cell.h)
add_executable(lazy_evaluation ${SOURCE_FILES})