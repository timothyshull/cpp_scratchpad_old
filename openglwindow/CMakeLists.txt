cmake_minimum_required(VERSION 3.6)
project(openglwindow)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(QT_PATH "/usr/local/opt/qt5")

set(QT_LIB_DIR ${QT_PATH}/lib/cmake)

set(Qt5Core_DIR "${QT_LIB_DIR}/Qt5Core")
set(Qt5Widgets_DIR "${QT_LIB_DIR}/Qt5Widgets")
set(Qt5Gui_DIR "${QT_LIB_DIR}/Qt5Widgets")
set(Qt5Quick_DIR "${QT_LIB_DIR}/Qt5Quick")
set(Qt5Qml_DIR "${QT_LIB_DIR}/Qt5Qml")
set(Qt5OpenGL_DIR "${QT_LIB_DIR}/Qt5OpenGL")

set(QT_LIBRARIES
        Qt5::Core
        Qt5::Widgets
        Qt5::Gui
        Qt5::Quick
        Qt5::Qml
        Qt5::OpenGL)

set(QT_LIBRARIES_REQUIRED
        Qt5Core
        Qt5Widgets
        Qt5Gui
        Qt5Quick
        Qt5Qml
        Qt5OpenGL)

foreach (QT_LIBRARIES_REQUIRED ${QT_LIBRARIES_REQUIRED})
    find_package(${QT_LIBRARIES_REQUIRED} REQUIRED)
endforeach ()

set(SOURCE_FILES main.cpp openglwindow.h openglwindow.cpp)
add_executable(openglwindow ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} ${QT_LIBRARIES})
