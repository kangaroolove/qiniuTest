#include "NewRequest.h"
#include "https.h"
#include "Json.h"
#include <QMessageBox>

NewRequest::NewRequest()
{
}

NewRequest::~NewRequest()
{
}

QString NewRequest::getToken()
{
    QUrl url = initUrl(GET_TOKEN);
    Https http;
    Json json;
    http.setUrl(url);
    QString message;

    QByteArray reply = http.get();

    if (json.analysisJson(reply, message) == true)
    {
        return json.getToken(reply);
    }
    else
    {
        QMessageBox::warning(NULL,
                             "Warning",
                             message,
                             QMessageBox::Ok,
                             QMessageBox::Ok);

        return QString::null;
    }
}

QList<FileStat> *NewRequest::getRemoteList(const QString &caseId)
{
    QUrl url = initUrl(GET_REMOTE_FILE_LIST, caseId);
    Https http;
    Json json;
    http.setUrl(url);
    QByteArray reply = http.get();
    QString message;
    if (json.analysisJson(reply, message) == true)
    {
        return json.getRemoteList(reply);
    }
    else
    {
        QMessageBox::warning(NULL,
                             "Warning",
                             message,
                             QMessageBox::Ok,
                             QMessageBox::Ok);

        return NULL;
    }
}

void NewRequest::updateRemoteSql(QByteArray &data)
{
    QUrl url = initUrl(UPDATE_REMOTE_SQL);
    Https http;
    Json json;
    http.setUrl(url);
    http.setRawHeader("Content-Type", "application/json");
    QByteArray reply = http.post(data);
    QString message;
    if (json.analysisJson(reply, message) == true)
    {

    }
    else
    {
        QMessageBox::warning(NULL,
                             "Warning",
                             message,
                             QMessageBox::Ok,
                             QMessageBox::Ok);
    }
}

QUrl NewRequest::initUrl(const QString &cmd)
{
    QUrl url = QString("%1%2").arg(URL).arg(cmd);
    return url;
}

QUrl NewRequest::initUrl(const QString &cmd, const QString &caseId)
{
    QUrl url(QString("%1%2%3").arg(URL).arg(cmd).arg(caseId));
    return url;
}

QSslConfiguration NewRequest::initSsl()
{
    QSslConfiguration sslConfig = QSslConfiguration::defaultConfiguration();
    sslConfig.setPeerVerifyMode(QSslSocket::VerifyNone);
    sslConfig.setProtocol(QSsl::TlsV1_2);

    return sslConfig;
}

