#include "Json.h"
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QVariant>
#include <QDebug>

Json::Json()
{

}

ReplyResult Json::analysisJson(const QByteArray& reply, QString& message)
{
    if (reply.isNull())
    {
        message.append("Time out");
        return TIME_OUT;
    }

    QJsonParseError jsonError;
    QJsonDocument doucment = QJsonDocument::fromJson(reply, &jsonError);

    if (!doucment.isNull() && (jsonError.error == QJsonParseError::NoError))
    {
        if (doucment.isObject())
        {
            QJsonObject object = doucment.object();
            if (object.contains("errorCode"))
            {
                QJsonValue value = object.value("errorCode");
                if (value.isDouble())
                {
                    int result = value.toVariant().toInt();
                    if (result == 0)
                    {
                        return NORMAL;
                    }
                }
            }
            if (object.contains("message"))
            {
                QJsonValue value = object.value("message");
                if (value.isString())
                {
                    message = value.toString();
                    return ERROR;
                }
            }
        }
    }

    return ERROR;
}

QString Json::getToken(const QByteArray &reply)
{
    if (reply.isNull())
    {
        return QString::null;
    }

    QJsonParseError jsonError;
    QJsonDocument doucment = QJsonDocument::fromJson(reply, &jsonError);

    if (!doucment.isNull() && (jsonError.error == QJsonParseError::NoError))
    {
        if (doucment.isObject())
        {
            QJsonObject object = doucment.object();
            if (object.contains("data"))
            {
                QJsonValue value = object.value("data");
                if (value.isString())
                {
                    QString token = value.toString();
                    return token;
                }
            }
        }
    }

    return QString::null;
}

QList<FileStat> *Json::getRemoteList(const QByteArray &reply)
{
    if (reply.isNull())
    {
        return NULL;
    }

    //qDebug()<<reply;
    QJsonParseError jsonError;
    QJsonDocument doucment = QJsonDocument::fromJson(reply, &jsonError);

    if (!doucment.isNull() && (jsonError.error == QJsonParseError::NoError))
    {
        QList<FileStat>* remoteList = new QList<FileStat>;
        if (doucment.isObject())
        {
            QJsonObject object = doucment.object();
            if (object.contains("data"))
            {
                QJsonValue value = object.value("data");
                if (value.isArray())
                {
                    QJsonArray array = value.toArray();
                    for (int i = 0; i < array.size(); ++i)
                    {
                        FileStat fileStat;
                        QJsonValue value = array.at(i);
                        if (value.isObject())
                        {
                            QJsonObject object = value.toObject();
                            if (object.contains("fileUrl"))
                            {
                                QJsonValue value = object.value("fileUrl");
                                if (value.isString())
                                {
                                    fileStat.fileUrl = value.toString();
                                    //qDebug()<<"fileUrl:"<<fileStat.fileUrl;
                                }
                            }
                            if (object.contains("update_time"))
                            {
                                QJsonValue value = object.value("update_time");
                                if (value.isDouble())
                                {
                                    fileStat.updateTime = QDateTime::fromMSecsSinceEpoch(value.toVariant().toLongLong());
                                }
                            }
                            if (object.contains("fileTypeKey_id"))
                            {
                                QJsonValue value = object.value("fileTypeKey_id");
                                if (value.isDouble())
                                {
                                    fileStat.fileType = value.toVariant().toInt();
                                }
                            }
                            if (object.contains("fileName"))
                            {
                                QJsonValue value = object.value("fileName");
                                if (value.isString())
                                {
                                    fileStat.webName = value.toString();
                                }
                            }
                        }
                        remoteList->push_back(fileStat);
                    }
                }
            }
        }

        return remoteList;
    }

    return NULL;
}

QByteArray Json::generateJson(const QString &caseId, const FileStat &FileStat)
{
    QJsonObject object;
    object.insert("caseinfoId", caseId);
    object.insert("updateTime", FileStat.updateTime.toMSecsSinceEpoch());
    object.insert("filetypekeyId", FileStat.fileType);
    object.insert("filename", FileStat.fileUrl);

    QJsonDocument document;
    document.setObject(object);

    //qDebug()<<object;

    return document.toJson(QJsonDocument::Compact);
}


