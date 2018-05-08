#ifndef NEWREQUEST_H
#define NEWREQUEST_H

#include<QNetworkAccessManager>
#include<QTimer>
#include <QUrl>

#define TIMER_INTERVAL  5000
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
private:
    QTimer m_timeoutTimer;
    void startTimer();
    void stopTimer();
    QUrl initUrl(QString cmd);
    void initSsl();
    void get();
    void post();
public slots:
    void onTimerTimeout();
};

#endif // NEWREQUEST_H
