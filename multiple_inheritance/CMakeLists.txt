cmake_minimum_required(VERSION 3.6)
project(multiple_inheritance)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(basics basics.cpp)
add_executable(private private.cpp)
add_executable(protected protected.cpp)
add_executable(public public.cpp)
add_executable(virtual_base virtual_base.cpp)
add_executable(virtual_base2 virtual_base2.cpp)
