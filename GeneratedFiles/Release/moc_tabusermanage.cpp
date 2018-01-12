/****************************************************************************
** Meta object code from reading C++ file 'tabusermanage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../tabusermanage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tabusermanage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_TabUserManage_t {
    QByteArrayData data[16];
    char stringdata0[196];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TabUserManage_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TabUserManage_t qt_meta_stringdata_TabUserManage = {
    {
QT_MOC_LITERAL(0, 0, 13), // "TabUserManage"
QT_MOC_LITERAL(1, 14, 13), // "userfirstSlot"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 16), // "userpreviousSlot"
QT_MOC_LITERAL(4, 46, 12), // "usernextSlot"
QT_MOC_LITERAL(5, 59, 12), // "userlastSlot"
QT_MOC_LITERAL(6, 72, 11), // "useraddSlot"
QT_MOC_LITERAL(7, 84, 14), // "userdeleteSlot"
QT_MOC_LITERAL(8, 99, 14), // "userreviseSlot"
QT_MOC_LITERAL(9, 114, 13), // "onCellClicked"
QT_MOC_LITERAL(10, 128, 3), // "row"
QT_MOC_LITERAL(11, 132, 3), // "col"
QT_MOC_LITERAL(12, 136, 20), // "onRadioButtonClicked"
QT_MOC_LITERAL(13, 157, 10), // "addfreshen"
QT_MOC_LITERAL(14, 168, 13), // "deletefreshen"
QT_MOC_LITERAL(15, 182, 13) // "revisefreshen"

    },
    "TabUserManage\0userfirstSlot\0\0"
    "userpreviousSlot\0usernextSlot\0"
    "userlastSlot\0useraddSlot\0userdeleteSlot\0"
    "userreviseSlot\0onCellClicked\0row\0col\0"
    "onRadioButtonClicked\0addfreshen\0"
    "deletefreshen\0revisefreshen"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TabUserManage[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x08 /* Private */,
       3,    0,   75,    2, 0x08 /* Private */,
       4,    0,   76,    2, 0x08 /* Private */,
       5,    0,   77,    2, 0x08 /* Private */,
       6,    0,   78,    2, 0x08 /* Private */,
       7,    0,   79,    2, 0x08 /* Private */,
       8,    0,   80,    2, 0x08 /* Private */,
       9,    2,   81,    2, 0x08 /* Private */,
      12,    1,   86,    2, 0x08 /* Private */,
      13,    0,   89,    2, 0x08 /* Private */,
      14,    0,   90,    2, 0x08 /* Private */,
      15,    0,   91,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   10,   11,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TabUserManage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TabUserManage *_t = static_cast<TabUserManage *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->userfirstSlot(); break;
        case 1: _t->userpreviousSlot(); break;
        case 2: _t->usernextSlot(); break;
        case 3: _t->userlastSlot(); break;
        case 4: _t->useraddSlot(); break;
        case 5: _t->userdeleteSlot(); break;
        case 6: _t->userreviseSlot(); break;
        case 7: _t->onCellClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 8: _t->onRadioButtonClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->addfreshen(); break;
        case 10: _t->deletefreshen(); break;
        case 11: _t->revisefreshen(); break;
        default: ;
        }
    }
}

const QMetaObject TabUserManage::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_TabUserManage.data,
      qt_meta_data_TabUserManage,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TabUserManage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TabUserManage::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TabUserManage.stringdata0))
        return static_cast<void*>(const_cast< TabUserManage*>(this));
    return QWidget::qt_metacast(_clname);
}

int TabUserManage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
