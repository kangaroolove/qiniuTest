#include "DownloadTask.h"
#include <QFile>

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
    }
}

