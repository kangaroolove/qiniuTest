/****************************************************************************
** Meta object code from reading C++ file 'NewUploadThread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../NewUploadThread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'NewUploadThread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_NewUploadThread_t {
    QByteArrayData data[12];
    char stringdata0[180];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NewUploadThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NewUploadThread_t qt_meta_stringdata_NewUploadThread = {
    {
QT_MOC_LITERAL(0, 0, 15), // "NewUploadThread"
QT_MOC_LITERAL(1, 16, 22), // "uploadFileSuccessfully"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 25), // "uploadAllFileSuccessfully"
QT_MOC_LITERAL(4, 66, 16), // "uploadFileFailed"
QT_MOC_LITERAL(5, 83, 16), // "QList<FileStat>*"
QT_MOC_LITERAL(6, 100, 16), // "uploadFailedList"
QT_MOC_LITERAL(7, 117, 18), // "refreshProgressBar"
QT_MOC_LITERAL(8, 136, 13), // "onUploadStart"
QT_MOC_LITERAL(9, 150, 14), // "uploadFileList"
QT_MOC_LITERAL(10, 165, 8), // "QString&"
QT_MOC_LITERAL(11, 174, 5) // "token"

    },
    "NewUploadThread\0uploadFileSuccessfully\0"
    "\0uploadAllFileSuccessfully\0uploadFileFailed\0"
    "QList<FileStat>*\0uploadFailedList\0"
    "refreshProgressBar\0onUploadStart\0"
    "uploadFileList\0QString&\0token"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NewUploadThread[] = {

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
       8,    2,   45,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 10,    9,   11,

       0        // eod
};

void NewUploadThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        NewUploadThread *_t = static_cast<NewUploadThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->uploadFileSuccessfully(); break;
        case 1: _t->uploadAllFileSuccessfully(); break;
        case 2: _t->uploadFileFailed((*reinterpret_cast< QList<FileStat>*(*)>(_a[1]))); break;
        case 3: _t->refreshProgressBar(); break;
        case 4: _t->onUploadStart((*reinterpret_cast< QList<FileStat>*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (NewUploadThread::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NewUploadThread::uploadFileSuccessfully)) {
                *result = 0;
            }
        }
        {
            typedef void (NewUploadThread::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NewUploadThread::uploadAllFileSuccessfully)) {
                *result = 1;
            }
        }
        {
            typedef void (NewUploadThread::*_t)(QList<FileStat> * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NewUploadThread::uploadFileFailed)) {
                *result = 2;
            }
        }
        {
            typedef void (NewUploadThread::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NewUploadThread::refreshProgressBar)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject NewUploadThread::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_NewUploadThread.data,
      qt_meta_data_NewUploadThread,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *NewUploadThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NewUploadThread::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_NewUploadThread.stringdata0))
        return static_cast<void*>(const_cast< NewUploadThread*>(this));
    return QObject::qt_metacast(_clname);
}

int NewUploadThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void NewUploadThread::uploadFileSuccessfully()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void NewUploadThread::uploadAllFileSuccessfully()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void NewUploadThread::uploadFileFailed(QList<FileStat> * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void NewUploadThread::refreshProgressBar()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE