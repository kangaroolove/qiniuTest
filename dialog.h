#ifndef DIALOG_H
#define DIALOG_H

#include "NewDataSync.h"
#include <QDialog>

class NewDataSync;

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
public slots:
    void onFileUploadSuccessfully();
    void onAllFileUploadSuccessfully();
    void onFileUploadFailed(QList<FileStat> *uploadFailedList);
    void onProgressBarRefresh();
    void onFileDownloadSuccessfully();
    void onAllFileDownloadSuccessfully();
    void onFileDownloadFailed(QList<FileStat> *downloadFailedList);
    void onBtnUploadClicked();
    void onBtnDownloadClicked();
    void onBtnDirClicked();
    void onProgressBarMaxValueSet(int value, SyncOperateType type);
    void onUploadLatestSend();
    void onDownloadLatestSend();
private:
    Ui::Dialog *ui;
    NewDataSync *m_newDataSync;
    int m_uploadCount;
    int m_uploadSuccessfulCount;
    int m_downloadCount;
    int m_downloadSuccessfulCount;
};

#endif // DIALOG_H
