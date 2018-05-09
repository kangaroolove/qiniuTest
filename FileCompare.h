#ifndef FILECOMPARE_H
#define FILECOMPARE_H

#include "NewDataSync.h"
#include "FileStat.h"

enum SyncOperateType;
class FileCompare
{
public:
    FileCompare();
    QList<FileStat>* makeFileCompare(SyncOperateType type, QList<FileStat>* local, QList<FileStat>* remote);
private:
    QList<FileStat>* getUploadList(QList<FileStat>* local, QList<FileStat>* remote);
    QList<FileStat>* getDownloadList(QList<FileStat>* local, QList<FileStat>* remote);
};

#endif // FILECOMPARE_H
