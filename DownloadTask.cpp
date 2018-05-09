#include "DownloadTask.h"

DownloadTask::DownloadTask(FileStat fileStat, QObject *parent) : QObject(parent)
{
    m_fileStat = fileStat;
}

void DownloadTask::run()
{

}

