#ifndef NEWREQUEST_H
#define NEWREQUEST_H

#include<QNetworkAccessManager>
#include<QTimer>
#include <QUrl>
#include "FileStat.h"

#define URL "http://172.18.169.111:3080"
#define GET_TOKEN   "/aligner/client/file/qiNiuToken"

enum RequestType
{
    GET = 0,
    POST,
};

class NewRequest : QObject
{
    Q_OBJECT
public:
    NewRequest();
    ~NewRequest();
    QString getToken();
    QList<FileStat>* getRemoteList();
private:
    QUrl initUrl(QString cmd);
    QSslConfiguration initSsl();
};

#endif // NEWREQUEST_H
