/****************************************************************************
** Meta object code from reading C++ file 'DownloadTask.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../DownloadTask.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DownloadTask.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_DownloadTask_t {
    QByteArrayData data[8];
    char stringdata0[124];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DownloadTask_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DownloadTask_t qt_meta_stringdata_DownloadTask = {
    {
QT_MOC_LITERAL(0, 0, 12), // "DownloadTask"
QT_MOC_LITERAL(1, 13, 24), // "downloadFileSuccessfully"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 27), // "downloadAllFileSuccessfully"
QT_MOC_LITERAL(4, 67, 18), // "downloadFileFailed"
QT_MOC_LITERAL(5, 86, 9), // "FileStat&"
QT_MOC_LITERAL(6, 96, 8), // "fileStat"
QT_MOC_LITERAL(7, 105, 18) // "refreshProgressBar"

    },
    "DownloadTask\0downloadFileSuccessfully\0"
    "\0downloadAllFileSuccessfully\0"
    "downloadFileFailed\0FileStat&\0fileStat\0"
    "refreshProgressBar"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DownloadTask[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,
       3,    0,   35,    2, 0x06 /* Public */,
       4,    1,   36,    2, 0x06 /* Public */,
       7,    0,   39,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,

       0        // eod
};

void DownloadTask::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DownloadTask *_t = static_cast<DownloadTask *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->downloadFileSuccessfully(); break;
        case 1: _t->downloadAllFileSuccessfully(); break;
        case 2: _t->downloadFileFailed((*reinterpret_cast< FileStat(*)>(_a[1]))); break;
        case 3: _t->refreshProgressBar(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (DownloadTask::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DownloadTask::downloadFileSuccessfully)) {
                *result = 0;
            }
        }
        {
            typedef void (DownloadTask::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DownloadTask::downloadAllFileSuccessfully)) {
                *result = 1;
            }
        }
        {
            typedef void (DownloadTask::*_t)(FileStat & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DownloadTask::downloadFileFailed)) {
                *result = 2;
            }
        }
        {
            typedef void (DownloadTask::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DownloadTask::refreshProgressBar)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject DownloadTask::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_DownloadTask.data,
      qt_meta_data_DownloadTask,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *DownloadTask::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DownloadTask::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_DownloadTask.stringdata0))
        return static_cast<void*>(const_cast< DownloadTask*>(this));
    if (!strcmp(_clname, "QRunnable"))
        return static_cast< QRunnable*>(const_cast< DownloadTask*>(this));
    return QObject::qt_metacast(_clname);
}

int DownloadTask::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void DownloadTask::downloadFileSuccessfully()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void DownloadTask::downloadAllFileSuccessfully()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void DownloadTask::downloadFileFailed(FileStat & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void DownloadTask::refreshProgressBar()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
