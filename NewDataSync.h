#ifndef NEWDATASNC_H
#define NEWDATASNC_H

#include "FileCompare.h"
#include "FileStat.h"
#include <QObject>

class FileCompare;
class NewDataSync
{
public:
    NewDataSync();
    ~NewDataSync();
private:
    FileCompare *m_fileCompare;
    QList<FileStat> *m_localList;
};

#endif // NEWDATASNC_H
