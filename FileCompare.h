#ifndef FILECOMPARE_H
#define FILECOMPARE_H

#include "NewDataSnc.h"
#include "FileStat.h"

class FileCompare
{
public:
    FileCompare();
    QList<FileStat>* getLocalFile(QString caseId, QString dirString, SyncOperateType type);
    QList<FileStat>* makeFileCompare(SyncOperateType type, QList<FileStat>* local, QList<FileStat>* remote);
};

#endif // FILECOMPARE_H
