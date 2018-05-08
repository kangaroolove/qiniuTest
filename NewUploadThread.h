#ifndef NEWUPLOADTHREAD_H
#define NEWUPLOADTHREAD_H

#include <QObject>

class NewUploadThread : public QObject
{
    Q_OBJECT
public:
    explicit NewUploadThread(QObject *parent = 0);

signals:

public slots:
    void onUploadStart();
};

#endif // NEWUPLOADTHREAD_H
