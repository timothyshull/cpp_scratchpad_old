#include <QtCore/QCoreApplication>
#include <QtCore/QCommandLineParser>
#include <iostream>
#include "echoserver.h"

int main(int argc, char* argv[]) {
    QCoreApplication a(argc, argv);

    QCommandLineParser parser;
    parser.setApplicationDescription("QtWebSockets example: echoserver");
    parser.addHelpOption();

    QCommandLineOption dbgOption(QStringList() << "d" << "debug",
                                 QCoreApplication::translate("main", "Debug output [default: off]."));
    parser.addOption(dbgOption);
    QCommandLineOption portOption(QStringList() << "p" << "port",
                                  QCoreApplication::translate("main", "Port for echoserver [default: 1234]."),
                                  QCoreApplication::translate("main", "port"), QLatin1Literal("1234"));
    parser.addOption(portOption);
    parser.process(a);
    bool debug = parser.isSet(dbgOption);
    int port = parser.value(portOption).toInt();

    EchoServer* server = new EchoServer(port, debug);
    std::cerr << "running server";
    QObject::connect(server, &EchoServer::closed, &a, &QCoreApplication::quit);

    return a.exec();
}