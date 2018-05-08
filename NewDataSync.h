#ifndef NEWDATASNC_H
#define NEWDATASNC_H

#include "FileCompare.h"
#include "FileStat.h"
#include "NewRequest.h"
#include <QObject>

#define MD5_READ_MAX_SIZE   4096

enum SyncOperateType
{
    NO = 0,
    UPLOAD,
    DOWNLOAD,
};

class FileCompare;
class NewDataSync
{
public:
    NewDataSync();
    ~NewDataSync();
    void setOperateType(SyncOperateType type);
    void start();
private:
    SyncOperateType m_operateType;
    FileCompare *m_fileCompare;
    QList<FileStat> *m_localList;
    QList<FileStat> *m_remoteList;
    NewRequest m_request;
    QList<FileStat>* getLocalFile(QString caseId, const QString& path, SyncOperateType type);
    QList<FileStat>* getRemoteFile(QString caseId);
    QString getFileUrl(const QString &fileName, const QString& caseId, const QString &dir);
    QByteArray getMd5(const QString& fileName);
    QString getFileId(const QString& caseId, const QString& fileName);
    QString getUuid();
};

#endif // NEWDATASNC_H
