cmake_minimum_required(VERSION 3.6)
project(libuv_tests)

set(CMAKE_CXX_STANDARD 11)

add_executable(libuv_tests main.cpp Promise.h utility.h tmp.h)