#include "NewDownloadThread.h"
#include "DownloadTask.h"
#include <QThreadPool>

NewDownloadThread::NewDownloadThread(QObject *parent) : QObject(parent)
{
    m_count = 0;
    m_total = 0;
    m_downloadFailedList = NULL;
}

void NewDownloadThread::onDownloadStart(QList<FileStat> *downloadFileList)
{
    if (m_downloadFailedList)
    {
        m_downloadFailedList->clear();
        delete m_downloadFailedList;
        m_downloadFailedList = NULL;
    }

    m_downloadFailedList = new QList<FileStat>;
    m_total = downloadFileList->size();
    m_count = 0;

    QThreadPool threadPool;
    threadPool.setMaxThreadCount(10);
    for (int i = 0; i < downloadFileList->size(); ++i)
    {
        DownloadTask *task = new DownloadTask(downloadFileList->at(i));
        connect(task, SIGNAL(downloadFinished(bool,FileStat*)), this, SLOT(onDownloadFinished(bool,FileStat*)), Qt::DirectConnection);
        threadPool.start(task);
    }
}

void NewDownloadThread::onDownloadFinished(bool successful, FileStat *fileStat)
{
    emit refreshProgressBar();
    ++m_count;

    if (successful == false)
    {
        m_downloadFailedList->push_back(*fileStat);
    }

    if (m_count == m_total)
    {
        emit downloadFinished(m_downloadFailedList);
    }
}

