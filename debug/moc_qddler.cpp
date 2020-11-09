/****************************************************************************
** Meta object code from reading C++ file 'qddler.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../qddler.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qddler.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Qddler_t {
    QByteArrayData data[8];
    char stringdata0[110];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Qddler_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Qddler_t qt_meta_stringdata_Qddler = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Qddler"
QT_MOC_LITERAL(1, 7, 13), // "onTimechanged"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 15), // "onEnergychanged"
QT_MOC_LITERAL(4, 38, 17), // "onDeadlinechanged"
QT_MOC_LITERAL(5, 56, 15), // "onTimeExhausted"
QT_MOC_LITERAL(6, 72, 17), // "onEnergyExhausted"
QT_MOC_LITERAL(7, 90, 19) // "onDeadlineExhausted"

    },
    "Qddler\0onTimechanged\0\0onEnergychanged\0"
    "onDeadlinechanged\0onTimeExhausted\0"
    "onEnergyExhausted\0onDeadlineExhausted"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Qddler[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    0,   45,    2, 0x06 /* Public */,
       4,    0,   46,    2, 0x06 /* Public */,
       5,    0,   47,    2, 0x06 /* Public */,
       6,    0,   48,    2, 0x06 /* Public */,
       7,    0,   49,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Qddler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Qddler *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onTimechanged(); break;
        case 1: _t->onEnergychanged(); break;
        case 2: _t->onDeadlinechanged(); break;
        case 3: _t->onTimeExhausted(); break;
        case 4: _t->onEnergyExhausted(); break;
        case 5: _t->onDeadlineExhausted(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Qddler::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Qddler::onTimechanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Qddler::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Qddler::onEnergychanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Qddler::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Qddler::onDeadlinechanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Qddler::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Qddler::onTimeExhausted)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Qddler::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Qddler::onEnergyExhausted)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Qddler::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Qddler::onDeadlineExhausted)) {
                *result = 5;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Qddler::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Qddler.data,
    qt_meta_data_Qddler,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Qddler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Qddler::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Qddler.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Qddler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void Qddler::onTimechanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Qddler::onEnergychanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Qddler::onDeadlinechanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Qddler::onTimeExhausted()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Qddler::onEnergyExhausted()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void Qddler::onDeadlineExhausted()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
