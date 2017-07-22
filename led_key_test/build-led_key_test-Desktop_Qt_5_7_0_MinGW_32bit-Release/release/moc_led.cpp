/****************************************************************************
** Meta object code from reading C++ file 'led.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../led_key_test/led.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'led.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_led_t {
    QByteArrayData data[8];
    char stringdata0[58];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_led_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_led_t qt_meta_stringdata_led = {
    {
QT_MOC_LITERAL(0, 0, 3), // "led"
QT_MOC_LITERAL(1, 4, 11), // "send_status"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 2), // "no"
QT_MOC_LITERAL(4, 20, 10), // "led_status"
QT_MOC_LITERAL(5, 31, 4), // "stat"
QT_MOC_LITERAL(6, 36, 10), // "setLedStat"
QT_MOC_LITERAL(7, 47, 10) // "mousePress"

    },
    "led\0send_status\0\0no\0led_status\0stat\0"
    "setLedStat\0mousePress"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_led[] = {

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
       1,    2,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   34,    2, 0x0a /* Public */,
       7,    0,   37,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::UChar, 0x80000000 | 4,    3,    5,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,

       0        // eod
};

void led::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        led *_t = static_cast<led *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->send_status((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< led_status(*)>(_a[2]))); break;
        case 1: _t->setLedStat((*reinterpret_cast< led_status(*)>(_a[1]))); break;
        case 2: _t->mousePress(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (led::*_t)(quint8 , led_status );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&led::send_status)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject led::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_led.data,
      qt_meta_data_led,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *led::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *led::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_led.stringdata0))
        return static_cast<void*>(const_cast< led*>(this));
    return QWidget::qt_metacast(_clname);
}

int led::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void led::send_status(quint8 _t1, led_status _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
