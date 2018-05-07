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

private:
    Ui::Dialog *ui;
    NewDataSync *m_newDataSync;
};

#endif // DIALOG_H
