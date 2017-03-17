#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QList>
#include <QStringList>
#include <QMainWindow>

#include "torrentclient.h"

class QAction;

class QCloseEvent;

class QLabel;

class QProgressDialog;

class QSlider;

class TorrentView;

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);

    QSize sizeHint() const Q_DECL_OVERRIDE;

    const TorrentClient *clientForRow(int row) const;

protected:
    void closeEvent(QCloseEvent *event) Q_DECL_OVERRIDE;

private slots:

    void loadSettings();

    void saveSettings();

    bool addTorrent();

    void removeTorrent();

    void pauseTorrent();

    void moveTorrentUp();

    void moveTorrentDown();

    void torrentStopped();

    void torrentError(TorrentClient::Error error);

    void updateState(TorrentClient::State state);

    void updatePeerInfo();

    void updateProgress(int percent);

    void updateDownloadRate(int bytesPerSecond);

    void updateUploadRate(int bytesPerSecond);

    void setUploadLimit(int bytes);

    void setDownloadLimit(int bytes);

    void about();

    void setActionsEnabled();

    void acceptFileDrop(const QString &fileName);

private:
    int rowOfClient(TorrentClient *client) const;

    bool addTorrent(const QString &fileName, const QString &destinationFolder,
                    const QByteArray &resumeState = QByteArray());

    TorrentView *torrentView;
    QAction *pauseTorrentAction;
    QAction *removeTorrentAction;
    QAction *upActionTool;
    QAction *downActionTool;
    QSlider *uploadLimitSlider;
    QSlider *downloadLimitSlider;
    QLabel *uploadLimitLabel;
    QLabel *downloadLimitLabel;

    int uploadLimit;
    int downloadLimit;

    struct Job {
        TorrentClient *client;
        QString torrentFileName;
        QString destinationDirectory;
    };
    QList<Job> jobs;
    int jobsStopped;
    int jobsToStop;

    QString lastDirectory;
    QProgressDialog *quitDialog;

    bool saveChanges;
};

#endif