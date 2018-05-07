#ifndef FILECOMPARE_H
#define FILECOMPARE_H

#include "NewDataSync.h"
#include "FileStat.h"

enum SyncOperateType
{
    NO = 0,
    UPLOAD,
    DOWNLOAD,
};

class FileCompare
{
public:
    FileCompare();
    QList<FileStat>* getLocalFile(QString caseId, QString path, SyncOperateType type);
    QList<FileStat>* makeFileCompare(SyncOperateType type, QList<FileStat>* local, QList<FileStat>* remote);
private:
    QString getFileUrl(const QString &fileName, const QString& caseId, const QString &dir);
};

#endif // FILECOMPARE_H
