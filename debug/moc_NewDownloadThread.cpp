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
    QByteArrayData data[10];
    char stringdata0[179];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NewDownloadThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NewDownloadThread_t qt_meta_stringdata_NewDownloadThread = {
    {
QT_MOC_LITERAL(0, 0, 17), // "NewDownloadThread"
QT_MOC_LITERAL(1, 18, 24), // "downloadFileSuccessfully"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 27), // "downloadAllFileSuccessfully"
QT_MOC_LITERAL(4, 72, 18), // "downloadFileFailed"
QT_MOC_LITERAL(5, 91, 16), // "QList<FileStat>*"
QT_MOC_LITERAL(6, 108, 18), // "downloadFailedList"
QT_MOC_LITERAL(7, 127, 18), // "refreshProgressBar"
QT_MOC_LITERAL(8, 146, 15), // "onDownloadStart"
QT_MOC_LITERAL(9, 162, 16) // "downloadFileList"

    },
    "NewDownloadThread\0downloadFileSuccessfully\0"
    "\0downloadAllFileSuccessfully\0"
    "downloadFileFailed\0QList<FileStat>*\0"
    "downloadFailedList\0refreshProgressBar\0"
    "onDownloadStart\0downloadFileList"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NewDownloadThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    0,   40,    2, 0x06 /* Public */,
       4,    1,   41,    2, 0x06 /* Public */,
       7,    0,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   45,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5,    9,

       0        // eod
};

void NewDownloadThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        NewDownloadThread *_t = static_cast<NewDownloadThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->downloadFileSuccessfully(); break;
        case 1: _t->downloadAllFileSuccessfully(); break;
        case 2: _t->downloadFileFailed((*reinterpret_cast< QList<FileStat>*(*)>(_a[1]))); break;
        case 3: _t->refreshProgressBar(); break;
        case 4: _t->onDownloadStart((*reinterpret_cast< QList<FileStat>*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (NewDownloadThread::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NewDownloadThread::downloadFileSuccessfully)) {
                *result = 0;
            }
        }
        {
            typedef void (NewDownloadThread::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NewDownloadThread::downloadAllFileSuccessfully)) {
                *result = 1;
            }
        }
        {
            typedef void (NewDownloadThread::*_t)(QList<FileStat> * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NewDownloadThread::downloadFileFailed)) {
                *result = 2;
            }
        }
        {
            typedef void (NewDownloadThread::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NewDownloadThread::refreshProgressBar)) {
                *result = 3;
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
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void NewDownloadThread::downloadFileSuccessfully()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void NewDownloadThread::downloadAllFileSuccessfully()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void NewDownloadThread::downloadFileFailed(QList<FileStat> * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void NewDownloadThread::refreshProgressBar()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
