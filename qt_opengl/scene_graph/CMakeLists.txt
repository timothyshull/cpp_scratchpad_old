# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

# Find the QtWidgets library
find_package(Qt5Widgets)
find_package(Qt5OpenGL)
find_package(Qt5Quick)
find_package(Qt5Qml)

# Add the include directories for the Qt 5 Widgets module to the compile lines.
include_directories(${Qt5Widgets_INCLUDE_DIRS}
        ${Qt5OpenGL_INCLUDE_DIRS}
        ${Qt5Quick_INCLUDE_DIRS}
        ${Qt5Qml_INCLUDE_DIRS})

# Use the compile definitions defined in the Qt 5 Widgets module
add_definitions(${Qt5Widgets_DEFINITIONS}
        ${Qt5OpenGL_DEFINITIONS}
        ${Qt5Quick_DEFINITIONS}
        ${Qt5Qml_DEFINITIONS})

# Add compiler flags for building executables (-fPIE)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")

qt5_generate_moc(main.cpp main.moc)

# Tell CMake to create the helloworld executable (main.qml openglunderqml.pro openglunderqml.qrc arent' necessary)
add_executable(scene_graph main.cpp main.moc squircle.h squircle.cpp main.qml openglunderqml.pro openglunderqml.qrc)

#Link the executable to the Qt 5 widgets library.
target_link_libraries(scene_graph Qt5::Widgets Qt5::OpenGL Qt5::Quick Qt5::Qml)