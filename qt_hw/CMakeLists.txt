cmake_minimum_required(VERSION 3.3)
project(qt_hw)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(qt_hw ${SOURCE_FILES})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

find_package(Qt5Core REQUIRED)
find_package(Qt5WebSockets REQUIRED)

set(SOURCE_FILES main.cpp echoserver.pro echoserver.h echoserver.cpp)
add_executable(echoserver ${SOURCE_FILES})

# Use the Widgets module from Qt 5.
target_link_libraries(echoserver Qt5::Core)
target_link_libraries(echoserver Qt5::WebSockets)