cmake_minimum_required(VERSION 3.6)
project(smart_pointers)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

add_executable(shared_ptr shared_ptr.cpp)
add_executable(weak_ptr weak_ptr.cpp)
add_executable(unique_ptr unique_ptr.cpp)

add_executable(test_shared_ptr test_shared_ptr.cpp)
add_executable(test_weak_ptr test_weak_ptr.cpp)
add_executable(test_unique_ptr test_unique_ptr.cpp)