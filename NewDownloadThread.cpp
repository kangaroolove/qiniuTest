#include "NewDownloadThread.h"

NewDownloadThread::NewDownloadThread(QObject *parent) : QObject(parent)
{

}

void NewDownloadThread::onDownloadStart(QList<FileStat> *downloadFileList)
{
    for (int i = 0; i < downloadFileList->size(); ++i)
    {

    }
}

