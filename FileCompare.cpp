#include "FileCompare.h"

FileCompare::FileCompare()
{
}


QList<FileStat>* FileCompare::makeFileCompare(SyncOperateType type, QList<FileStat> *local, QList<FileStat> *remote)
{
    switch (type)
    {
        case SyncOperateType::NO:
            return NULL;
        case SyncOperateType::UPLOAD:
            return getUploadList(local, remote);
        case SyncOperateType::DOWNLOAD:
            return getDownloadList(local, remote);
        default:
            return NULL;
    }
}

QList<FileStat> *FileCompare::getUploadList(QList<FileStat> *local, QList<FileStat> *remote)
{
    QList<FileStat> *uploadList = new QList<FileStat>;
    for (int i = 0; i < local->size(); ++i)
    {
        for (int j = 0; j < remote->size(); ++j)
        {

        }
    }

    return uploadList;
}

QList<FileStat> *FileCompare::getDownloadList(QList<FileStat> *local, QList<FileStat> *remote)
{
    QList<FileStat> *downloadList = new QList<FileStat>;
    for (int i = 0; i < remote->size(); ++i)
    {
        for (int j = 0; j < local->size(); ++j)
        {

        }
    }

    return downloadList;
}
