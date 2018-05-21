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
    void downloadFinished(QList<FileStat> *downloadFailedList);
    void refreshProgressBar();
public slots:
    void onDownloadFinished(bool successful, FileStat *fileStat);
    void onDownloadStart(QList<FileStat> *downloadFileList);
private:
    QList<FileStat> *m_downloadFailedList;
    int m_count;
    int m_total;
};

#endif // NEWDOWNLOADTHREAD_H
