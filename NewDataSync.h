#ifndef NEWDATASNC_H
#define NEWDATASNC_H

#include "FileCompare.h"
#include "FileStat.h"
#include "NewRequest.h"
#include "NewUploadThread.h"
#include "NewDownloadThread.h"
#include <QObject>
#include <QThread>
#include <QFileInfo>

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
    void start(const QString &caseId, const QString &path);
signals:
    void startUpload(QList<FileStat> *uploadFileList, QString token);
    void startDownload(QList<FileStat> *downloadFileList);

    void uploadFinished(QList<FileStat> *uploadFailedList);

    void downloadFileSuccessfully();
    void downloadAllFileSuccessfully();
    void downloadFileFailed(QList<FileStat> *uploadFailedList);
    void refreshProgressBar();
    void setProgressBarMaxValue(int, SyncOperateType type);
    void sendUploadLatest();
    void sendDownloadLatest();
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
    QStringList m_suffixType;
    QList<FileStat>* getLocalFile(const QString &caseId, const QString& path, const SyncOperateType &type, const QStringList &suffix);
    QList<FileStat>* getRemoteFile(const QString &caseId, const QString &path);
    QString getFilePath(const QString &webName, const int &fileType, const QString &path, const QString &caseId);
    QString getFileUrl(const QString &fileName, const QString& caseId, const QString &dir);
    QByteArray getMd5(const QString& fileName);
    QString getUuid();
    FileType getFileType(const QFileInfo &fileInfo);
    QList<FileStat>* initFile(QList<FileStat> *list, const QString &path, const QString &caseId);
    QString getFileName(const QString &webName, const int &fileType);
};

#endif // NEWDATASNC_H
