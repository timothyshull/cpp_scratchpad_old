cmake_minimum_required(VERSION 3.6)
project(binary_repr)

set(CMAKE_CXX_STANDARD 11)

add_executable(binary_repr main.cpp Binary_float_repr.h Binary_integer_repr.h uint_type.h)