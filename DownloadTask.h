#ifndef DOWNLOADTASK_H
#define DOWNLOADTASK_H

#include "FileStat.h"
#include <QObject>
#include <QRunnable>

class DownloadTask : public QObject , public QRunnable
{
    Q_OBJECT
public:
    explicit DownloadTask(FileStat fileStat, QObject *parent = 0);
    void run();
signals:

public slots:

private:
    FileStat m_fileStat;
};

#endif // DOWNLOADTASK_H