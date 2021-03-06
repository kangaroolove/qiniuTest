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
    void onUploadFinished(QList<FileStat> *uploadFailedList);
    void onDownloadFinished(QList<FileStat> *downloadFailedList);
    void onProgressBarRefresh();
    void onBtnUploadClicked();
    void onBtnDownloadClicked();
    void onBtnDirClicked();
    void onProgressBarMaxValueSet(int value, SyncOperateType type);
private:
    Ui::Dialog *ui;
    NewDataSync *m_newDataSync;
    int m_uploadCount;
    int m_downloadCount;
    int m_downloadSuccessfulCount;
};

#endif // DIALOG_H
