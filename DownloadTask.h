#ifndef DOWNLOADTASK_H
#define DOWNLOADTASK_H

#include "FileStat.h"
#include "NewRequest.h"
#include <QObject>
#include <QRunnable>

class DownloadTask : public QObject , public QRunnable
{
    Q_OBJECT
public:
    explicit DownloadTask(FileStat fileStat, QObject *parent = 0);
    void run();
signals:
    void downloadFileSuccessfully();
    void downloadAllFileSuccessfully();
    void downloadFileFailed(FileStat &fileStat);
    void refreshProgressBar();
public slots:

private:
    FileStat m_fileStat;
    NewRequest m_request;
    void modifyDownloadFileTime(const FileStat &fileStat);
};

#endif // DOWNLOADTASK_H
