#ifndef FILESTAT_H
#define FILESTAT_H

#include <QString>
#include <QDateTime>

class FileStat
{
public:
    FileStat();
    QString fileName;
    QString fileId;
    QDateTime createTime;
    QDateTime updateTime;
    QByteArray hash;
    QString fileUrl;
};

#endif // FILESTAT_H
