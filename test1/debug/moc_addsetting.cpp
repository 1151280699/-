/****************************************************************************
** Meta object code from reading C++ file 'addsetting.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../addsetting.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'addsetting.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_addsetting_t {
    QByteArrayData data[9];
    char stringdata0[126];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_addsetting_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_addsetting_t qt_meta_stringdata_addsetting = {
    {
QT_MOC_LITERAL(0, 0, 10), // "addsetting"
QT_MOC_LITERAL(1, 11, 6), // "change"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 21), // "on_trueButton_clicked"
QT_MOC_LITERAL(4, 41, 21), // "on_addStation_clicked"
QT_MOC_LITERAL(5, 63, 24), // "on_deleteStation_clicked"
QT_MOC_LITERAL(6, 88, 26), // "on_StationNums_cellChanged"
QT_MOC_LITERAL(7, 115, 3), // "row"
QT_MOC_LITERAL(8, 119, 6) // "column"

    },
    "addsetting\0change\0\0on_trueButton_clicked\0"
    "on_addStation_clicked\0on_deleteStation_clicked\0"
    "on_StationNums_cellChanged\0row\0column"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_addsetting[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   40,    2, 0x08 /* Private */,
       4,    0,   41,    2, 0x08 /* Private */,
       5,    0,   42,    2, 0x08 /* Private */,
       6,    2,   43,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    7,    8,

       0        // eod
};

void addsetting::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        addsetting *_t = static_cast<addsetting *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->change(); break;
        case 1: _t->on_trueButton_clicked(); break;
        case 2: _t->on_addStation_clicked(); break;
        case 3: _t->on_deleteStation_clicked(); break;
        case 4: _t->on_StationNums_cellChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (addsetting::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&addsetting::change)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject addsetting::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_addsetting.data,
      qt_meta_data_addsetting,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *addsetting::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *addsetting::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_addsetting.stringdata0))
        return static_cast<void*>(const_cast< addsetting*>(this));
    return QWidget::qt_metacast(_clname);
}

int addsetting::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void addsetting::change()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
