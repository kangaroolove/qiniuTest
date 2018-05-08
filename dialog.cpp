#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    m_newDataSync = new NewDataSync;
    m_newDataSync->start();
}

Dialog::~Dialog()
{
    delete ui;
    delete m_newDataSync;
}
