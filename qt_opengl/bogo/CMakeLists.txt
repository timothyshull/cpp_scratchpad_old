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

qt5_wrap_ui(ui_window.h window.ui)

# Tell CMake to create the helloworld executable (main.qml openglunderqml.pro openglunderqml.qrc arent' necessary)
add_executable(bogo main.cpp main.moc myglwidget.cpp myglwidget.h window.h window.cpp ui_window.h)

#Link the executable to the Qt 5 widgets library.
target_link_libraries(bogo Qt5::Widgets Qt5::OpenGL Qt5::OpenGLExtensions Qt5::Quick Qt5::Qml ${OPENGL_LIBRARIES})