cmake_minimum_required(VERSION 3.3)
project(ch_1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(ex_6_1 ex_1.cpp student_record.cpp student_record.h)
add_executable(ex_6_2 ex_2.cpp CounterType.cpp CounterType.h)
