#include "FileCompare.h"
#include <QDir>
#include <QMessageBox>

FileCompare::FileCompare(SyncOperateType type, QString caseId, QString dirString)
{
}

QList<FileStat>* FileCompare::getLocalFile(QString caseId, QString dirString, SyncOperateType type)
{
    QDir dir(dirString);
    if (!dir.exists())
    {
        QMessageBox::warning(null,
                             "警告",
                             "目录不存在",
                             QMessageBox::Ok,
                             QMessageBox::Ok);
    }

    QFileInfo fileInfo = dir.entryInfoList(QDir::NoDotAndDotDot | QDir::Files | QDir::Dirs);
    QList<FileStat> list = new QList<FileStat>;

    for (int i = 0; i < fileInfo.size(); ++i)
    {
        QDebug()<<fileInfo[i];
    }
}

QList<FileStat>* FileCompare::makeFileCompare(SyncOperateType type, QList<FileStat> *local, QList<FileStat> *remote)
{

}
