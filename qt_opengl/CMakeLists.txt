cmake_minimum_required(VERSION 3.6)
project(qt_opengl)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(CMAKE_PREFIX_PATH /usr/local/Cellar/qt5/5.6.1-1)

add_subdirectory(bogo)
add_subdirectory(scene_graph)
