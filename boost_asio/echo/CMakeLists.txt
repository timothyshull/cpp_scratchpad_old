cmake_minimum_required(VERSION 3.3)
project(boost_asio)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(async_tcp_echo_server async_tcp_echo_server.cpp)
add_executable(async_udp_echo_server async_udp_echo_server.cpp)
add_executable(blocking_tcp_echo_client blocking_tcp_echo_client.cpp)
add_executable(blocking_tcp_echo_server blocking_tcp_echo_server.cpp)
add_executable(blocking_udp_echo_client blocking_udp_echo_client.cpp)
add_executable(blocking_udp_echo_server blocking_udp_echo_server.cpp)
