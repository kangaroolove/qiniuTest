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
    QByteArrayData data[7];
    char stringdata0[80];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DownloadTask_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DownloadTask_t qt_meta_stringdata_DownloadTask = {
    {
QT_MOC_LITERAL(0, 0, 12), // "DownloadTask"
QT_MOC_LITERAL(1, 13, 18), // "refreshProgressBar"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 16), // "downloadFinished"
QT_MOC_LITERAL(4, 50, 10), // "successful"
QT_MOC_LITERAL(5, 61, 9), // "FileStat*"
QT_MOC_LITERAL(6, 71, 8) // "fileStat"

    },
    "DownloadTask\0refreshProgressBar\0\0"
    "downloadFinished\0successful\0FileStat*\0"
    "fileStat"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DownloadTask[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x06 /* Public */,
       3,    2,   30,    2, 0x06 /* Public */,
       3,    1,   35,    2, 0x26 /* Public | MethodCloned */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool, 0x80000000 | 5,    4,    6,
    QMetaType::Void, QMetaType::Bool,    4,

       0        // eod
};

void DownloadTask::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DownloadTask *_t = static_cast<DownloadTask *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->refreshProgressBar(); break;
        case 1: _t->downloadFinished((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< FileStat*(*)>(_a[2]))); break;
        case 2: _t->downloadFinished((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (DownloadTask::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DownloadTask::refreshProgressBar)) {
                *result = 0;
            }
        }
        {
            typedef void (DownloadTask::*_t)(bool , FileStat * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DownloadTask::downloadFinished)) {
                *result = 1;
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
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void DownloadTask::refreshProgressBar()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void DownloadTask::downloadFinished(bool _t1, FileStat * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
