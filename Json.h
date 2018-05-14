#ifndef JSON_H
#define JSON_H

#include "FileStat.h"
#include<QByteArray>
#include<QMap>

class Json
{
public:
    Json();
    bool analysisJson(const QByteArray& reply, QString& message);
    QString getToken(const QByteArray &reply);
    QList<FileStat>* getRemoteList(const QByteArray &reply);
    QByteArray generateJson(const QString &caseId, const FileStat &FileStat);
};

#endif // JSON_H
