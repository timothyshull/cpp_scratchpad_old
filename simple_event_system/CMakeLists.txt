cmake_minimum_required(VERSION 3.6)
project(simple_event_system)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp observers.h observer.h subject.h details.h)
add_executable(simple_event_system ${SOURCE_FILES})