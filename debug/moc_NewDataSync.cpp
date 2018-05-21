/****************************************************************************
** Meta object code from reading C++ file 'NewDataSync.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../NewDataSync.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'NewDataSync.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_NewDataSync_t {
    QByteArrayData data[19];
    char stringdata0[297];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NewDataSync_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NewDataSync_t qt_meta_stringdata_NewDataSync = {
    {
QT_MOC_LITERAL(0, 0, 11), // "NewDataSync"
QT_MOC_LITERAL(1, 12, 11), // "startUpload"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 16), // "QList<FileStat>*"
QT_MOC_LITERAL(4, 42, 14), // "uploadFileList"
QT_MOC_LITERAL(5, 57, 5), // "token"
QT_MOC_LITERAL(6, 63, 13), // "startDownload"
QT_MOC_LITERAL(7, 77, 16), // "downloadFileList"
QT_MOC_LITERAL(8, 94, 14), // "uploadFinished"
QT_MOC_LITERAL(9, 109, 16), // "uploadFailedList"
QT_MOC_LITERAL(10, 126, 24), // "downloadFileSuccessfully"
QT_MOC_LITERAL(11, 151, 27), // "downloadAllFileSuccessfully"
QT_MOC_LITERAL(12, 179, 18), // "downloadFileFailed"
QT_MOC_LITERAL(13, 198, 18), // "refreshProgressBar"
QT_MOC_LITERAL(14, 217, 22), // "setProgressBarMaxValue"
QT_MOC_LITERAL(15, 240, 15), // "SyncOperateType"
QT_MOC_LITERAL(16, 256, 4), // "type"
QT_MOC_LITERAL(17, 261, 16), // "sendUploadLatest"
QT_MOC_LITERAL(18, 278, 18) // "sendDownloadLatest"

    },
    "NewDataSync\0startUpload\0\0QList<FileStat>*\0"
    "uploadFileList\0token\0startDownload\0"
    "downloadFileList\0uploadFinished\0"
    "uploadFailedList\0downloadFileSuccessfully\0"
    "downloadAllFileSuccessfully\0"
    "downloadFileFailed\0refreshProgressBar\0"
    "setProgressBarMaxValue\0SyncOperateType\0"
    "type\0sendUploadLatest\0sendDownloadLatest"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NewDataSync[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   64,    2, 0x06 /* Public */,
       6,    1,   69,    2, 0x06 /* Public */,
       8,    1,   72,    2, 0x06 /* Public */,
      10,    0,   75,    2, 0x06 /* Public */,
      11,    0,   76,    2, 0x06 /* Public */,
      12,    1,   77,    2, 0x06 /* Public */,
      13,    0,   80,    2, 0x06 /* Public */,
      14,    2,   81,    2, 0x06 /* Public */,
      17,    0,   86,    2, 0x06 /* Public */,
      18,    0,   87,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString,    4,    5,
    QMetaType::Void, 0x80000000 | 3,    7,
    QMetaType::Void, 0x80000000 | 3,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    9,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 15,    2,   16,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void NewDataSync::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        NewDataSync *_t = static_cast<NewDataSync *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->startUpload((*reinterpret_cast< QList<FileStat>*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->startDownload((*reinterpret_cast< QList<FileStat>*(*)>(_a[1]))); break;
        case 2: _t->uploadFinished((*reinterpret_cast< QList<FileStat>*(*)>(_a[1]))); break;
        case 3: _t->downloadFileSuccessfully(); break;
        case 4: _t->downloadAllFileSuccessfully(); break;
        case 5: _t->downloadFileFailed((*reinterpret_cast< QList<FileStat>*(*)>(_a[1]))); break;
        case 6: _t->refreshProgressBar(); break;
        case 7: _t->setProgressBarMaxValue((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< SyncOperateType(*)>(_a[2]))); break;
        case 8: _t->sendUploadLatest(); break;
        case 9: _t->sendDownloadLatest(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (NewDataSync::*_t)(QList<FileStat> * , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NewDataSync::startUpload)) {
                *result = 0;
            }
        }
        {
            typedef void (NewDataSync::*_t)(QList<FileStat> * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NewDataSync::startDownload)) {
                *result = 1;
            }
        }
        {
            typedef void (NewDataSync::*_t)(QList<FileStat> * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NewDataSync::uploadFinished)) {
                *result = 2;
            }
        }
        {
            typedef void (NewDataSync::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NewDataSync::downloadFileSuccessfully)) {
                *result = 3;
            }
        }
        {
            typedef void (NewDataSync::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NewDataSync::downloadAllFileSuccessfully)) {
                *result = 4;
            }
        }
        {
            typedef void (NewDataSync::*_t)(QList<FileStat> * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NewDataSync::downloadFileFailed)) {
                *result = 5;
            }
        }
        {
            typedef void (NewDataSync::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NewDataSync::refreshProgressBar)) {
                *result = 6;
            }
        }
        {
            typedef void (NewDataSync::*_t)(int , SyncOperateType );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NewDataSync::setProgressBarMaxValue)) {
                *result = 7;
            }
        }
        {
            typedef void (NewDataSync::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NewDataSync::sendUploadLatest)) {
                *result = 8;
            }
        }
        {
            typedef void (NewDataSync::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NewDataSync::sendDownloadLatest)) {
                *result = 9;
            }
        }
    }
}

const QMetaObject NewDataSync::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_NewDataSync.data,
      qt_meta_data_NewDataSync,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *NewDataSync::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NewDataSync::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_NewDataSync.stringdata0))
        return static_cast<void*>(const_cast< NewDataSync*>(this));
    return QObject::qt_metacast(_clname);
}

int NewDataSync::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void NewDataSync::startUpload(QList<FileStat> * _t1, QString _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void NewDataSync::startDownload(QList<FileStat> * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void NewDataSync::uploadFinished(QList<FileStat> * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void NewDataSync::downloadFileSuccessfully()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void NewDataSync::downloadAllFileSuccessfully()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void NewDataSync::downloadFileFailed(QList<FileStat> * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void NewDataSync::refreshProgressBar()
{
    QMetaObject::activate(this, &staticMetaObject, 6, Q_NULLPTR);
}

// SIGNAL 7
void NewDataSync::setProgressBarMaxValue(int _t1, SyncOperateType _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void NewDataSync::sendUploadLatest()
{
    QMetaObject::activate(this, &staticMetaObject, 8, Q_NULLPTR);
}

// SIGNAL 9
void NewDataSync::sendDownloadLatest()
{
    QMetaObject::activate(this, &staticMetaObject, 9, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
