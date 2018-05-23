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
    char stringdata0[268];
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
QT_MOC_LITERAL(6, 63, 6), // "caseId"
QT_MOC_LITERAL(7, 70, 13), // "startDownload"
QT_MOC_LITERAL(8, 84, 16), // "downloadFileList"
QT_MOC_LITERAL(9, 101, 14), // "uploadFinished"
QT_MOC_LITERAL(10, 116, 16), // "uploadFailedList"
QT_MOC_LITERAL(11, 133, 16), // "downloadFinished"
QT_MOC_LITERAL(12, 150, 18), // "downloadFailedList"
QT_MOC_LITERAL(13, 169, 18), // "refreshProgressBar"
QT_MOC_LITERAL(14, 188, 22), // "setProgressBarMaxValue"
QT_MOC_LITERAL(15, 211, 15), // "SyncOperateType"
QT_MOC_LITERAL(16, 227, 4), // "type"
QT_MOC_LITERAL(17, 232, 16), // "onUploadFinished"
QT_MOC_LITERAL(18, 249, 18) // "onDownloadFinished"

    },
    "NewDataSync\0startUpload\0\0QList<FileStat>*\0"
    "uploadFileList\0token\0caseId\0startDownload\0"
    "downloadFileList\0uploadFinished\0"
    "uploadFailedList\0downloadFinished\0"
    "downloadFailedList\0refreshProgressBar\0"
    "setProgressBarMaxValue\0SyncOperateType\0"
    "type\0onUploadFinished\0onDownloadFinished"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NewDataSync[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   54,    2, 0x06 /* Public */,
       7,    1,   61,    2, 0x06 /* Public */,
       9,    1,   64,    2, 0x06 /* Public */,
      11,    1,   67,    2, 0x06 /* Public */,
      13,    0,   70,    2, 0x06 /* Public */,
      14,    2,   71,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      17,    1,   76,    2, 0x0a /* Public */,
      18,    1,   79,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString, QMetaType::QString,    4,    5,    6,
    QMetaType::Void, 0x80000000 | 3,    8,
    QMetaType::Void, 0x80000000 | 3,   10,
    QMetaType::Void, 0x80000000 | 3,   12,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 15,    2,   16,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,   10,
    QMetaType::Void, 0x80000000 | 3,   12,

       0        // eod
};

void NewDataSync::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        NewDataSync *_t = static_cast<NewDataSync *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->startUpload((*reinterpret_cast< QList<FileStat>*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 1: _t->startDownload((*reinterpret_cast< QList<FileStat>*(*)>(_a[1]))); break;
        case 2: _t->uploadFinished((*reinterpret_cast< QList<FileStat>*(*)>(_a[1]))); break;
        case 3: _t->downloadFinished((*reinterpret_cast< QList<FileStat>*(*)>(_a[1]))); break;
        case 4: _t->refreshProgressBar(); break;
        case 5: _t->setProgressBarMaxValue((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< SyncOperateType(*)>(_a[2]))); break;
        case 6: _t->onUploadFinished((*reinterpret_cast< QList<FileStat>*(*)>(_a[1]))); break;
        case 7: _t->onDownloadFinished((*reinterpret_cast< QList<FileStat>*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (NewDataSync::*_t)(QList<FileStat> * , QString , QString );
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
            typedef void (NewDataSync::*_t)(QList<FileStat> * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NewDataSync::downloadFinished)) {
                *result = 3;
            }
        }
        {
            typedef void (NewDataSync::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NewDataSync::refreshProgressBar)) {
                *result = 4;
            }
        }
        {
            typedef void (NewDataSync::*_t)(int , SyncOperateType );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NewDataSync::setProgressBarMaxValue)) {
                *result = 5;
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
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void NewDataSync::startUpload(QList<FileStat> * _t1, QString _t2, QString _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
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
void NewDataSync::downloadFinished(QList<FileStat> * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void NewDataSync::refreshProgressBar()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void NewDataSync::setProgressBarMaxValue(int _t1, SyncOperateType _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_END_MOC_NAMESPACE
