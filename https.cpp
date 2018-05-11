#include "https.h"
#include <QDebug>

Https::Https(QObject *parent) : QObject(parent)
{

}

void Https::setUrl(const QUrl& url)
{
    this->url = url;
    request.setUrl(url);
}

QUrl Https::getUrl()
{
    return url;
}

void Https::setSslConfiguration(const QSslConfiguration & config)
{
    this->sslConfig = config;
    request.setSslConfiguration(sslConfig);
}

void Https::setRawHeaders(QMap<QString, QString> & headerList)
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

void Https::setRawHeader(const QByteArray &headerName, const QByteArray &headerValue)
{
    request.setRawHeader(headerName, headerValue);
}

QList<QNetworkCookie> Https::GetAllCookies()
{
    QList<QNetworkCookie> tempList = cookieList;
    return tempList;
}

QByteArray Https::get()
{
    QTimer timer;
    timer.setInterval(TIMER_INTERVAL);
    timer.setSingleShot(true);

    QEventLoop loop;
    connect(&timer, SIGNAL(timeout()), &loop, SLOT(quit()));
    connect(&manager, SIGNAL(finished(QNetworkReply*)), &loop, SLOT(quit()));
    reply = manager.get(request);
    timer.start();

    loop.exec();

    if (timer.isActive())
    {
        timer.stop();
        return getReply();
    }
    else
    {
        disconnect(&manager, SIGNAL(finished(QNetworkReply*)), &loop, SLOT(quit()));
        reply->abort();
        reply->deleteLater();
        qDebug()<<"timeout";
        return NULL;
    }
}

QByteArray Https::post(QByteArray & byteArray)
{
    QTimer timer;
    timer.setInterval(TIMER_INTERVAL);
    timer.setSingleShot(true);

    QEventLoop loop;
    connect(&manager, SIGNAL(finished(QNetworkReply*)), &loop, SLOT(quit()));
    reply = manager.post(request, byteArray);
    timer.start();

    loop.exec();

    if (timer.isActive())
    {
        timer.stop();
        return getReply();
    }
    else
    {
        disconnect(&manager, SIGNAL(finished(QNetworkReply*)), &loop, SLOT(quit()));
        reply->abort();
        reply->deleteLater();
        qDebug()<<"timeout";
        return NULL;
    }
}

QByteArray Https::getReply()
{
    if (reply->error() == QNetworkReply::NoError)
    {
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

