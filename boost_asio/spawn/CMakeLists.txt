cmake_minimum_required(VERSION 3.3)
project(boost_asio)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(echo_server echo_server.cpp)