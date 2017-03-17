#-------------------------------------------------
#
# Project created by QtCreator 2017-01-22T16:05:34
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = openglwindow
TEMPLATE = app

include(openglwindow.pri)

SOURCES += main.cpp

# HEADERS  += openglwindow.h

# FORMS    += openglwindow.ui

target.path = $$[QT_INSTALL_EXAMPLES]/gui/openglwindow
INSTALLS += target