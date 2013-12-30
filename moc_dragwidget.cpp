/****************************************************************************
** Meta object code from reading C++ file 'dragwidget.h'
**
** Created: Sat Dec 7 22:47:51 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "dragwidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dragwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DragWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,
      27,   11,   11,   11, 0x05,
      44,   11,   11,   11, 0x05,
      60,   11,   11,   11, 0x05,
      81,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      97,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_DragWidget[] = {
    "DragWidget\0\0BetPlaced(int)\0BetReturned(int)\0"
    "AddToBet(float)\0RemoveFromBet(float)\0"
    "PlayChipSound()\0ClearChips()\0"
};

void DragWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        DragWidget *_t = static_cast<DragWidget *>(_o);
        switch (_id) {
        case 0: _t->BetPlaced((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->BetReturned((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->AddToBet((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 3: _t->RemoveFromBet((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 4: _t->PlayChipSound(); break;
        case 5: _t->ClearChips(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData DragWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject DragWidget::staticMetaObject = {
    { &QStackedWidget::staticMetaObject, qt_meta_stringdata_DragWidget,
      qt_meta_data_DragWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DragWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DragWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DragWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DragWidget))
        return static_cast<void*>(const_cast< DragWidget*>(this));
    return QStackedWidget::qt_metacast(_clname);
}

int DragWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QStackedWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void DragWidget::BetPlaced(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DragWidget::BetReturned(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void DragWidget::AddToBet(float _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void DragWidget::RemoveFromBet(float _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void DragWidget::PlayChipSound()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}
QT_END_MOC_NAMESPACE
