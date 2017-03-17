#include <QApplication>
#include <QtCore>

#include "mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));

    Q_INIT_RESOURCE(icons);

    MainWindow window;
    window.show();

    return app.exec();
}