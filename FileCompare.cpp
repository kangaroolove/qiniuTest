#include "FileCompare.h"
#include <QDirIterator>
#include <QMessageBox>
#include <QDebug>

FileCompare::FileCompare()
{
}

QList<FileStat>* FileCompare::getLocalFile(QString caseId, QString path, SyncOperateType type)
{
    QDir dir(path);
    if (!dir.exists())
    {
    }

    QStringList list = path.split("/");
    qDebug()<<list.last();

    QList<FileStat> *localList = new QList<FileStat>;
    FileStat fileStatItem;

    QDirIterator it(path,
                    QDir::NoDotAndDotDot | QDir::NoSymLinks | QDir::Files,
                    QDirIterator::Subdirectories);
    while (it.hasNext())
    {
        it.next();
        qDebug()<<it.fileInfo().absoluteFilePath();
        fileStatItem.fileUrl = getFileUrl(it.fileInfo().absoluteFilePath(), caseId, list.last());
        fileStatItem.createTime = it.fileInfo().created();
        fileStatItem.updateTime = it.fileInfo().lastModified();
    }

    return localList;
}

QString FileCompare::getFileUrl(const QString& fileName, const QString& caseId, const QString& dir)
{
//    QStringList list = fileName.split(dir);
//    for (int i = 0; i < list.size(); ++i)
//    {
//        qDebug()<<list[i];
//    }
    QString caseToUpper = caseId.toUpper();

    int position = fileName.indexOf(dir);
    QString temp = fileName;
    qDebug()<<"position"<<position;
    temp.remove(0, position);
    temp.replace(dir, caseToUpper);
    qDebug()<<temp;
//    fileUrl.append(caseToUpper);
//    fileUrl.append("/");

    //qDebug()<<fileUrl;

    return fileName;
}

/*
QList<FileStat>* FileCompare::makeFileCompare(SyncOperateType type, QList<FileStat> *local, QList<FileStat> *remote)
{

}*/
