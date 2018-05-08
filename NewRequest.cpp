#include "NewRequest.h"
#include "https.h"
#include "Json.h"
#include <QMessageBox>

NewRequest::NewRequest()
{
    connect(&m_timeoutTimer, SIGNAL(timeout()), this, SLOT(onTimerTimeout()));
}

NewRequest::~NewRequest()
{
}

QString NewRequest::getToken()
{
    QUrl url = initUrl(GET_TOKEN);
    Https http;
    Json json;
    http.SetUrl(url);
    QString message;

    startTimer();
    QByteArray reply = http.Get();

    if (json.analysisJson(reply, message) == true)
    {
        stopTimer();
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

void NewRequest::startTimer()
{
    if (!m_timeoutTimer.isActive())
    {
        m_timeoutTimer.start(TIMER_INTERVAL);
    }
}

void NewRequest::stopTimer()
{
    if (m_timeoutTimer.isActive())
    {
        m_timeoutTimer.stop();
    }
}

QUrl NewRequest::initUrl(QString cmd)
{
    QUrl url = QString("%1%2").arg(URL).arg(cmd);
    return url;
}

void NewRequest::get()
{

}

void NewRequest::onTimerTimeout()
{

}

