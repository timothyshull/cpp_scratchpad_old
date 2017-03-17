cmake_minimum_required(VERSION 3.6)
project(sfinae)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -w")

add_executable(type_sfinae type_sfinae.cpp)
add_executable(expression_sfinae expression_sfinae.cpp)
add_executable(expression_sfinae2 expression_sfinae2.cpp)
