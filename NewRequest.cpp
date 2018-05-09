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

//QList<FileStat> *NewRequest::getRemoteList()
//{
//    QUrl url = initUrl();
//    Https http;
//    Json json;
//    http.SetUrl(url);
//    QByteArray reply = http.Post();
//    QString message;
//    if (json.analysisJson(reply, message) == true)
//    {

//    }
//    else
//    {
//        QMessageBox::warning(NULL,
//                             "Warning",
//                             message,
//                             QMessageBox::Ok,
//                             QMessageBox::Ok);

//        return QString::null;
//    }
//}

QUrl NewRequest::initUrl(QString cmd)
{
    QUrl url = QString("%1%2").arg(URL).arg(cmd);
    return url;
}

QSslConfiguration NewRequest::initSsl()
{
    QSslConfiguration sslConfig = QSslConfiguration::defaultConfiguration();
    sslConfig.setPeerVerifyMode(QSslSocket::VerifyNone);
    sslConfig.setProtocol(QSsl::TlsV1_2);

    return sslConfig;
}

