#ifndef FILESTAT_H
#define FILESTAT_H

#include <QString>
#include <QDateTime>

class FileStat
{
public:
    FileStat();
    QString fileName;
    QDateTime createTime;
    QDateTime updateTime;
    QByteArray hash;
    QString fileUrl;
    int errorCode;
};

#endif // FILESTAT_H
