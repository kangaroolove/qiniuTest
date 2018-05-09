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
    void downloadFileFailed(QList<FileStat> *uploadFailedList);
    void refreshProgressBar();
public slots:
    void onDownloadStart(QList<FileStat> *uploadFileList, QString &token);
private:
    QList<FileStat> *m_downloadFailedList;
};

#endif // NEWDOWNLOADTHREAD_H
