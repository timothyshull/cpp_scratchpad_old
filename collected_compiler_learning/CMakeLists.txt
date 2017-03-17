cmake_minimum_required(VERSION 3.5)
project(simple_lexer)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# see https://cmake.org/cmake/help/v3.5/module/FindBoost.html
find_package(Boost REQUIRED)

include_directories(${Boost_INCLUDE_DIR})

add_executable(simple_lexer main.cpp)
add_executable(llvm_toy llvm_toy.cpp)
add_executable(10_10 10-10.cpp)

#message(WARNING "Boost_INCLUDE_DIR: " ${Boost_INCLUDE_DIR})
#message(WARNING "Boost_LIBRARIES: " ${Boost_LIBRARIES})

target_link_libraries(10_10 "libboost_filesystem.a")
target_link_libraries(10_10 "libboost_system.a")
