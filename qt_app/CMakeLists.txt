cmake_minimum_required(VERSION 3.3)
project(qt_app)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)


#list(APPEND CMAKE_MODULE_PATH "/usr/local/opt/qt5/lib/cmake")
# Find the QtWidgets library
#find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
#find_package(Qt5Gui REQUIRED)


set(SOURCE_FILES application/main.cpp application/mainwindow.cpp application/mainwindow.h application/application.pro application/application.qrc)
add_executable(qt_app ${SOURCE_FILES})

#qt5_use_modules(qt_app Core Widgets Gui)

# Use the Widgets module from Qt 5.
target_link_libraries(qt_app Qt5::Widgets)
#target_link_libraries(qt_app Qt5::Core)
#target_link_libraries(qt_app Qt5::Gui)



