/****************************************************************************
** Meta object code from reading C++ file 'Box.hpp'
**
** Created: Sat Jan 25 23:27:54 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Box.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Box.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Box[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
       5,    4,    4,    4, 0x05,
      37,    4,    4,    4, 0x05,
      56,    4,    4,    4, 0x05,

 // slots: signature, parameters, type, tag, flags
      95,   83,    4,    4, 0x08,
     126,  114,    4,    4, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Box[] = {
    "Box\0\0updatePlayersHandValue(QString)\0"
    "updateBet(QString)\0updatePlayersName(QString)\0"
    "BetIncrease\0IncreaseBet(float)\0"
    "BetDecrease\0DecreaseBet(float)\0"
};

void Box::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Box *_t = static_cast<Box *>(_o);
        switch (_id) {
        case 0: _t->updatePlayersHandValue((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->updateBet((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->updatePlayersName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->IncreaseBet((*reinterpret_cast< const float(*)>(_a[1]))); break;
        case 4: _t->DecreaseBet((*reinterpret_cast< const float(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Box::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Box::staticMetaObject = {
    { &Participant::staticMetaObject, qt_meta_stringdata_Box,
      qt_meta_data_Box, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Box::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Box::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Box::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Box))
        return static_cast<void*>(const_cast< Box*>(this));
    return Participant::qt_metacast(_clname);
}

int Box::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Participant::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void Box::updatePlayersHandValue(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Box::updateBet(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Box::updatePlayersName(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
