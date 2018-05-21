/****************************************************************************
** Meta object code from reading C++ file 'NewDownloadThread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../NewDownloadThread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'NewDownloadThread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_NewDownloadThread_t {
    QByteArrayData data[12];
    char stringdata0[173];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NewDownloadThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NewDownloadThread_t qt_meta_stringdata_NewDownloadThread = {
    {
QT_MOC_LITERAL(0, 0, 17), // "NewDownloadThread"
QT_MOC_LITERAL(1, 18, 16), // "downloadFinished"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 16), // "QList<FileStat>*"
QT_MOC_LITERAL(4, 53, 18), // "downloadFailedList"
QT_MOC_LITERAL(5, 72, 18), // "refreshProgressBar"
QT_MOC_LITERAL(6, 91, 18), // "onDownloadFinished"
QT_MOC_LITERAL(7, 110, 10), // "successful"
QT_MOC_LITERAL(8, 121, 9), // "FileStat*"
QT_MOC_LITERAL(9, 131, 8), // "fileStat"
QT_MOC_LITERAL(10, 140, 15), // "onDownloadStart"
QT_MOC_LITERAL(11, 156, 16) // "downloadFileList"

    },
    "NewDownloadThread\0downloadFinished\0\0"
    "QList<FileStat>*\0downloadFailedList\0"
    "refreshProgressBar\0onDownloadFinished\0"
    "successful\0FileStat*\0fileStat\0"
    "onDownloadStart\0downloadFileList"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NewDownloadThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       5,    0,   37,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    2,   38,    2, 0x0a /* Public */,
      10,    1,   43,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool, 0x80000000 | 8,    7,    9,
    QMetaType::Void, 0x80000000 | 3,   11,

       0        // eod
};

void NewDownloadThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        NewDownloadThread *_t = static_cast<NewDownloadThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->downloadFinished((*reinterpret_cast< QList<FileStat>*(*)>(_a[1]))); break;
        case 1: _t->refreshProgressBar(); break;
        case 2: _t->onDownloadFinished((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< FileStat*(*)>(_a[2]))); break;
        case 3: _t->onDownloadStart((*reinterpret_cast< QList<FileStat>*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (NewDownloadThread::*_t)(QList<FileStat> * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NewDownloadThread::downloadFinished)) {
                *result = 0;
            }
        }
        {
            typedef void (NewDownloadThread::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NewDownloadThread::refreshProgressBar)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject NewDownloadThread::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_NewDownloadThread.data,
      qt_meta_data_NewDownloadThread,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *NewDownloadThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NewDownloadThread::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_NewDownloadThread.stringdata0))
        return static_cast<void*>(const_cast< NewDownloadThread*>(this));
    return QObject::qt_metacast(_clname);
}

int NewDownloadThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void NewDownloadThread::downloadFinished(QList<FileStat> * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void NewDownloadThread::refreshProgressBar()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
