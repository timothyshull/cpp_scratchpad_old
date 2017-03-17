cmake_minimum_required(VERSION 3.3)
project(boost_asio)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(chat_server chat_server.cpp chat_message.h)
add_executable(chat_client chat_client.cpp chat_message.h)