#ifndef NEWDATASNC_H
#define NEWDATASNC_H

#include "FileCompare.h"
#include "FileStat.h"
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
private:
    FileCompare *m_fileCompare;
    QList<FileStat> *m_localList;
    QList<FileStat>* getLocalFile(QString caseId, QString path, SyncOperateType type);
    QString getFileUrl(const QString &fileName, const QString& caseId, const QString &dir);
    QByteArray getMd5(const QString& fileName);
};

#endif // NEWDATASNC_H
