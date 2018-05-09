#ifndef NEWDATASNC_H
#define NEWDATASNC_H

#include "FileCompare.h"
#include "FileStat.h"
#include "NewRequest.h"
#include "NewUploadThread.h"
#include "NewDownloadThread.h"
#include <QObject>
#include <QThread>

#define MD5_READ_MAX_SIZE   4096

enum SyncOperateType
{
    NO = 0,
    UPLOAD,
    DOWNLOAD,
};

class FileCompare;
class NewDataSync : public QObject
{
    Q_OBJECT
public:
    NewDataSync();
    ~NewDataSync();
    void setOperateType(SyncOperateType type);
    void start();
signals:
    void startUpload(QList<FileStat> *uploadFileList, QString &token);
    void startDownload(QList<FileStat> *uploadFileList, QString &token);

    void uploadFileSuccessfully();
    void uploadAllFileSuccessfully();
    void uploadFileFailed(QList<FileStat> *uploadFailedList);

    void downloadFileSuccessfully();
    void downloadAllFileSuccessfully();
    void downloadFileFailed(QList<FileStat> *uploadFailedList);
    void refreshProgressBar();
private:
    SyncOperateType m_operateType;
    FileCompare *m_fileCompare;
    QList<FileStat> *m_localList;
    QList<FileStat> *m_remoteList;
    NewRequest m_request;
    QThread m_uploadThread;
    QThread m_downloadThread;
    NewUploadThread *m_upload;
    NewDownloadThread *m_download;
    QList<FileStat>* getLocalFile(QString caseId, const QString& path, SyncOperateType type);
    QList<FileStat>* getRemoteFile(QString caseId);
    QString getFileUrl(const QString &fileName, const QString& caseId, const QString &dir);
    QByteArray getMd5(const QString& fileName);
    QString getUuid();
};

#endif // NEWDATASNC_H
