#ifndef FILESTAT_H
#define FILESTAT_H

#include <QString>
#include <QDateTime>

#define DATE_TIME_FOMAT   "yyyy-MM-dd,hh-mm-ss"

enum FileType
{
    OTHER_FILE = 0,
    BASE_DATA,
    MEASURE_DATA,
    WEB_UP_STL,
    WEB_LOW_STL,
    WEB_ATTACHMENT_FIRST_FILE,
    WEB_ATTACHMENT_SECOND_FILE,
    WEB_ATTACHMENT_THIRD_FILE,
    PDF,
    FACE_FRONTAL,
    FACE_FRONTAL_SMILE,
    FACE_RIGHT_45_DEGREES,
    FACE_RIGHT_90_DEGREES,
    MOUTH_FRONTAL,
    MOUTH_UP,
    MOUTH_DOWN,
    MOUTH_LEFT,
    MOUTH_RIGHT,
    X_RAY_FRONTAL,
    X_RAY_PROFILE,
    TOOTH_RTD,
    TOOTH_RTTSD,
    TOOTH_SRTD,
    COMPRESSED_UPPER_STL,
    COMPRESSED_LOWER_STL,
    ANGLE_CAL_BOW_DATA,
    CDU_TEETH_WIDTH_DATA,
    CDU_CREATE_TEETH_BASE,
    DENTAL_ARCH_DATA,
    ENVIRONMENT_STATE_BEFORE_CLOSE,
    OCCLUSAL_PLANE_DATA,
    LOWER_RTP,
    UPPER_RTP,
    CDU_ENVIRONMENT_STATE_SAVE,
};

class FileStat
{
public:
    FileStat();
    // 不带路径的文件名
    QString fileName;
    // web端的命名方式
    QString webName;
    // 文件路径
    QString filePath;
    QDateTime createTime;
    QDateTime updateTime;
    QByteArray hash;
    // 对于上传是带路径、fileType、uuid,对于下载就是下载的url
    QString fileUrl;
    int fileType;
    int errorCode;
};

#endif // FILESTAT_H
