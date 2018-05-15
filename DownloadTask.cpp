#include "DownloadTask.h"
#include <QFile>
#include <sys/utime.h>
#include <time.h>

DownloadTask::DownloadTask(FileStat fileStat, QObject *parent) : QObject(parent)
{
    m_fileStat = fileStat;
}

void DownloadTask::run()
{
    bool result = m_request.downloadFile(m_fileStat.fileUrl, m_fileStat.filePath);
    if (result == true)
    {
        QFile srcFile(m_fileStat.filePath);
        if (srcFile.exists())
        {
            srcFile.remove();
        }
        QFile::rename(m_fileStat.filePath + TEMP_FILE_SUFFIX, m_fileStat.filePath);
        //modifyDownloadFileTime(m_fileStat);
        emit downloadFileSuccessfully();
    }
    else
    {
        emit downloadFileFailed(m_fileStat);
    }
}

void DownloadTask::modifyDownloadFileTime(const FileStat &fileStat)
{
    int year = fileStat.updateTime.date().year();
    int month = fileStat.updateTime.date().month();
    int day = fileStat.updateTime.date().day();
    int hour = fileStat.updateTime.time().hour();
    int minute = fileStat.updateTime.time().minute();
    int second = fileStat.updateTime.time().second();

    qDebug()<<year<<month<<day<<hour<<minute<<second;

    struct tm tma = {0}, tmm = {0};
//    time.tm_year = year;
//    time.tm_mon = month;
//    time.tm_mday = day;
//    time.tm_hour = hour;
//    time.tm_min = minute;
//    time.tm_sec = second;
//    time.tm_isdst = 0;

    tma.tm_hour = hour;
    tma.tm_isdst = 0;
    tma.tm_mday = day;
    tma.tm_min = minute;
    tma.tm_mon = month - 1;
    tma.tm_sec = second;
    tma.tm_year = year - 1900;

    tmm.tm_hour = 12;
    tmm.tm_isdst = 0;
    tmm.tm_mday = 15;
    tmm.tm_min = 0;
    tmm.tm_mon = 0;
    tmm.tm_sec = 0;
    tmm.tm_year = 102;

    struct _utimbuf ut;
    ut.modtime = mktime(&tma);
    ut.actime = mktime(&tmm);
    QByteArray charFileName = fileStat.filePath.toLatin1();
    char *fileName = charFileName.data();
    qDebug()<<charFileName<<fileName;
    if (_utime(fileName, &ut) == -1)
    {
        qDebug()<<"modify time failed";
    }
    else
    {
        qDebug()<<"modify time successfully";
    }
}

