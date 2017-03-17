cmake_minimum_required(VERSION 3.3)
project(boost_asio)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_subdirectory(allocation)
add_subdirectory(buffers)
add_subdirectory(chat)
add_subdirectory(echo)
add_subdirectory(futures)
add_subdirectory(http)
add_subdirectory(spawn)
