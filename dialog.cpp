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
    m_downloadCount = 0;

    connect(ui->btn_dir, SIGNAL(clicked(bool)), this, SLOT(onBtnDirClicked()));
    connect(ui->btn_upload, SIGNAL(clicked(bool)), this, SLOT(onBtnUploadClicked()));
    connect(ui->btn_download, SIGNAL(clicked(bool)), this, SLOT(onBtnDownloadClicked()));

    m_newDataSync = new NewDataSync;
    connect(m_newDataSync, SIGNAL(uploadFinished(QList<FileStat>*)), this, SLOT(onUploadFinished(QList<FileStat>*)));
    connect(m_newDataSync, SIGNAL(downloadFinished(QList<FileStat>*)), this, SLOT(onDownloadFinished(QList<FileStat>*)));
    connect(m_newDataSync, SIGNAL(refreshProgressBar()), this, SLOT(onProgressBarRefresh()), Qt::QueuedConnection);
    connect(m_newDataSync, SIGNAL(setProgressBarMaxValue(int, SyncOperateType)), this, SLOT(onProgressBarMaxValueSet(int, SyncOperateType)));

    //ui->lab_dir->setText("C:/Users/pangkuanxin/Desktop/1");
    //ui->txt_caseId->setText("2018050001");
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

void Dialog::onUploadFinished(QList<FileStat> *uploadFailedList)
{
    if (uploadFailedList)
    {
        int failedCount = uploadFailedList->size();
        QString message("Upload total:" + QString::number(m_uploadCount));
        message.append(",successfully count:" + QString::number(m_uploadCount - failedCount));
        message.append(",failed count:" + QString::number(failedCount));

        QMessageBox::warning(this,
                             "Warning",
                             message,
                             QMessageBox::Ok,
                             QMessageBox::Ok);
    }
    else
    {
        qDebug()<<"uploadFileList is null";
    }
}

void Dialog::onDownloadFinished(QList<FileStat> *downloadFailedList)
{
    if (downloadFailedList)
    {
        int failedCount = downloadFailedList->size();

        QString message("Download total:" + QString::number(m_downloadCount));
        message.append(",successfully count:" + QString::number(m_downloadCount - failedCount));
        message.append(",failed count:" + QString::number(failedCount));

        QMessageBox::warning(this,
                             "Warning",
                             message,
                             QMessageBox::Ok,
                             QMessageBox::Ok);
    }
    else
    {
        qDebug()<<"downloadFailedList is null";
    }
}

void Dialog::onProgressBarRefresh()
{
    //qDebug()<<"update progress";
    int value = ui->progressBar->value();
    ui->progressBar->setValue(++value);
}

void Dialog::onBtnUploadClicked()
{
    qDebug()<<"upload";
    QString path = ui->lab_dir->text();
    QString caseId = ui->txt_caseId->text();

    NewDataSyncStatus status =  m_newDataSync->getStatus();
    if (status == NewDataSyncStatus::FREE)
    {
        m_uploadCount = 0;
        ui->progressBar->setValue(0);
        m_newDataSync->setOperateType(UPLOAD);
        m_newDataSync->start(caseId, path);
    }
    else
    {
        QMessageBox::information(this,
                                 "Information",
                                 "It is working",
                                 QMessageBox::Ok);
    }
}

void Dialog::onBtnDownloadClicked()
{
    qDebug()<<"download";
    QString path = ui->lab_dir->text();
    QString caseId = ui->txt_caseId->text();

    NewDataSyncStatus status =  m_newDataSync->getStatus();
    if (status == NewDataSyncStatus::FREE)
    {
        m_downloadCount = 0;
        ui->progressBar->setValue(0);
        m_newDataSync->setOperateType(DOWNLOAD);
        m_newDataSync->start(caseId, path);
    }
    else
    {
        QMessageBox::information(this,
                                 "Information",
                                 "It is working",
                                 QMessageBox::Ok);
    }
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
