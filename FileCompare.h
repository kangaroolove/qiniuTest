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

};

#endif // FILECOMPARE_H
