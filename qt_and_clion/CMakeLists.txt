cmake_minimum_required(VERSION 2.8.11)
project(qt_and_clion)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

set(QT_PATH "/usr/local/opt/qt5")

set(QT_LIB_DIR ${QT_PATH}/lib/cmake)
set(Qt5Core_DIR "${QT_LIB_DIR}/Qt5Core")
set(Qt5Widgets_DIR "${QT_LIB_DIR}/Qt5Widgets")
set(Qt5Gui_DIR "${QT_LIB_DIR}/Qt5Widgets")

set(QT_LIBRARIES Qt5::Core Qt5::Widgets Qt5::Gui)
set(QT_LIBRARIES_REQUIRED Qt5Core Qt5Widgets Qt5Gui)

foreach (QT_LIBRARIES_REQUIRED ${QT_LIBRARIES_REQUIRED})
    find_package(${QT_LIBRARIES_REQUIRED} REQUIRED)
endforeach ()

# add_custom_target(qtMakefile COMMAND make -C ${QT_BIN})
# include_directories(${QT_BIN})

set(SOURCE_FILES main.cpp mainwindow.cpp mainwindow.h mainwindow.ui)
add_executable(qt_and_clion ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} ${QT_LIBRARIES})