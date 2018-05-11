#ifndef JSON_H
#define JSON_H

#include "FileStat.h"
#include<QByteArray>

class Json
{
public:
    Json();
    bool analysisJson(const QByteArray& reply, QString& message);
    QString getToken(const QByteArray &reply);
    QList<FileStat>* getRemoteList(const QByteArray &reply);
};

#endif // JSON_H
