/****************************************************************************
** Meta object code from reading C++ file 'demo.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../Demo/demo.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'demo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Demo[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
       6,    5,    5,    5, 0x05,
      20,    5,    5,    5, 0x05,
      35,    5,    5,    5, 0x05,

 // slots: signature, parameters, type, tag, flags
      64,   58,    5,    5, 0x0a,
      90,   83,    5,    5, 0x0a,
     114,    5,    5,    5, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Demo[] = {
    "Demo\0\0signalLogin()\0signalLogout()\0"
    "signalRadiationCheck()\0bShow\0"
    "slotShowMenu(bool)\0widget\0"
    "slotSetWidget(QWidget*)\0slotBackMainWidget()\0"
};

void Demo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Demo *_t = static_cast<Demo *>(_o);
        switch (_id) {
        case 0: _t->signalLogin(); break;
        case 1: _t->signalLogout(); break;
        case 2: _t->signalRadiationCheck(); break;
        case 3: _t->slotShowMenu((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->slotSetWidget((*reinterpret_cast< QWidget*(*)>(_a[1]))); break;
        case 5: _t->slotBackMainWidget(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Demo::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Demo::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Demo,
      qt_meta_data_Demo, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Demo::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Demo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Demo::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Demo))
        return static_cast<void*>(const_cast< Demo*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Demo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
void Demo::signalLogin()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void Demo::signalLogout()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void Demo::signalRadiationCheck()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
