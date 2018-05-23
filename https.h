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
    void onNetworkStatusChanged(QNetworkSession::State state);
private:
    QUrl m_url;
    QNetworkRequest m_request;
    QNetworkAccessManager m_accessManager;
    QNetworkConfigurationManager m_configManager;
    QNetworkReply* m_reply;
    QSslConfiguration m_sslConfig;
    QList<QNetworkCookie> m_cookieList;
    QNetworkSession *m_session;
    QTimer *m_timer;
    QNetworkSession::State m_networkState;
    QByteArray getReply();
};

#endif // HTTPS_H
