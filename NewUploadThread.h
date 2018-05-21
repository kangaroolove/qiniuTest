#ifndef NEWUPLOADTHREAD_H
#define NEWUPLOADTHREAD_H

#include "FileStat.h"
#include "NewRequest.h"
#include "Json.h"
#include <QObject>

class NewUploadThread : public QObject
{
    Q_OBJECT
public:
    explicit NewUploadThread(QObject *parent = 0);
    void setCaseId(const QString &caseId);
signals:
    void refreshProgressBar();
    void uploadFinished(QList<FileStat> *uploadFailedList);
public slots:
    void onUploadStart(QList<FileStat> *uploadFileList, QString token);
private:
    QString m_caseId;
    QList<FileStat> *m_uploadFailedList;
    NewRequest m_request;
    Json m_json;
};

#endif // NEWUPLOADTHREAD_H
