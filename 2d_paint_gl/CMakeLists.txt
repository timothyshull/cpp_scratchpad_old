cmake_minimum_required(VERSION 3.3)
project(2d_paint_gl)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)

set(SOURCE_FILES
        2dpainting.pro
        glwidget.cpp
        glwidget.h
        helper.cpp
        helper.h
        main.cpp
        widget.cpp
        widget.h
        window.cpp
        window.h)

add_executable(2d_paint_gl ${SOURCE_FILES})

# Use the Widgets module from Qt 5.
target_link_libraries(2d_paint_gl Qt5::Core)
target_link_libraries(2d_paint_gl Qt5::Widgets)