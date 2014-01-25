/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Sat Jan 25 23:27:52 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      23,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      51,   25,   11,   11, 0x08,
      82,   25,   11,   11, 0x08,
     123,  113,   11,   11, 0x08,
     155,  113,   11,   11, 0x08,
     198,  187,   11,   11, 0x08,
     233,  224,   11,   11, 0x08,
     257,   11,   11,   11, 0x08,
     276,   11,   11,   11, 0x08,
     302,  295,   11,   11, 0x08,
     429,  328,   11,   11, 0x08,
     552,  482,   11,   11, 0x08,
     584,   11,   11,   11, 0x08,
     620,  605,   11,   11, 0x08,
     650,   11,   11,   11, 0x08,
     671,   11,   11,   11, 0x08,
     693,  681,   11,   11, 0x08,
     712,   11,   11,   11, 0x08,
     728,   11,   11,   11, 0x08,
     743,   11,   11,   11, 0x08,
     759,   11,   11,   11, 0x08,
     775,   11,   11,   11, 0x08,
     793,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0threadStop()\0"
    "LoadCardName,CardPosition\0"
    "updateDealersHand(QString,int)\0"
    "updatePlayersHand(QString,int)\0HandValue\0"
    "UpdatePlayersHandValue(QString)\0"
    "UpdateDealersHandValue(QString)\0"
    "StackValue\0updateStackValue(QString)\0"
    "BetValue\0UpdateBetValue(QString)\0"
    "ClearPlayersHand()\0ClearDealersHand()\0"
    "Status\0updateGameStatus(QString)\0"
    "HitVisible,StandVisible,SurrenderVisible,DoubleVisible,SplitVisible,Ye"
    "sVisible,NoVisible,DoneVisible\0"
    "HideButtons(bool,bool,bool,bool,bool,bool,bool,bool)\0"
    "BustVisible,DealerBustVisible,BlackjackVisible,DealerBlackjackVisible\0"
    "ResultText(bool,bool,bool,bool)\0"
    "HideHandValueSpots()\0ResultsSummary\0"
    "updateResultsSummary(QString)\0"
    "HideResultsSummary()\0Restart()\0"
    "ActiveState\0DisableChips(bool)\0"
    "PositionYesNo()\0PlayWinSound()\0"
    "PlayLoseSound()\0PlayChipSound()\0"
    "DisplayAboutBox()\0MakeConnections()\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->threadStop(); break;
        case 1: _t->updateDealersHand((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->updatePlayersHand((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->UpdatePlayersHandValue((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->UpdateDealersHandValue((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->updateStackValue((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->UpdateBetValue((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->ClearPlayersHand(); break;
        case 8: _t->ClearDealersHand(); break;
        case 9: _t->updateGameStatus((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->HideButtons((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4])),(*reinterpret_cast< bool(*)>(_a[5])),(*reinterpret_cast< bool(*)>(_a[6])),(*reinterpret_cast< bool(*)>(_a[7])),(*reinterpret_cast< bool(*)>(_a[8]))); break;
        case 11: _t->ResultText((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4]))); break;
        case 12: _t->HideHandValueSpots(); break;
        case 13: _t->updateResultsSummary((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 14: _t->HideResultsSummary(); break;
        case 15: _t->Restart(); break;
        case 16: _t->DisableChips((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 17: _t->PositionYesNo(); break;
        case 18: _t->PlayWinSound(); break;
        case 19: _t->PlayLoseSound(); break;
        case 20: _t->PlayChipSound(); break;
        case 21: _t->DisplayAboutBox(); break;
        case 22: _t->MakeConnections(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 23)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 23;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::threadStop()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
