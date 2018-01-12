/****************************************************************************
** Meta object code from reading C++ file 'tabstartsell.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../tabstartsell.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tabstartsell.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_TabStartSell_t {
    QByteArrayData data[15];
    char stringdata0[275];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TabStartSell_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TabStartSell_t qt_meta_stringdata_TabStartSell = {
    {
QT_MOC_LITERAL(0, 0, 12), // "TabStartSell"
QT_MOC_LITERAL(1, 13, 18), // "savestabuyEditinfo"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 24), // "savestatelephoneEditinfo"
QT_MOC_LITERAL(4, 58, 20), // "savestaphoneEditinfo"
QT_MOC_LITERAL(5, 79, 21), // "savestasortComBoxinfo"
QT_MOC_LITERAL(6, 101, 21), // "savestalengthEditinfo"
QT_MOC_LITERAL(7, 123, 20), // "savestawidthEditinfo"
QT_MOC_LITERAL(8, 144, 16), // "savestateChanged"
QT_MOC_LITERAL(9, 161, 25), // "savestaflatsingleEditinfo"
QT_MOC_LITERAL(10, 187, 22), // "savestamodulusEditinfo"
QT_MOC_LITERAL(11, 210, 23), // "savestaterminalEditinfo"
QT_MOC_LITERAL(12, 234, 21), // "savestanameComBoxinfo"
QT_MOC_LITERAL(13, 256, 11), // "ClearScreen"
QT_MOC_LITERAL(14, 268, 6) // "Finish"

    },
    "TabStartSell\0savestabuyEditinfo\0\0"
    "savestatelephoneEditinfo\0savestaphoneEditinfo\0"
    "savestasortComBoxinfo\0savestalengthEditinfo\0"
    "savestawidthEditinfo\0savestateChanged\0"
    "savestaflatsingleEditinfo\0"
    "savestamodulusEditinfo\0savestaterminalEditinfo\0"
    "savestanameComBoxinfo\0ClearScreen\0"
    "Finish"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TabStartSell[] = {

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
       1,    0,   79,    2, 0x08 /* Private */,
       3,    0,   80,    2, 0x08 /* Private */,
       4,    0,   81,    2, 0x08 /* Private */,
       5,    1,   82,    2, 0x08 /* Private */,
       6,    0,   85,    2, 0x08 /* Private */,
       7,    0,   86,    2, 0x08 /* Private */,
       8,    1,   87,    2, 0x08 /* Private */,
       9,    0,   90,    2, 0x08 /* Private */,
      10,    0,   91,    2, 0x08 /* Private */,
      11,    0,   92,    2, 0x08 /* Private */,
      12,    0,   93,    2, 0x08 /* Private */,
      13,    0,   94,    2, 0x08 /* Private */,
      14,    0,   95,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TabStartSell::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TabStartSell *_t = static_cast<TabStartSell *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->savestabuyEditinfo(); break;
        case 1: _t->savestatelephoneEditinfo(); break;
        case 2: _t->savestaphoneEditinfo(); break;
        case 3: _t->savestasortComBoxinfo((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->savestalengthEditinfo(); break;
        case 5: _t->savestawidthEditinfo(); break;
        case 6: _t->savestateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->savestaflatsingleEditinfo(); break;
        case 8: _t->savestamodulusEditinfo(); break;
        case 9: _t->savestaterminalEditinfo(); break;
        case 10: _t->savestanameComBoxinfo(); break;
        case 11: _t->ClearScreen(); break;
        case 12: _t->Finish(); break;
        default: ;
        }
    }
}

const QMetaObject TabStartSell::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_TabStartSell.data,
      qt_meta_data_TabStartSell,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TabStartSell::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TabStartSell::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TabStartSell.stringdata0))
        return static_cast<void*>(const_cast< TabStartSell*>(this));
    return QWidget::qt_metacast(_clname);
}

int TabStartSell::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
