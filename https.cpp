#include "https.h"


Https::Https(QObject *parent) : QObject(parent)
{

}

void Https::SetUrl(const QUrl& url)
{
    this->url = url;
    request.setUrl(url);
}

QUrl Https::GetUrl()
{
    return url;
}

void Https::SetSslConfiguration(const QSslConfiguration & config)
{
    this->sslConfig = config;
    request.setSslConfiguration(sslConfig);
}

void Https::SetRawHeaders(QMap<QString, QString> & headerList)
{
    if (headerList.isEmpty())
    {
        return;
    }

    QMap<QString, QString>::iterator it;
    for(it = headerList.begin(); it != headerList.end(); it++)
    {
         request.setRawHeader(it.key().toUtf8(), it.value().toUtf8());
    }
}

QList<QNetworkCookie> Https::GetAllCookies()
{
    QList<QNetworkCookie> tempList = cookieList;
    return tempList;
}

QByteArray Https::Get()
{
    QEventLoop loop;
    connect(&manager, SIGNAL(finished(QNetworkReply*)),
            &loop, SLOT(quit()));
    reply = manager.get(request);

    loop.exec();

    return GetReply();
}

QByteArray Https::Post(QByteArray & byteArray)
{
    QEventLoop loop;
    connect(&manager, SIGNAL(finished(QNetworkReply*)),
            &loop, SLOT(quit()));
    reply = manager.post(request, byteArray);

    loop.exec();

    return GetReply();
}

QByteArray Https::GetReply()
{
    if (reply->error() == QNetworkReply::NoError)
    {
        QTextCodec * pCodec = QTextCodec::codecForName("utf8");
        reply->deleteLater();
        return reply->readAll();
    }
    else
    {
        qDebug()<<"handle errors here";
        QVariant statusCodeV = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
        qDebug("found error .... code: %d %d", statusCodeV.toInt(), (int)reply->error());
        return NULL;
    }
}

