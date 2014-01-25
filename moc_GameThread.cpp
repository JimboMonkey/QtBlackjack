/****************************************************************************
** Meta object code from reading C++ file 'GameThread.hpp'
**
** Created: Sat Jan 25 23:27:55 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "GameThread.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GameThread.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GameThread[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      37,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      26,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,
      38,   11,   11,   11, 0x05,
      57,   11,   11,   11, 0x05,
      78,   76,   11,   11, 0x05,
     109,   76,   11,   11, 0x05,
     140,   11,   11,   11, 0x05,
     172,   11,   11,   11, 0x05,
     204,   11,   11,   11, 0x05,
     225,   11,   11,   11, 0x05,
     244,   11,   11,   11, 0x05,
     263,   11,   11,   11, 0x05,
     282,   11,   11,   11, 0x05,
     310,   11,   11,   11, 0x05,
     336,   11,   11,   11, 0x05,
     345,   11,   11,   11, 0x05,
     355,   11,   11,   11, 0x05,
     377,   11,   11,   11, 0x05,
     398,  390,   11,   11, 0x05,
     460,  456,   11,   11, 0x05,
     502,   11,   11,   11, 0x05,
     529,   11,   11,   11, 0x05,
     559,   11,   11,   11, 0x05,
     580,   11,   11,   11, 0x05,
     599,   11,   11,   11, 0x05,
     610,   11,   11,   11, 0x05,
     625,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
     653,  641,   11,   11, 0x08,
     695,  669,   11,   11, 0x08,
     714,  669,   11,   11, 0x08,
     745,  735,   11,   11, 0x08,
     779,  735,   11,   11, 0x08,
     824,  813,   11,   11, 0x08,
     856,  847,   11,   11, 0x08,
     875,   11,   11,   11, 0x08,
     896,   11,   11,   11, 0x08,
     911,   11,   11,   11, 0x08,
     925,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_GameThread[] = {
    "GameThread\0\0updateFromThread(QString)\0"
    "clearPlayersHand()\0clearDealersHand()\0"
    ",\0updateDealersHand(QString,int)\0"
    "updatePlayersHand(QString,int)\0"
    "updateDealersHandValue(QString)\0"
    "updatePlayersHandValue(QString)\0"
    "updateStack(QString)\0updateBet(QString)\0"
    "IncreaseBet(float)\0DecreaseBet(float)\0"
    "updatePlayersStack(QString)\0"
    "updateGameStatus(QString)\0Choice()\0"
    "BetDone()\0updateStatus(QString)\0"
    "Clearchips()\0,,,,,,,\0"
    "ButtonVisibility(bool,bool,bool,bool,bool,bool,bool,bool)\0"
    ",,,\0ResultTextVisibility(bool,bool,bool,bool)\0"
    "HandValueSpotsVisibility()\0"
    "updateResultsSummary(QString)\0"
    "HideResultsSummary()\0DisableChips(bool)\0"
    "GameOver()\0PlayWinSound()\0PlayLoseSound()\0"
    "ButtonIndex\0ChoiceMade(int)\0"
    "LoadCardName,CardPosition\0hello(QString,int)\0"
    "goodbye(QString,int)\0HandValue\0"
    "thUpdatePlayersHandValue(QString)\0"
    "thUpdateDealersHandValue(QString)\0"
    "StackValue\0thUpdateStack(QString)\0"
    "BetValue\0thUpdateBet(float)\0"
    "RemoveFromStack(int)\0ReturnBet(int)\0"
    "BettingDone()\0ClearBet()\0"
};

void GameThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        GameThread *_t = static_cast<GameThread *>(_o);
        switch (_id) {
        case 0: _t->updateFromThread((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->clearPlayersHand(); break;
        case 2: _t->clearDealersHand(); break;
        case 3: _t->updateDealersHand((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->updatePlayersHand((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->updateDealersHandValue((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->updatePlayersHandValue((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->updateStack((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->updateBet((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->IncreaseBet((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 10: _t->DecreaseBet((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 11: _t->updatePlayersStack((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 12: _t->updateGameStatus((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 13: _t->Choice(); break;
        case 14: _t->BetDone(); break;
        case 15: _t->updateStatus((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 16: _t->Clearchips(); break;
        case 17: _t->ButtonVisibility((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4])),(*reinterpret_cast< bool(*)>(_a[5])),(*reinterpret_cast< bool(*)>(_a[6])),(*reinterpret_cast< bool(*)>(_a[7])),(*reinterpret_cast< bool(*)>(_a[8]))); break;
        case 18: _t->ResultTextVisibility((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4]))); break;
        case 19: _t->HandValueSpotsVisibility(); break;
        case 20: _t->updateResultsSummary((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 21: _t->HideResultsSummary(); break;
        case 22: _t->DisableChips((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 23: _t->GameOver(); break;
        case 24: _t->PlayWinSound(); break;
        case 25: _t->PlayLoseSound(); break;
        case 26: _t->ChoiceMade((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 27: _t->hello((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 28: _t->goodbye((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 29: _t->thUpdatePlayersHandValue((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 30: _t->thUpdateDealersHandValue((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 31: _t->thUpdateStack((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 32: _t->thUpdateBet((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 33: _t->RemoveFromStack((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 34: _t->ReturnBet((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 35: _t->BettingDone(); break;
        case 36: _t->ClearBet(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData GameThread::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject GameThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_GameThread,
      qt_meta_data_GameThread, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GameThread::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GameThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GameThread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GameThread))
        return static_cast<void*>(const_cast< GameThread*>(this));
    return QThread::qt_metacast(_clname);
}

int GameThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 37)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 37;
    }
    return _id;
}

// SIGNAL 0
void GameThread::updateFromThread(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GameThread::clearPlayersHand()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void GameThread::clearDealersHand()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void GameThread::updateDealersHand(QString _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void GameThread::updatePlayersHand(QString _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void GameThread::updateDealersHandValue(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void GameThread::updatePlayersHandValue(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void GameThread::updateStack(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void GameThread::updateBet(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void GameThread::IncreaseBet(float _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void GameThread::DecreaseBet(float _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void GameThread::updatePlayersStack(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void GameThread::updateGameStatus(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void GameThread::Choice()
{
    QMetaObject::activate(this, &staticMetaObject, 13, 0);
}

// SIGNAL 14
void GameThread::BetDone()
{
    QMetaObject::activate(this, &staticMetaObject, 14, 0);
}

// SIGNAL 15
void GameThread::updateStatus(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 15, _a);
}

// SIGNAL 16
void GameThread::Clearchips()
{
    QMetaObject::activate(this, &staticMetaObject, 16, 0);
}

// SIGNAL 17
void GameThread::ButtonVisibility(bool _t1, bool _t2, bool _t3, bool _t4, bool _t5, bool _t6, bool _t7, bool _t8)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)), const_cast<void*>(reinterpret_cast<const void*>(&_t7)), const_cast<void*>(reinterpret_cast<const void*>(&_t8)) };
    QMetaObject::activate(this, &staticMetaObject, 17, _a);
}

// SIGNAL 18
void GameThread::ResultTextVisibility(bool _t1, bool _t2, bool _t3, bool _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 18, _a);
}

// SIGNAL 19
void GameThread::HandValueSpotsVisibility()
{
    QMetaObject::activate(this, &staticMetaObject, 19, 0);
}

// SIGNAL 20
void GameThread::updateResultsSummary(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 20, _a);
}

// SIGNAL 21
void GameThread::HideResultsSummary()
{
    QMetaObject::activate(this, &staticMetaObject, 21, 0);
}

// SIGNAL 22
void GameThread::DisableChips(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 22, _a);
}

// SIGNAL 23
void GameThread::GameOver()
{
    QMetaObject::activate(this, &staticMetaObject, 23, 0);
}

// SIGNAL 24
void GameThread::PlayWinSound()
{
    QMetaObject::activate(this, &staticMetaObject, 24, 0);
}

// SIGNAL 25
void GameThread::PlayLoseSound()
{
    QMetaObject::activate(this, &staticMetaObject, 25, 0);
}
QT_END_MOC_NAMESPACE
