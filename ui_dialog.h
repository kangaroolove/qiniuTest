/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QGridLayout *gridLayout;
    QProgressBar *progressBar;
    QLabel *lab_dir;
    QLineEdit *txt_caseId;
    QLabel *label_2;
    QLabel *label;
    QPushButton *btn_dir;
    QPushButton *btn_download;
    QPushButton *btn_upload;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(354, 116);
        gridLayout = new QGridLayout(Dialog);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        progressBar = new QProgressBar(Dialog);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(0);

        gridLayout->addWidget(progressBar, 2, 0, 1, 5);

        lab_dir = new QLabel(Dialog);
        lab_dir->setObjectName(QStringLiteral("lab_dir"));
        lab_dir->setStyleSheet(QLatin1String("QPushButton{\n"
"border: 1px solid #E7E8EA;\n"
"border-radius: 4px;\n"
"}"));

        gridLayout->addWidget(lab_dir, 1, 1, 1, 4);

        txt_caseId = new QLineEdit(Dialog);
        txt_caseId->setObjectName(QStringLiteral("txt_caseId"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(txt_caseId->sizePolicy().hasHeightForWidth());
        txt_caseId->setSizePolicy(sizePolicy);

        gridLayout->addWidget(txt_caseId, 0, 1, 1, 3);

        label_2 = new QLabel(Dialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label = new QLabel(Dialog);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        btn_dir = new QPushButton(Dialog);
        btn_dir->setObjectName(QStringLiteral("btn_dir"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(btn_dir->sizePolicy().hasHeightForWidth());
        btn_dir->setSizePolicy(sizePolicy2);
        btn_dir->setMinimumSize(QSize(23, 23));
        btn_dir->setMaximumSize(QSize(23, 23));
        btn_dir->setStyleSheet(QLatin1String("QPushButton{\n"
"border:0px;\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resource/\346\226\207\344\273\266\345\244\271.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_dir->setIcon(icon);
        btn_dir->setIconSize(QSize(23, 23));

        gridLayout->addWidget(btn_dir, 0, 4, 1, 1);

        btn_download = new QPushButton(Dialog);
        btn_download->setObjectName(QStringLiteral("btn_download"));

        gridLayout->addWidget(btn_download, 4, 3, 1, 1);

        btn_upload = new QPushButton(Dialog);
        btn_upload->setObjectName(QStringLiteral("btn_upload"));

        gridLayout->addWidget(btn_upload, 4, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(50, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 4, 2, 1, 1);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0));
        lab_dir->setText(QString());
#ifndef QT_NO_TOOLTIP
        txt_caseId->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        txt_caseId->setPlaceholderText(QApplication::translate("Dialog", "\350\257\267\350\276\223\345\205\245\344\270\200\344\270\252\347\227\205\345\216\206\345\217\267", 0));
        label_2->setText(QApplication::translate("Dialog", "\347\233\256\345\275\225\357\274\232", 0));
        label->setText(QApplication::translate("Dialog", "\347\227\205\345\216\206\345\217\267\357\274\232", 0));
        btn_download->setText(QApplication::translate("Dialog", "\344\270\213\350\275\275", 0));
        btn_upload->setText(QApplication::translate("Dialog", "\344\270\212\344\274\240", 0));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
