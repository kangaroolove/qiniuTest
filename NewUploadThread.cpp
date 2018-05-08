#include "NewUploadThread.h"
#include "qiniu/resumable_io.h"
#include "qiniu/rs.h"
#include "qiniu/base.h"
#include <QDebug>

NewUploadThread::NewUploadThread(QObject *parent) : QObject(parent)
{

}

void NewUploadThread::onUploadStart()
{
    Qiniu_Rio_PutRet putRet;
    Qiniu_Client client;
    Qiniu_Rio_PutExtra putExtra;

    char *key;
    char *localFile;

    Qiniu_Zero(putExtra);

    char *uptoken;

    Qiniu_Use_Zone_Huanan(Qiniu_False);

    Qiniu_Client_InitNoAuth(&client, 1024);
    Qiniu_Error error = Qiniu_Rio_PutFile(&client, &putRet, uptoken, key, localFile, &putExtra);
    if (error.code != 200)
    {
        qDebug()<<error.code;
       //qDebug()<<QString("upload file %1:%2 error").arg(bucket).arg(key);
    }
    else
    {
        //qDebug()<<QString("upload file %1:%2 success").arg(bucket).arg(key);
        qDebug()<<QString("key: %1").arg(putRet.key);
        qDebug()<<QString("hash: %1").arg(putRet.hash);
    }

    Qiniu_Free(uptoken);
    Qiniu_Client_Cleanup(&client);
}

