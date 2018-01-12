/****************************************************************************
** Meta object code from reading C++ file 'tabproductmanage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../tabproductmanage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tabproductmanage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_TabProductManage_t {
    QByteArrayData data[14];
    char stringdata0[203];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TabProductManage_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TabProductManage_t qt_meta_stringdata_TabProductManage = {
    {
QT_MOC_LITERAL(0, 0, 16), // "TabProductManage"
QT_MOC_LITERAL(1, 17, 16), // "firstPageClicked"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 19), // "previousPageClicked"
QT_MOC_LITERAL(4, 55, 15), // "nextPageClicked"
QT_MOC_LITERAL(5, 71, 15), // "lastPageClicked"
QT_MOC_LITERAL(6, 87, 14), // "addPageClicked"
QT_MOC_LITERAL(7, 102, 14), // "delPageClicked"
QT_MOC_LITERAL(8, 117, 17), // "updatePageClicked"
QT_MOC_LITERAL(9, 135, 13), // "onCellClicked"
QT_MOC_LITERAL(10, 149, 20), // "onRadioButtonClicked"
QT_MOC_LITERAL(11, 170, 8), // "addfresh"
QT_MOC_LITERAL(12, 179, 11), // "deletefresh"
QT_MOC_LITERAL(13, 191, 11) // "revisefresh"

    },
    "TabProductManage\0firstPageClicked\0\0"
    "previousPageClicked\0nextPageClicked\0"
    "lastPageClicked\0addPageClicked\0"
    "delPageClicked\0updatePageClicked\0"
    "onCellClicked\0onRadioButtonClicked\0"
    "addfresh\0deletefresh\0revisefresh"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TabProductManage[] = {

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
       1,    0,   74,    2, 0x0a /* Public */,
       3,    0,   75,    2, 0x0a /* Public */,
       4,    0,   76,    2, 0x0a /* Public */,
       5,    0,   77,    2, 0x0a /* Public */,
       6,    0,   78,    2, 0x0a /* Public */,
       7,    0,   79,    2, 0x0a /* Public */,
       8,    0,   80,    2, 0x0a /* Public */,
       9,    2,   81,    2, 0x0a /* Public */,
      10,    1,   86,    2, 0x0a /* Public */,
      11,    0,   89,    2, 0x0a /* Public */,
      12,    0,   90,    2, 0x0a /* Public */,
      13,    0,   91,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TabProductManage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TabProductManage *_t = static_cast<TabProductManage *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->firstPageClicked(); break;
        case 1: _t->previousPageClicked(); break;
        case 2: _t->nextPageClicked(); break;
        case 3: _t->lastPageClicked(); break;
        case 4: _t->addPageClicked(); break;
        case 5: _t->delPageClicked(); break;
        case 6: _t->updatePageClicked(); break;
        case 7: _t->onCellClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 8: _t->onRadioButtonClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->addfresh(); break;
        case 10: _t->deletefresh(); break;
        case 11: _t->revisefresh(); break;
        default: ;
        }
    }
}

const QMetaObject TabProductManage::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_TabProductManage.data,
      qt_meta_data_TabProductManage,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TabProductManage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TabProductManage::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TabProductManage.stringdata0))
        return static_cast<void*>(const_cast< TabProductManage*>(this));
    return QWidget::qt_metacast(_clname);
}

int TabProductManage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
