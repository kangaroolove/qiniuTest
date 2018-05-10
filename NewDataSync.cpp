#include "NewDataSync.h"
#include <QFile>
#include <QCryptographicHash>
#include <QMessageBox>
#include <QDir>
#include <QDirIterator>
#include <QDebug>
#include <QUuid>

NewDataSync::NewDataSync()
{
    m_localList = NULL;
    m_remoteList = NULL;
    m_operateType = SyncOperateType::NO;

    m_suffixType.clear();
    m_suffixType<<QString("*.stl")<<QString("*.rtd")<<QString("*.rttsd")<<QString("*.srtd")<<QString("*.dat")<<QString("*.rtp");

    m_fileCompare = new FileCompare;

    m_upload = new NewUploadThread;
    m_upload->moveToThread(&m_uploadThread);
    connect(this, SIGNAL(startUpload(QList<FileStat>*,QString&)), m_upload, SLOT(onUploadStart(QList<FileStat>*,QString&)));
    connect(m_upload, SIGNAL(uploadFileSuccessfully()), this, SIGNAL(uploadFileSuccessfully()));
    connect(m_upload, SIGNAL(uploadAllFileSuccessfully()), this, SIGNAL(uploadAllFileSuccessfully()));
    connect(m_upload, SIGNAL(uploadFileFailed(QList<FileStat>*)), this, SIGNAL(uploadFileFailed(QList<FileStat>*)));
    connect(m_upload, SIGNAL(refreshProgressBar()), this, SIGNAL(refreshProgressBar()));
    m_uploadThread.start();

    m_download = new NewDownloadThread;
    m_download->moveToThread(&m_downloadThread);
    connect(this, SIGNAL(startDownload(QList<FileStat>*,QString&)), m_download, SLOT(onDownloadStart(QList<FileStat>*)));
    connect(m_download, SIGNAL(downloadFileSuccessfully()), this, SIGNAL(downloadFileSuccessfully()));
    connect(m_download, SIGNAL(downloadAllFileSuccessfully()), this, SIGNAL(downloadAllFileSuccessfully()));
    connect(m_download, SIGNAL(downloadFileFailed(QList<FileStat>*)), this, SIGNAL(downloadFileFailed(QList<FileStat>*)));
    connect(m_download, SIGNAL(refreshProgressBar()), this, SIGNAL(refreshProgressBar()));
    m_downloadThread.start();
}

NewDataSync::~NewDataSync()
{
    if (m_fileCompare)
    {
        delete m_fileCompare;
        m_fileCompare = NULL;
    }
    if (m_localList)
    {
        m_localList->clear();
        delete m_localList;
        m_localList = NULL;
    }
    if (m_remoteList)
    {
        m_remoteList->clear();
        delete m_remoteList;
        m_remoteList = NULL;
    }

    m_uploadThread.quit();
    m_uploadThread.wait();

    m_downloadThread.quit();
    m_downloadThread.wait();
}

void NewDataSync::setOperateType(SyncOperateType type)
{
    switch (type)
    {
        case SyncOperateType::UPLOAD:
        case SyncOperateType::DOWNLOAD:
        case SyncOperateType::NO:
            m_operateType = type;
            break;
        default:
            break;
    }
}

