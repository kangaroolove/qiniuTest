#include "dialog.h"
#include "ui_dialog.h"
#include <QMessageBox>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    m_newDataSync = new NewDataSync;
    connect(m_newDataSync, SIGNAL(uploadedFile()), this, SLOT(onFileUploaded()));
    connect(m_newDataSync, SIGNAL(uploadAllFileSuccessfully()), this, SLOT(onAllFileUploadSuccessfully()));
    connect(m_newDataSync, SIGNAL(uploadFileFailed(QList<FileStat>*)), this, SLOT(onFileUploadFailed(QList<FileStat>*)));
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

void Dialog::onFileUploaded()
{

}

void Dialog::onAllFileUploadSuccessfully()
{

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
