#ifndef HTTPS_H
#define HTTPS_H

#include <QtNetwork>
#include <QObject>

#define TIMER_INTERVAL  5000

class Https : public QObject
{
    Q_OBJECT
public:
    explicit Https(QObject *parent = 0);
    void setUrl(const QUrl& url);
    QUrl getUrl();
    void setSslConfiguration(const QSslConfiguration & config);
    void setRawHeaders(QMap<QString, QString> & headerList);
    void setRawHeaders(QString& url, QMap<QString, QString> & headerList);
    QList<QNetworkCookie> GetAllCookies();
    QByteArray get();
    QByteArray post(QByteArray& byteArray);
private:
    QUrl url;
    QNetworkRequest request;
    QStringList headerList;
    QNetworkAccessManager manager;
    QNetworkReply* reply;
    QSslConfiguration sslConfig;
    QList<QNetworkCookie> cookieList;
    QByteArray getReply();
};

#endif // HTTPS_H
