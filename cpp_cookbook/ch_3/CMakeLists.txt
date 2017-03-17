cmake_minimum_required(VERSION 3.3)
project(cpp_cookbook)

find_package(Boost)
if (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIR})
endif ()

#set(CMAKE_GENERATOR "Unix Makefiles")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")