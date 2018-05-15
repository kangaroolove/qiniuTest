#ifndef NEWDOWNLOADTHREAD_H
#define NEWDOWNLOADTHREAD_H

#include "FileStat.h"
#include <QObject>

class NewDownloadThread : public QObject
{
    Q_OBJECT
public:
    explicit NewDownloadThread(QObject *parent = 0);

signals:
    void downloadFileSuccessfully();
    void downloadAllFileSuccessfully();
    void downloadFileFailed(QList<FileStat> *downloadFailedList);
    void refreshProgressBar();
public slots:
    void onDownloadStart(QList<FileStat> *downloadFileList);
    void onDownloadFileSucceessfully();
    void onDownloadFileFailed(FileStat &fileStat);
private:
    QList<FileStat> *m_downloadFailedList;
    int m_count;
    int m_failCount;
    int m_total;
};

#endif // NEWDOWNLOADTHREAD_H
