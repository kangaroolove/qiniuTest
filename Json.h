#ifndef JSON_H
#define JSON_H

#include "FileStat.h"
#include<QByteArray>
#include<QMap>

enum ReplyResult
{
    TIME_OUT = 0,
    NORMAL,
    ERROR,
};

class Json
{
public:
    Json();
    ReplyResult analysisJson(const QByteArray& reply, QString& message);
    QString getToken(const QByteArray &reply);
    QList<FileStat>* getRemoteList(const QByteArray &reply);
    QByteArray generateJson(const QString &caseId, const FileStat &FileStat);
};

#endif // JSON_H
