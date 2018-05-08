#ifndef HTTPS_H
#define HTTPS_H

#include <QtNetwork>
#include <QObject>

class Https : public QObject
{
    Q_OBJECT
public:
    explicit Https(QObject *parent = 0);
    void SetUrl(const QUrl& url);
    QUrl GetUrl();
    void SetSslConfiguration(const QSslConfiguration & config);
    void SetRawHeaders(QMap<QString, QString> & headerList);
    void SetRawHeaders(QString& url, QMap<QString, QString> & headerList);
    QList<QNetworkCookie> GetAllCookies();
    QByteArray Get();
    QByteArray Post(QByteArray& byteArray);
private:
    QUrl url;
    QNetworkRequest request;
    QStringList headerList;
    QNetworkAccessManager manager;
    QNetworkReply* reply;
    QSslConfiguration sslConfig;
    QList<QNetworkCookie> cookieList;
    QByteArray GetReply();
};

#endif // HTTPS_H
