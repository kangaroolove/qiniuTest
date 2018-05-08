#include "Json.h"
#include <QJsonDocument>

#include <QJsonObject>
#include <QVariant>

Json::Json()
{

}

bool Json::analysisJson(const QByteArray& reply, QString& message)
{
    if (reply.isNull())
    {
        return false;
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
                        return true;
                    }
                }
            }
            if (object.contains("message"))
            {
                QJsonValue value = object.value("message");
                if (value.isString())
                {
                    message = value.toString();
                    return false;
                }
            }
        }
    }

    return false;
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


