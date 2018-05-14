#include "NewDownloadThread.h"
#include "DownloadTask.h"
#include <QThreadPool>

NewDownloadThread::NewDownloadThread(QObject *parent) : QObject(parent)
{

}

void NewDownloadThread::onDownloadStart(QList<FileStat> *downloadFileList)
{
    QThreadPool threadPool;
    threadPool.setMaxThreadCount(10);
    for (int i = 0; i < downloadFileList->size(); ++i)
    {
        DownloadTask *task = new DownloadTask(downloadFileList->at(i));
        threadPool.start(task);
    }
}

