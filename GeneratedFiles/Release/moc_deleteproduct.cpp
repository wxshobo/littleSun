/****************************************************************************
** Meta object code from reading C++ file 'deleteproduct.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../deleteproduct.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'deleteproduct.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_deleteproduct_t {
    QByteArrayData data[5];
    char stringdata0[69];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_deleteproduct_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_deleteproduct_t qt_meta_stringdata_deleteproduct = {
    {
QT_MOC_LITERAL(0, 0, 13), // "deleteproduct"
QT_MOC_LITERAL(1, 14, 13), // "deleteSuccess"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 19), // "deleteButtonClicked"
QT_MOC_LITERAL(4, 49, 19) // "cancelButtonClicked"

    },
    "deleteproduct\0deleteSuccess\0\0"
    "deleteButtonClicked\0cancelButtonClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_deleteproduct[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   30,    2, 0x08 /* Private */,
       4,    0,   31,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void deleteproduct::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        deleteproduct *_t = static_cast<deleteproduct *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->deleteSuccess(); break;
        case 1: _t->deleteButtonClicked(); break;
        case 2: _t->cancelButtonClicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (deleteproduct::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&deleteproduct::deleteSuccess)) {
                *result = 0;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject deleteproduct::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_deleteproduct.data,
      qt_meta_data_deleteproduct,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *deleteproduct::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *deleteproduct::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_deleteproduct.stringdata0))
        return static_cast<void*>(const_cast< deleteproduct*>(this));
    return QWidget::qt_metacast(_clname);
}

int deleteproduct::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void deleteproduct::deleteSuccess()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
