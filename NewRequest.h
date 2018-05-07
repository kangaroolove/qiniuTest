#ifndef NEWREQUEST_H
#define NEWREQUEST_H

#include<QNetworkAccessManager>
#include<QTimer>

#define TIMER_INTERVAL  5000

enum RequestType
{
    GET = 0,
    POST,
};

class NewRequest
{
public:
    NewRequest();
    ~NewRequest();
private:
    QTimer m_timeoutTimer;
    QNetworkAccessManager* m_manager;
    void startTimer();
    void stopTimer();
public slots:
    void onTimerTimeout();
};

#endif // NEWREQUEST_H
