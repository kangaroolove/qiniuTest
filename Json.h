#ifndef JSON_H
#define JSON_H

#include<QByteArray>
class Json
{
public:
    Json();
    bool analysisJson(const QByteArray& reply, QString& message);
    QString getToken(const QByteArray &reply);
};

#endif // JSON_H
