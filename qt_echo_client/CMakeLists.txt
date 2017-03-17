cmake_minimum_required(VERSION 3.3)
project(echoclient)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

find_package(Qt5Core REQUIRED)
find_package(Qt5WebSockets REQUIRED)

set(SOURCE_FILES main.cpp echoclient.pro echoclient.h echoclient.cpp)
add_executable(echoclient ${SOURCE_FILES})

# Use the Widgets module from Qt 5.
target_link_libraries(echoclient Qt5::Core)
target_link_libraries(echoclient Qt5::WebSockets)