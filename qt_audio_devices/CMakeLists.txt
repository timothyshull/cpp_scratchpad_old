cmake_minimum_required(VERSION 3.6)
project(qt_audio_devices)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(CMAKE_PREFIX_PATH /usr/local/Cellar/qt5/5.6.1-1)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

# Find the QtWidgets library
find_package(Qt5Widgets)
find_package(Qt5Multimedia)

# Add the include directories for the Qt 5 Widgets module to the compile lines.
include_directories(${Qt5Widgets_INCLUDE_DIRS}
        ${Qt5Multimedia_INCLUDE_DIRS})

# Use the compile definitions defined in the Qt 5 Widgets module
add_definitions(${Qt5Widgets_DEFINITIONS}
        ${Qt5OpenGL_DEFINITIONS})

# Add compiler flags for building executables (-fPIE)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")

qt5_generate_moc(main.cpp main.moc)

qt5_wrap_ui(ui_audiodevicesbase.h audiodevicesbase.ui)

# Tell CMake to create the helloworld executable (main.qml openglunderqml.pro openglunderqml.qrc arent' necessary)
add_executable(qt_audio_devices main.cpp main.moc audiodevices.h audiodevices.cpp audiodevices.pro audiodevicesbase.ui)

#Link the executable to the Qt 5 widgets library.
target_link_libraries(qt_audio_devices Qt5::Widgets Qt5::Multimedia)