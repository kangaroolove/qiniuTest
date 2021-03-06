#include "NewUploadThread.h"
#include "qiniu/resumable_io.h"
#include "qiniu/rs.h"
#include "qiniu/base.h"
#include <QDebug>
#include <string.h>

NewUploadThread::NewUploadThread(QObject *parent) : QObject(parent)
{
    m_uploadFailedList = NULL;
    Qiniu_Global_Init(-1);
}

void NewUploadThread::onUploadStart(QList<FileStat> *uploadFileList, QString token, QString caseId)
{
    if (token.isNull())
    {
        qDebug()<<"token is null";
        return;
    }

    if (m_uploadFailedList)
    {
        m_uploadFailedList->clear();
        delete m_uploadFailedList;
        m_uploadFailedList = NULL;
    }

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
        charLocalFile = uploadFileList->at(i).filePath.toLatin1();

        char *key = charFileUrl.data();
        char *localFile = charLocalFile.data();

        qDebug()<<"key:"<<key;
        qDebug()<<"localFile:"<<localFile;

        Qiniu_Zero(putExtra);

        Qiniu_Use_Zone_Huanan(Qiniu_False);

        Qiniu_Client_InitNoAuth(&client, 1024);
        Qiniu_Error error = Qiniu_Rio_PutFile(&client, &putRet, uptoken, key, localFile, &putExtra);
        if (error.code != 200)
        {
            qDebug()<<"error:"<<error.code;
            qDebug()<<"message:"<<error.message;
            (*uploadFileList)[i].errorCode = error.code;
            m_uploadFailedList->push_back(uploadFileList->at(i));
        }
        else
        {
            qDebug()<<QString("key: %1").arg(putRet.key);
            if (strcmp(putRet.key, charFileUrl.data()) == 0)
            {
                qDebug()<<"equal";
                QByteArray data = m_json.generateJson(caseId, uploadFileList->at(i));
                m_request.updateRemoteSql(data);
            }
        }

        emit refreshProgressBar();

        Qiniu_Client_Cleanup(&client);
    }

    emit uploadFinished(m_uploadFailedList);
}

