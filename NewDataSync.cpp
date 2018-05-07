#include "NewDataSync.h"

NewDataSync::NewDataSync()
{
    QString dir("C:/Users/pangkuanxin/Desktop/abc");
    m_fileCompare = new FileCompare;
    m_localList = m_fileCompare->getLocalFile("FT1JN3PC", dir, SyncOperateType::NO);
}

NewDataSync::~NewDataSync()
{
    delete m_fileCompare;
}

