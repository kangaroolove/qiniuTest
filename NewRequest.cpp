#include "NewRequest.h"

NewRequest::NewRequest()
{
    m_manager = NULL;
    m_manager = new QNetworkAccessManager;

    connect(&m_timeoutTimer, SIGNAL(timeout()), this, SLOT(onTimerTimeout()));
}

NewRequest::~NewRequest()
{
    if (m_manager)
    {
        delete m_manager;
        m_manager = NULL;
    }
}

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

void NewRequest::onTimerTimeout()
{

}

