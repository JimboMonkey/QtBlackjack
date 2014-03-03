/****************************************************************************
** Meta object code from reading C++ file 'ChipPile.hpp'
**
** Created: Sun Feb 23 17:46:27 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "ChipPile.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ChipPile.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ChipPile[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x05,
      29,    9,    9,    9, 0x05,
      48,    9,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
      64,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ChipPile[] = {
    "ChipPile\0\0IncreaseBet(float)\0"
    "DecreaseBet(float)\0PlayChipSound()\0"
    "ClearChips()\0"
};

void ChipPile::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ChipPile *_t = static_cast<ChipPile *>(_o);
        switch (_id) {
        case 0: _t->IncreaseBet((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 1: _t->DecreaseBet((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 2: _t->PlayChipSound(); break;
        case 3: _t->ClearChips(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ChipPile::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ChipPile::staticMetaObject = {
    { &QStackedWidget::staticMetaObject, qt_meta_stringdata_ChipPile,
      qt_meta_data_ChipPile, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ChipPile::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ChipPile::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ChipPile::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ChipPile))
        return static_cast<void*>(const_cast< ChipPile*>(this));
    return QStackedWidget::qt_metacast(_clname);
}

int ChipPile::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QStackedWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void ChipPile::IncreaseBet(float _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ChipPile::DecreaseBet(float _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ChipPile::PlayChipSound()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
