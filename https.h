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
    ~Https();
    void setUrl(const QUrl& url);
    QUrl getUrl();
    void setSslConfiguration(const QSslConfiguration & config);
    void setRawHeaders(QMap<QString, QString> & headerList);
    void setRawHeader(const QByteArray &headerName, const QByteArray &headerValue);
    void setRawHeaders(QString& url, QMap<QString, QString> & headerList);
    QList<QNetworkCookie> GetAllCookies();
    QByteArray get();
    QByteArray post(QByteArray& byteArray);
    QByteArray downloadFile();
public slots:
    void onDownloadProgress();
private:
    QUrl url;
    QNetworkRequest request;
    QStringList headerList;
    QNetworkAccessManager manager;
    QNetworkReply* reply;
    QSslConfiguration sslConfig;
    QList<QNetworkCookie> cookieList;
    QTimer m_timer;
    QByteArray getReply();
};

#endif // HTTPS_H
