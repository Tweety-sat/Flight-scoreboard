/****************************************************************************
** Meta object code from reading C++ file 'ManageFlight.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Flightsboard/ManageFlight.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ManageFlight.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ManageFlight_t {
    QByteArrayData data[11];
    char stringdata0[130];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ManageFlight_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ManageFlight_t qt_meta_stringdata_ManageFlight = {
    {
QT_MOC_LITERAL(0, 0, 12), // "ManageFlight"
QT_MOC_LITERAL(1, 13, 9), // "addFlight"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 6), // "Flight"
QT_MOC_LITERAL(4, 31, 10), // "editFlight"
QT_MOC_LITERAL(5, 42, 12), // "deleteFlight"
QT_MOC_LITERAL(6, 55, 23), // "on_lineFind_textChanged"
QT_MOC_LITERAL(7, 79, 4), // "arg1"
QT_MOC_LITERAL(8, 84, 14), // "on_add_clicked"
QT_MOC_LITERAL(9, 99, 14), // "on_del_clicked"
QT_MOC_LITERAL(10, 114, 15) // "on_edit_clicked"

    },
    "ManageFlight\0addFlight\0\0Flight\0"
    "editFlight\0deleteFlight\0on_lineFind_textChanged\0"
    "arg1\0on_add_clicked\0on_del_clicked\0"
    "on_edit_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ManageFlight[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       4,    2,   52,    2, 0x06 /* Public */,
       5,    1,   57,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   60,    2, 0x08 /* Private */,
       8,    0,   63,    2, 0x08 /* Private */,
       9,    0,   64,    2, 0x08 /* Private */,
      10,    0,   65,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 3,    2,    2,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ManageFlight::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ManageFlight *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->addFlight((*reinterpret_cast< Flight(*)>(_a[1]))); break;
        case 1: _t->editFlight((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< Flight(*)>(_a[2]))); break;
        case 2: _t->deleteFlight((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_lineFind_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->on_add_clicked(); break;
        case 5: _t->on_del_clicked(); break;
        case 6: _t->on_edit_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ManageFlight::*)(Flight );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ManageFlight::addFlight)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ManageFlight::*)(int , Flight );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ManageFlight::editFlight)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ManageFlight::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ManageFlight::deleteFlight)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ManageFlight::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_ManageFlight.data,
    qt_meta_data_ManageFlight,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ManageFlight::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ManageFlight::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ManageFlight.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int ManageFlight::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void ManageFlight::addFlight(Flight _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ManageFlight::editFlight(int _t1, Flight _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ManageFlight::deleteFlight(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
