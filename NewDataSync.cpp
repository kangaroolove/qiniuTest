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

    //m_localList = getLocalFile(caseId, path, m_operateType, m_suffixType);
    if (m_localList)
    {
        for (int i = 0; i < m_localList->size(); ++i)
        {
            qDebug()<<"fileName:"<<m_localList->at(i).fileName;
            qDebug()<<"filePath:"<<m_localList->at(i).filePath;
            qDebug()<<"fileType:"<<m_localList->at(i).fileType;
            qDebug()<<"createTime:"<<m_localList->at(i).createTime;
            qDebug()<<"updateTime:"<<m_localList->at(i).updateTime;
            qDebug()<<"fileUrl:"<<m_localList->at(i).fileUrl;
            qDebug()<<"hash:"<<m_localList->at(i).hash;
        }
    }

    //QString token = m_request.getToken();
    //qDebug()<<"token"<<token;
    m_remoteList = getRemoteFile(caseId);
    if (m_remoteList)
    {
        for (int i = 0; i < m_remoteList->size(); ++i)
        {
            qDebug()<<"fileName:"<<m_remoteList->at(i).fileName;
            qDebug()<<"filePath:"<<m_remoteList->at(i).filePath;
            qDebug()<<"fileType:"<<m_remoteList->at(i).fileType;
            qDebug()<<"createTime:"<<m_remoteList->at(i).createTime;
            qDebug()<<"updateTime:"<<m_remoteList->at(i).updateTime;
            qDebug()<<"fileUrl:"<<m_remoteList->at(i).fileUrl;
            qDebug()<<"hash:"<<m_remoteList->at(i).hash;
        }
    }
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
        fileStatItem.fileName = it.fileName();
        fileStatItem.filePath = it.filePath();
        fileStatItem.fileType = getFileType(it.fileInfo());
        fileStatItem.createTime = it.fileInfo().created();
        fileStatItem.updateTime = it.fileInfo().lastModified();
        if (type == SyncOperateType::UPLOAD)
        {
            fileStatItem.fileUrl = getFileUrl(it.filePath(), caseId, list.last());
            fileStatItem.hash = getMd5(it.fileInfo().absoluteFilePath());
        }
        localList->push_back(fileStatItem);
    }

    return localList;
}

QList<FileStat> *NewDataSync::getRemoteFile(const QString &caseId)
{
    return m_request.getRemoteList(caseId);
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

FileType NewDataSync::getFileType(const QFileInfo &fileInfo)
{
    QString suffix = fileInfo.suffix();
    QString fileName = fileInfo.fileName();

    if (suffix == "rtd")
    {
        return FileType::TOOTH_RTD;
    }
    else if (suffix == "rttsd")
    {
        return FileType::TOOTH_RTTSD;
    }
    else if (suffix == "srtd")
    {
        return FileType::TOOTH_SRTD;
    }
    else if (suffix == "stl")
    {
        if (fileName == "s0.stl")
        {
            return FileType::WEB_UP_STL;
        }
        else if (fileName == "ss0.stl")
        {
            return FileType::COMPRESSED_UPPER_STL;
        }
        else if (fileName == "sx0.stl")
        {
            return FileType::WEB_LOW_STL;
        }
        else if (fileName == "x0.stl")
        {
            return FileType::COMPRESSED_LOWER_STL;
        }
        else
        {
            return FileType::OTHER_FILE;
        }
    }
    else if (suffix == "dat")
    {
        if (fileName == "AngleCalBowData.dat")
        {
            return FileType::ANGLE_CAL_BOW_DATA;
        }
        else if (fileName == "CduCreateTeethBase.dat")
        {
            return FileType::CDU_CREATE_TEETH_BASE;
        }
        else if (fileName == "CduTeethWidthData.dat")
        {
            return FileType::CDU_TEETH_WIDTH_DATA;
        }
        else if (fileName == "DentalArchData.dat")
        {
            return FileType::DENTAL_ARCH_DATA;
        }
        else if (fileName == "EnvironmentStateBeforeClose.dat")
        {
            return FileType::ENVIRONMENT_STATE_BEFORE_CLOSE;
        }
        else if (fileName == "OcclusalPlaneData.dat")
        {
            return FileType::OCCLUSAL_PLANE_DATA;
        }
        else if (fileName == "CduEnvironmentStateSave.dat")
        {
            return FileType::ENVIRONMENT_STATE_SAVE;
        }
        else
        {
            return FileType::OTHER_FILE;
        }
    }
    else if (suffix == "rtp")
    {
        if (fileName.indexOf("Lower") != -1)
        {
            return FileType::LOWER_RTP;
        }
        else if (fileName.indexOf("Upper") != -1)
        {
            return FileType::UPPER_RTP;
        }
        else
        {
            return FileType::OTHER_FILE;
        }
    }
    else
    {
        return FileType::OTHER_FILE;
    }
}




