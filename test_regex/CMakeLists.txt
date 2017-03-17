cmake_minimum_required(VERSION 3.6)
project(test_regex)

set(CMAKE_CXX_STANDARD 11)

add_executable(regex1 regex1.cpp)
add_executable(regex2 regex2.cpp)
add_executable(regex3 regex3.cpp)
add_executable(regex_iter1 regex_iter1.cpp)
add_executable(regex_token_iter1 regex_token_iter1.cpp)
add_executable(regex_replace1 regex_replace1.cpp)
add_executable(regex4 regex4.cpp)
add_executable(regex5 regex5.cpp)