#ifndef AUDIODEVICES_H
#define AUDIODEVICES_H

#include <QAudioDeviceInfo>
#include <QMainWindow>
#include <QObject>

#include "ui_audiodevicesbase.h"

class AudioDevicesBase : public QMainWindow, public Ui::AudioDevicesBase {
public:
    AudioDevicesBase(QWidget *parent = 0);

    virtual ~AudioDevicesBase();
};

class AudioTest : public AudioDevicesBase {
Q_OBJECT

public:
    AudioTest(QWidget *parent = 0);

    virtual ~AudioTest();

    QAudioDeviceInfo deviceInfo;
    QAudioFormat settings;
    QAudio::Mode mode;

private slots:

    void modeChanged(int idx);

    void deviceChanged(int idx);

    void sampleRateChanged(int idx);

    void channelChanged(int idx);

    void codecChanged(int idx);

    void sampleSizeChanged(int idx);

    void sampleTypeChanged(int idx);

    void endianChanged(int idx);

    void test();

    void populateTable();

};

#endif