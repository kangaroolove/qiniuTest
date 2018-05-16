/****************************************************************************
** Meta object code from reading C++ file 'dialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../dialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Dialog_t {
    QByteArrayData data[21];
    char stringdata0[380];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Dialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Dialog_t qt_meta_stringdata_Dialog = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Dialog"
QT_MOC_LITERAL(1, 7, 24), // "onFileUploadSuccessfully"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 27), // "onAllFileUploadSuccessfully"
QT_MOC_LITERAL(4, 61, 18), // "onFileUploadFailed"
QT_MOC_LITERAL(5, 80, 16), // "QList<FileStat>*"
QT_MOC_LITERAL(6, 97, 16), // "uploadFailedList"
QT_MOC_LITERAL(7, 114, 20), // "onProgressBarRefresh"
QT_MOC_LITERAL(8, 135, 26), // "onFileDownloadSuccessfully"
QT_MOC_LITERAL(9, 162, 29), // "onAllFileDownloadSuccessfully"
QT_MOC_LITERAL(10, 192, 20), // "onFileDownloadFailed"
QT_MOC_LITERAL(11, 213, 18), // "downloadFailedList"
QT_MOC_LITERAL(12, 232, 18), // "onBtnUploadClicked"
QT_MOC_LITERAL(13, 251, 20), // "onBtnDownloadClicked"
QT_MOC_LITERAL(14, 272, 15), // "onBtnDirClicked"
QT_MOC_LITERAL(15, 288, 24), // "onProgressBarMaxValueSet"
QT_MOC_LITERAL(16, 313, 5), // "value"
QT_MOC_LITERAL(17, 319, 15), // "SyncOperateType"
QT_MOC_LITERAL(18, 335, 4), // "type"
QT_MOC_LITERAL(19, 340, 18), // "onUploadLatestSend"
QT_MOC_LITERAL(20, 359, 20) // "onDownloadLatestSend"

    },
    "Dialog\0onFileUploadSuccessfully\0\0"
    "onAllFileUploadSuccessfully\0"
    "onFileUploadFailed\0QList<FileStat>*\0"
    "uploadFailedList\0onProgressBarRefresh\0"
    "onFileDownloadSuccessfully\0"
    "onAllFileDownloadSuccessfully\0"
    "onFileDownloadFailed\0downloadFailedList\0"
    "onBtnUploadClicked\0onBtnDownloadClicked\0"
    "onBtnDirClicked\0onProgressBarMaxValueSet\0"
    "value\0SyncOperateType\0type\0"
    "onUploadLatestSend\0onDownloadLatestSend"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Dialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x0a /* Public */,
       3,    0,   80,    2, 0x0a /* Public */,
       4,    1,   81,    2, 0x0a /* Public */,
       7,    0,   84,    2, 0x0a /* Public */,
       8,    0,   85,    2, 0x0a /* Public */,
       9,    0,   86,    2, 0x0a /* Public */,
      10,    1,   87,    2, 0x0a /* Public */,
      12,    0,   90,    2, 0x0a /* Public */,
      13,    0,   91,    2, 0x0a /* Public */,
      14,    0,   92,    2, 0x0a /* Public */,
      15,    2,   93,    2, 0x0a /* Public */,
      19,    0,   98,    2, 0x0a /* Public */,
      20,    0,   99,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 17,   16,   18,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Dialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Dialog *_t = static_cast<Dialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onFileUploadSuccessfully(); break;
        case 1: _t->onAllFileUploadSuccessfully(); break;
        case 2: _t->onFileUploadFailed((*reinterpret_cast< QList<FileStat>*(*)>(_a[1]))); break;
        case 3: _t->onProgressBarRefresh(); break;
        case 4: _t->onFileDownloadSuccessfully(); break;
        case 5: _t->onAllFileDownloadSuccessfully(); break;
        case 6: _t->onFileDownloadFailed((*reinterpret_cast< QList<FileStat>*(*)>(_a[1]))); break;
        case 7: _t->onBtnUploadClicked(); break;
        case 8: _t->onBtnDownloadClicked(); break;
        case 9: _t->onBtnDirClicked(); break;
        case 10: _t->onProgressBarMaxValueSet((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< SyncOperateType(*)>(_a[2]))); break;
        case 11: _t->onUploadLatestSend(); break;
        case 12: _t->onDownloadLatestSend(); break;
        default: ;
        }
    }
}

const QMetaObject Dialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Dialog.data,
      qt_meta_data_Dialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Dialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Dialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Dialog.stringdata0))
        return static_cast<void*>(const_cast< Dialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int Dialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
