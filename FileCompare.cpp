#include "FileCompare.h"

FileCompare::FileCompare()
{
}


QList<FileStat>* FileCompare::makeFileCompare(SyncOperateType type, QList<FileStat> *local, QList<FileStat> *remote)
{
    if ((local == NULL) || (remote == NULL))
    {
        return NULL;
    }

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
    bool isContain = false;
    int i;
    int j;

    for (i = 0; i < local->size(); ++i)
    {
        for (j = 0; j < remote->size(); ++j)
        {
            if (local->at(i).fileName == remote->at(j).fileName)
            {
                isContain = true;
                break;
            }
        }
        if (isContain == true)
        {
            if (local->at(i).updateTime > remote->at(j).updateTime)
            {
                uploadList->push_back(local->at(i));
                remote->removeAt(j);
            }
        }
        else
        {
            if (local->at(i).fileType != FileType::OTHER_FILE)
            {
                uploadList->push_back(local->at(i));
            }
        }
        isContain = false;
    }

    return uploadList;
}

QList<FileStat> *FileCompare::getDownloadList(QList<FileStat> *local, QList<FileStat> *remote)
{
    QList<FileStat> *downloadList = new QList<FileStat>;
    bool isContain = false;
    int i;
    int j;
    for (i = 0; i < remote->size(); ++i)
    {
        for (j = 0; j < local->size(); ++j)
        {
            if (remote->at(i).fileName == local->at(j).fileName)
            {
                isContain = true;
                break;
            }
        }
        if (isContain == true)
        {
            if (remote->at(i).updateTime > local->at(j).updateTime)
            {
                downloadList->push_back(remote->at(i));
                local->removeAt(j);
            }
        }
        else
        {
            if (remote->at(i).fileType != FileType::OTHER_FILE)
            {
                downloadList->push_back(remote->at(i));
            }
        }
        isContain = false;
    }

    return downloadList;
}
