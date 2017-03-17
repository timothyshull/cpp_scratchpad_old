cmake_minimum_required(VERSION 3.6)

set(CMAKE_CXX_STANDARD 11)

add_executable(cpp_file_read cpp_file_read.h cpp_file_read.cpp)
add_executable(test_file_read test_file_read.cpp Timer.h)
