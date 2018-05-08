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

    m_fileCompare = new FileCompare;
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
        m_localList = NULL;
    }
    if (m_remoteList)
    {
        m_remoteList->clear();
        m_remoteList = NULL;
    }
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

void NewDataSync::start()
{
    if (m_localList)
    {
        m_localList->clear();
        m_localList = NULL;
    }

    if (m_remoteList)
    {
        m_remoteList->clear();
        m_remoteList = NULL;
    }
    QString dir("C:/Users/pangkuanxin/Desktop/abc");
    m_localList = getLocalFile("20180508", dir, UPLOAD);
    for (int i = 0; i < m_localList->size(); ++i)
    {
        qDebug()<<m_localList->at(i).fileName;
        qDebug()<<m_localList->at(i).createTime;
        qDebug()<<m_localList->at(i).updateTime;
        qDebug()<<m_localList->at(i).fileUrl;
        qDebug()<<m_localList->at(i).hash;
    }
   // QString token = m_request.getToken();
    //qDebug()<<"token"<<token;
    m_remoteList = getRemoteFile("20180508");
}

QList<FileStat> *NewDataSync::getLocalFile(QString caseId, const QString &path, SyncOperateType type)
{
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

QString NewDataSync::getFileId(const QString &caseId, const QString &fileName)
{
//    switch ()
//    QString fileId("%1-%2-%3").arg(caseId);
    return NULL;
}

QString NewDataSync::getUuid()
{
    QUuid id = QUuid::createUuid();
    QString uuid = id.toString();
    uuid.remove("{").remove("}");

    return uuid;
}


