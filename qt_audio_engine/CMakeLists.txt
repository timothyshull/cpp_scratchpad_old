cmake_minimum_required(VERSION 3.6)
project(qt_audio_engine)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(CMAKE_PREFIX_PATH /usr/local/Cellar/qt5/5.6.1-1)

# Find includes in corresponding build directories
#set(CMAKE_INCLUDE_CURRENT_DIR ON)
#set(CMAKE_AUTOMOC ON)

find_package(Qt5 COMPONENTS Quick Core Network)
find_package(Qt5QuickCompiler)
qtquick_compiler_add_resources(RESOURCES )
add_executable(qt_audio_engine ${SRC_LIST} ${RESOURCES)
qt5_use_modules(qt_audio_engine Quick Core Network)
