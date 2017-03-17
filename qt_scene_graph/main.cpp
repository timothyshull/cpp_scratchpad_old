//#include <QGuiApplication>
//#include <QtQuick/QQuickView>
//
//
//int main(int argc, char **argv)
//{
//    QGuiApplication app(argc, argv);
//
//    qmlRegisterType<Squircle>("OpenGLUnderQML", 1, 0, "Squircle");
//
//    QQuickView view;
//    view.setResizeMode(QQuickView::SizeRootObjectToView);
//    // view.setSource(QUrl(QStringLiteral("qrc:/main.qml")));
//    // view.setSource(QUrl("qrc:/main.qml"));
//    view.setSource(QUrl("../main.qml"));
//    view.show();
//
//    return app.exec();
//}

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "squircle.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<Squircle>("OpenGLUnderQML", 1, 0, "Squircle");

    QQmlApplicationEngine engine;
    engine.load(QUrl("qrc:/main.qml"));

    return app.exec();
}
