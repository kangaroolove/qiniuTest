#include "NewDownloadThread.h"
#include "DownloadTask.h"
#include <QThreadPool>

NewDownloadThread::NewDownloadThread(QObject *parent) : QObject(parent)
{
    m_count = 0;
    m_failCount = 0;
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
    m_failCount = 0;
    m_total = downloadFileList->size();

    QThreadPool threadPool;
    threadPool.setMaxThreadCount(10);
    for (int i = 0; i < downloadFileList->size(); ++i)
    {
        DownloadTask *task = new DownloadTask(downloadFileList->at(i));
        connect(task, SIGNAL(downloadFileSuccessfully()), this, SLOT(onDownloadFileSucceessfully()), Qt::DirectConnection);
        connect(task, SIGNAL(downloadFileFailed(FileStat &)), this, SLOT(onDownloadFileFailed(FileStat &)));
        threadPool.start(task);
    }
}

void NewDownloadThread::onDownloadFileSucceessfully()
{
    qDebug()<<"download successfully";
    emit refreshProgressBar();
    ++m_count;
    if (m_count == m_total)
    {
        if (m_failCount > 0)
        {
            emit downloadFileFailed(m_downloadFailedList);
        }
        else
        {
            emit downloadAllFileSuccessfully();
        }
    }
}

void NewDownloadThread::onDownloadFileFailed(FileStat &fileStat)
{
    emit refreshProgressBar();
    ++m_count;
    ++m_failCount;
    m_downloadFailedList->push_back(fileStat);
    if (m_count == m_total)
    {
        emit downloadFileFailed(m_downloadFailedList);
    }
}