void NewDataSync::start(const QString &caseId, const QString &path)
{
    if (caseId.isEmpty() || path.isEmpty())
    {
        QMessageBox::warning(NULL,
                             "Warning",
                             "Please enter caseId and path",
                             QMessageBox::Ok,
                             QMessageBox::Ok);

        return;
    }

    if (m_localList)
    {
        m_localList->clear();
        delete m_localList;
        m_localList = NULL;
    }

    if (m_remoteList)
    {
        m_remoteList->clear();
        delete m_remoteList;
        m_remoteList = NULL;
    }

    m_localList = getLocalFile(caseId, path, m_operateType, m_suffixType);
    if (m_localList)
    {
        for (int i = 0; i < m_localList->size(); ++i)
        {
            qDebug()<<"fileName:"<<m_localList->at(i).fileName;
            qDebug()<<"createTime:"<<m_localList->at(i).createTime;
            qDebug()<<"updateTime:"<<m_localList->at(i).updateTime;
            qDebug()<<"fileUrl:"<<m_localList->at(i).fileUrl;
            qDebug()<<"hash:"<<m_localList->at(i).hash;
        }
    }

    //QString token = m_request.getToken();
    //qDebug()<<"token"<<token;
    m_remoteList = getRemoteFile(caseId);
    //QList<FileStat> *list = m_fileCompare->makeFileCompare(m_operateType, m_localList, m_remoteList);

//    if (m_operateType == SyncOperateType::UPLOAD)
//    {
//        emit startUpload(list, token);
//    }
//    else if (m_operateType == SyncOperateType::DOWNLOAD)
//    {
//        emit startDownload(list, token);
//    }
}

QList<FileStat> *NewDataSync::getLocalFile(const QString &caseId, const QString &path, const SyncOperateType &type, const QStringList &suffix)
{
    if (type == SyncOperateType::NO)
    {
        return NULL;
    }

    QDir dir(path);
    if (!dir.exists())
    {
        QMessageBox::warning(NULL,
                             "Warning",
                             "Path does not exist",
                             QMessageBox::Ok,
                             QMessageBox::Ok);

        return NULL;
    }

    QStringList list = path.split("/");
    if (list.size() == 0)
    {
        QMessageBox::warning(NULL,
                             "Warning",
                             "Path error",
                             QMessageBox::Ok,
                             QMessageBox::Ok);
        return NULL;
    }

    QList<FileStat> *localList = new QList<FileStat>;
    FileStat fileStatItem;

    QDirIterator it(path,
                    suffix,
                    QDir::NoDotAndDotDot | QDir::NoSymLinks | QDir::Files,
                    QDirIterator::Subdirectories);
    while (it.hasNext())
    {
        it.next();
        fileStatItem.fileName = it.fileInfo().absoluteFilePath();
        fileStatItem.createTime = it.fileInfo().created();
        fileStatItem.updateTime = it.fileInfo().lastModified();
        if (type == SyncOperateType::UPLOAD)
        {
            fileStatItem.fileUrl = getFileUrl(it.fileInfo().absoluteFilePath(), caseId, list.last());
            fileStatItem.hash = getMd5(it.fileInfo().absoluteFilePath());
        }
        localList->push_back(fileStatItem);
    }

    return localList;
}

QList<FileStat> *NewDataSync::getRemoteFile(QString caseId)
{
    QList<FileStat>* remoteList = new QList<FileStat>;
    return remoteList;
}

QString NewDataSync::getFileUrl(const QString &fileName, const QString &caseId, const QString &dir)
{
    QString caseToUpper = caseId.toUpper();

    int position = fileName.indexOf(dir);
    QString fileUrl = fileName;
    fileUrl.remove(0, position);
    fileUrl.replace(dir, caseToUpper);
    fileUrl.insert(0, "/");
    fileUrl.append("-");
    fileUrl.append(getUuid());
    //qDebug()<<fileUrl;

    return fileUrl;
}

QByteArray NewDataSync::getMd5(const QString &fileName)
{
    QFile file(fileName);
    if (file.open(QIODevice::ReadOnly) == false)
    {
        QMessageBox::warning(NULL,
                             "Warning",
                             "File open failed",
                             QMessageBox::Ok,
                             QMessageBox::Ok);

        return NULL;
    }

    QCryptographicHash hash(QCryptographicHash::Md5);
    while (!file.atEnd())
    {
        hash.addData(file.read(MD5_READ_MAX_SIZE));
    }
    QByteArray md5 = hash.result().toHex();
    file.close();
    //qDebug()<<md5;

    return md5;
}

QString NewDataSync::getUuid()
{
    QUuid id = QUuid::createUuid();
    QString uuid = id.toString();
    uuid.remove("{").remove("}");

    return uuid;
}


