#include "dialog.h"
#include "ui_dialog.h"
#include <QMessageBox>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    m_uploadCount = 0;
    m_uploadSuccessfulCount = 0;
    m_downloadCount = 0;
    m_downloadSuccessfulCount = 0;

    m_newDataSync = new NewDataSync;
    connect(m_newDataSync, SIGNAL(uploadFileSuccessfully()), this, SLOT(onFileUploadSuccessfully()));
    connect(m_newDataSync, SIGNAL(uploadAllFileSuccessfully()), this, SLOT(onAllFileUploadSuccessfully()));
    connect(m_newDataSync, SIGNAL(uploadFileFailed(QList<FileStat>*)), this, SLOT(onFileUploadFailed(QList<FileStat>*)));
    connect(m_newDataSync, SIGNAL(downloadFileSuccessfully()), this, SLOT(onFileDownloadSuccessfully()));
    connect(m_newDataSync, SIGNAL(downloadAllFileSuccessfully()), this, SLOT(onAllFileDownloadSuccessfully()));
    connect(m_newDataSync, SIGNAL(downloadFileFailed(QList<FileStat>*)), this, SLOT(onFileDownloadFailed(QList<FileStat>*)));
    connect(m_newDataSync, SIGNAL(refreshProgressBar()), this, SLOT(onProgressBarRefresh()));
    m_newDataSync->start();
}

Dialog::~Dialog()
{
    delete ui;
    if (m_newDataSync)
    {
        delete m_newDataSync;
        m_newDataSync = NULL;
    }
}

void Dialog::onFileUploadSuccessfully()
{
    ++m_uploadSuccessfulCount;
}

void Dialog::onAllFileUploadSuccessfully()
{
    QString message("Upload total:" + QString::number(m_uploadCount) + ",successfully count:" + QString::number(m_uploadSuccessfulCount));
    QMessageBox::information(this,
                             "Information",
                             message,
                             QMessageBox::Ok,
                             QMessageBox::Ok);
}

void Dialog::onFileUploadFailed(QList<FileStat> *uploadFailedList)
{
    QString message("Upload failed count:");
    message.append(uploadFailedList->size());
    for (int i = 0; i < uploadFailedList->size(); ++i)
    {
        message.append("\n");
        message.append(" error code:");
        message.append(uploadFailedList->at(i).errorCode);
        message.append(" fileName:");
        message.append(uploadFailedList->at(i).fileUrl);
    }

    QMessageBox::warning(this,
                         "Warning",
                         message,
                         QMessageBox::Ok,
                         QMessageBox::Ok);
}

void Dialog::onProgressBarRefresh()
{
    int value = ui->progressBar->value();
    ui->progressBar->setValue(++value);
}

void Dialog::onFileDownloadSuccessfully()
{
    ++m_downloadSuccessfulCount;
}

void Dialog::onAllFileDownloadSuccessfully()
{
    QString message("Download total:" + QString::number(m_downloadCount) + ",successfully count:" + QString::number(m_downloadSuccessfulCount));
    QMessageBox::information(this,
                             "Information",
                             message,
                             QMessageBox::Ok,
                             QMessageBox::Ok);
}

void Dialog::onFileDownloadFailed(QList<FileStat> *downloadFailedList)
{
    QString message("Download failed count:");
    message.append(downloadFailedList->size());
    for (int i = 0; i < downloadFailedList->size(); ++i)
    {
        message.append("\n");
        message.append(" error code:");
        message.append(downloadFailedList->at(i).errorCode);
        message.append(" fileName:");
        message.append(downloadFailedList->at(i).fileUrl);
    }

    QMessageBox::warning(this,
                         "Warning",
                         message,
                         QMessageBox::Ok,
                         QMessageBox::Ok);
}
