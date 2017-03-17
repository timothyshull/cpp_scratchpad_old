cmake_minimum_required(VERSION 3.6)
project(c_strings_and_arrays)

set(CMAKE_CXX_STANDARD 11)

add_executable(main main.cpp c_strings.cpp c_strings.h)