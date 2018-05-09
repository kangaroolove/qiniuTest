#ifndef NEWUPLOADTHREAD_H
#define NEWUPLOADTHREAD_H

#include "FileStat.h"
#include <QObject>

class NewUploadThread : public QObject
{
    Q_OBJECT
public:
    explicit NewUploadThread(QObject *parent = 0);

signals:
    void uploadFileSuccessfully();
    void uploadAllFileSuccessfully();
    void uploadFileFailed(QList<FileStat> *uploadFailedList);
    void refreshProgressBar();
public slots:
    void onUploadStart(QList<FileStat> *uploadFileList, QString &token);
private:
    QList<FileStat> *m_uploadFailedList;
};

#endif // NEWUPLOADTHREAD_H
