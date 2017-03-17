cmake_minimum_required(VERSION 3.6)
project(subprocess)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(Boost)
include_directories(BOOST_INCLUDE_DIR)
add_executable(subprocess main.cpp subprocess.cpp subprocess.h Preexec_fn.h)
add_executable(system system.cpp)
add_executable(fork fork.cpp)
add_executable(spawn spawn.cpp)