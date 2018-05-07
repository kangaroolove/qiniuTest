#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    m_newDataSync = new NewDataSync;
}

Dialog::~Dialog()
{
    delete ui;
    delete m_newDataSync;
}
