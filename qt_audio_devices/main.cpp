#include <QtWidgets>

#include "audiodevices.h"

int main(int argv, char **args) {
    QApplication app(argv, args);
    app.setApplicationName("Audio Device Test");

    AudioTest audio;
    audio.show();

    return app.exec();
}