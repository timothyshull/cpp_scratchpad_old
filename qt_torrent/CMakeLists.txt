cmake_minimum_required(VERSION 3.6)
project(qt_torrent)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(CMAKE_PREFIX_PATH /usr/local/Cellar/qt5/5.6.1-1)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

# Find the QtWidgets library
find_package(Qt5Widgets)
find_package(Qt5OpenGL)
find_package(Qt5OpenGLExtensions)
find_package(Qt5Quick)
find_package(Qt5Qml)
find_package(OpenGL)

#message(WARNING "OPENGL_INCLUDE_DIR: " ${OPENGL_INCLUDE_DIR})
#message(WARNING "OPENGL_LIBRARIES: " )

# Add the include directories for the Qt 5 Widgets module to the compile lines.
include_directories(${Qt5Widgets_INCLUDE_DIRS}
        ${Qt5OpenGL_INCLUDE_DIRS}
        ${Qt5OpenGLExtensions_INCLUDE_DIRS}
        ${Qt5Quick_INCLUDE_DIRS}
        ${Qt5Qml_INCLUDE_DIRS}
        ${OPENGL_INCLUDE_DIR})

# Use the compile definitions defined in the Qt 5 Widgets module
add_definitions(${Qt5Widgets_DEFINITIONS}
        ${Qt5OpenGL_DEFINITIONS}
        ${Qt5OpenGLExtensions_DEFINITIONS}
        ${Qt5Quick_DEFINITIONS}
        ${Qt5Qml_DEFINITIONS})

# Add compiler flags for building executables (-fPIE)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")

qt5_generate_moc(main.cpp main.moc)

qt5_wrap_ui(forms/addtorrentform.ui)

set(SOURCE_FILES main.cpp
        forms/addtorrentform.ui
        addtorrentdialog.cpp
        addtorrentdialog.h
        bencodeparser.cpp
        bencodeparser.h
        CMakeLists.txt
        connectionmanager.cpp
        connectionmanager.h
        filemanager.cpp
        filemanager.h
        icons.qrc
        main.cpp
        mainwindow.cpp
        mainwindow.h
        metainfo.cpp
        metainfo.h
        peerwireclient.cpp
        peerwireclient.h
        ratecontroller.cpp
        ratecontroller.h
        torrent.pro
        torrentclient.cpp
        torrentclient.h
        torrentserver.cpp
        torrentserver.h
        trackerclient.cpp
        trackerclient.h)

add_executable(qt_torrent ${SOURCE_FILES})

#Link the executable to the Qt 5 widgets library.
target_link_libraries(qt_torrent Qt5::Widgets Qt5::OpenGL Qt5::OpenGLExtensions Qt5::Quick Qt5::Qml ${OPENGL_LIBRARIES})