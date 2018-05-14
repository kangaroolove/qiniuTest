#include "dialog.h"
#include "ui_dialog.h"
#include <QMessageBox>
#include <QFileDialog>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    m_uploadCount = 0;
    m_uploadSuccessfulCount = 0;
    m_downloadCount = 0;
    m_downloadSuccessfulCount = 0;

    connect(ui->btn_dir, SIGNAL(clicked(bool)), this, SLOT(onBtnDirClicked()));
    connect(ui->btn_upload, SIGNAL(clicked(bool)), this, SLOT(onBtnUploadClicked()));
    connect(ui->btn_download, SIGNAL(clicked(bool)), this, SLOT(onBtnDownloadClicked()));

    m_newDataSync = new NewDataSync;
    connect(m_newDataSync, SIGNAL(uploadFileSuccessfully()), this, SLOT(onFileUploadSuccessfully()));
    connect(m_newDataSync, SIGNAL(uploadAllFileSuccessfully()), this, SLOT(onAllFileUploadSuccessfully()));
    connect(m_newDataSync, SIGNAL(uploadFileFailed(QList<FileStat>*)), this, SLOT(onFileUploadFailed(QList<FileStat>*)));
    connect(m_newDataSync, SIGNAL(downloadFileSuccessfully()), this, SLOT(onFileDownloadSuccessfully()));
    connect(m_newDataSync, SIGNAL(downloadAllFileSuccessfully()), this, SLOT(onAllFileDownloadSuccessfully()));
    connect(m_newDataSync, SIGNAL(downloadFileFailed(QList<FileStat>*)), this, SLOT(onFileDownloadFailed(QList<FileStat>*)));
    connect(m_newDataSync, SIGNAL(refreshProgressBar()), this, SLOT(onProgressBarRefresh()));
    connect(m_newDataSync, SIGNAL(setProgressBarMaxValue(int, SyncOperateType)), this, SLOT(onProgressBarMaxValueSet(int, SyncOperateType)));

    ui->lab_dir->setText("C:/Users/pangkuanxin/Desktop/1");
    ui->txt_caseId->setText("2018050016");
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

void Dialog::onBtnUploadClicked()
{
    qDebug()<<"upload";
    QString path = ui->lab_dir->text();
    QString caseId = ui->txt_caseId->text();

    ui->progressBar->setValue(0);

    m_newDataSync->setOperateType(UPLOAD);
    m_newDataSync->start(caseId, path);
}

void Dialog::onBtnDownloadClicked()
{
    qDebug()<<"download";
    QString path = ui->lab_dir->text();
    QString caseId = ui->txt_caseId->text();

    ui->progressBar->setValue(0);

    m_newDataSync->setOperateType(DOWNLOAD);
    m_newDataSync->start(caseId, path);
}

void Dialog::onBtnDirClicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                    ".",
                                                    QFileDialog::ShowDirsOnly
                                                    | QFileDialog::DontResolveSymlinks);
    ui->lab_dir->setText(dir);
}

void Dialog::onProgressBarMaxValueSet(int value, SyncOperateType type)
{
    if (value == 0)
    {
        QString message;
        if (type == SyncOperateType::UPLOAD)
        {
            message.append("Latest, do not need to upload");
        }
        else if (type == SyncOperateType::DOWNLOAD)
        {
            message.append("Latest, do not need to download");
        }

        QMessageBox::information(this,
                                 "information",
                                 message,
                                 QMessageBox::Ok,
                                 QMessageBox::Ok);
    }
    else
    {
        if (type == SyncOperateType::UPLOAD)
        {
            m_uploadCount = value;
        }
        else if (type == SyncOperateType::DOWNLOAD)
        {
            m_downloadCount = value;
        }
        ui->progressBar->setValue(0);
        ui->progressBar->setMaximum(value);
    }
}
