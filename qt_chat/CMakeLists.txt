cmake_minimum_required(VERSION 3.3)
project(qt_chat)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

find_package(Qt5Core REQUIRED)
find_package(Qt5WebSockets REQUIRED)
#find_package(Qt5Debug REQUIRED)


set(SOURCE_FILES chatserver.cpp chatserver.h main.cpp simplechat.pro)
add_executable(qt_chat ${SOURCE_FILES})

#qt5_use_modules(qt_app Core Widgets Gui)

# Use the Widgets module from Qt 5.
target_link_libraries(qt_chat Qt5::Core)
target_link_libraries(qt_chat Qt5::WebSockets)
#target_link_libraries(qt_app Qt5::Debug)