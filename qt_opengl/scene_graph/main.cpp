#include "squircle.h"

#include <QGuiApplication>
#include <QtQuick/QQuickView>

int main(int argc, char **argv) {
    QGuiApplication app(argc, argv);

    qmlRegisterType<Squircle>("OpenGLUnderQML", 1, 0, "Squircle");

    QQuickView view;
    view.setResizeMode(QQuickView::SizeRootObjectToView);
    view.setSource(QUrl("/Users/skull/Programming/Cpp/qt_opengl/scene_graph/main.qml"));
    view.show();

    return app.exec();
}