#include "NewUploadThread.h"
#include "qiniu/resumable_io.h"
#include "qiniu/rs.h"
#include "qiniu/base.h"
#include <QDebug>
#include <string.h>

NewUploadThread::NewUploadThread(QObject *parent) : QObject(parent)
{

}

void NewUploadThread::setCaseId(const QString &caseId)
{
    m_caseId = caseId;
}

void NewUploadThread::onUploadStart(QList<FileStat> *uploadFileList, QString &token)
{
    if (token.isNull())
    {
        qDebug()<<"token is null";
        return;
    }

    m_uploadFailedList->clear();
    delete m_uploadFailedList;
    m_uploadFailedList = NULL;
    m_uploadFailedList = new QList<FileStat>;

    QByteArray charFileUrl;
    QByteArray charLocalFile;
    QByteArray charUptoken = token.toLatin1();

    char *uptoken = charUptoken.data();
    for (int i = 0; i < uploadFileList->size(); ++i)
    {
        Qiniu_Rio_PutRet putRet;
        Qiniu_Client client;
        Qiniu_Rio_PutExtra putExtra;

        charFileUrl = uploadFileList->at(i).fileUrl.toLatin1();
        charLocalFile = uploadFileList->at(i).fileName.toLatin1();

        char *key = charFileUrl.data();
        char *localFile = charLocalFile.data();
        const char *hash = uploadFileList->at(i).hash.data();

        Qiniu_Zero(putExtra);

        Qiniu_Use_Zone_Huanan(Qiniu_False);

        Qiniu_Client_InitNoAuth(&client, 1024);
        Qiniu_Error error = Qiniu_Rio_PutFile(&client, &putRet, uptoken, key, localFile, &putExtra);
        if (error.code != 200)
        {
            qDebug()<<error.code;
            (*uploadFileList)[i].errorCode = error.code;
            m_uploadFailedList->push_back(uploadFileList->at(i));
        }
        else
        {
            qDebug()<<QString("key: %1").arg(putRet.key);
            qDebug()<<QString("hash: %1").arg(putRet.hash);
            if ((strcmp(putRet.key, charFileUrl.data()) == 0 && (strcmp(putRet.hash, hash) == 0)))
            {
                emit uploadFileSuccessfully();
                QMap<QString, QString>map = initUpdateMap(m_caseId, uploadFileList->at(i));
                QByteArray data = m_json.generateJson(map);
                m_request.updateRemoteSql(data);
            }
        }

        emit refreshProgressBar();

        Qiniu_Free(uptoken);
        Qiniu_Client_Cleanup(&client);
    }

    if (m_uploadFailedList->size() != 0)
    {
        emit uploadFileFailed(m_uploadFailedList);
    }
    else
    {
        emit uploadAllFileSuccessfully();
    }
}

QMap<QString, QString> NewUploadThread::initUpdateMap(const QString &caseId, const FileStat &fileStat)
{
    QMap<QString, QString>map;
    map.insert("caseinfoId", caseId);
    map.insert("updateTime", QString(fileStat.updateTime.toTime_t()));
    map.insert("filetypekeyId", QString::number(fileStat.fileType));
    map.insert("filename", fileStat.fileUrl);

    return map;
}

