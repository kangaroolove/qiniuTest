#ifndef NEWREQUEST_H
#define NEWREQUEST_H

#include<QNetworkAccessManager>
#include<QTimer>
#include <QUrl>
#include "FileStat.h"

#define URL "http://172.18.169.111:3080"
#define GET_TOKEN   "/aligner/client/qiNiuToken"
#define GET_REMOTE_FILE_LIST    "/aligner/client/originalModel/"
#define UPDATE_REMOTE_SQL   "/aligner/client/file"

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
    QList<FileStat>* getRemoteList(const QString &caseId);
    void updateRemoteSql(QByteArray &data);
private:
    QUrl initUrl(const QString &cmd);
    QUrl initUrl(const QString &cmd, const QString &caseId);
    QSslConfiguration initSsl();
};

#endif // NEWREQUEST_H
