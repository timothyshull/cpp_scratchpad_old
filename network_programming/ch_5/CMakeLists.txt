cmake_minimum_required(VERSION 3.3)
project(network_programming)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(showip showip.c)