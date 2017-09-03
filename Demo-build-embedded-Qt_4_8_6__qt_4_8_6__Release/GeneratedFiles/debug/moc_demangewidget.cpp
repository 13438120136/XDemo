/****************************************************************************
** Meta object code from reading C++ file 'demangewidget.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../Demo/demangewidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'demangewidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DeManageWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x0a,
      30,   15,   15,   15, 0x0a,
      44,   15,   15,   15, 0x0a,
      62,   57,   15,   15, 0x0a,
      87,   57,   15,   15, 0x0a,
     115,   15,   15,   15, 0x0a,
     148,  138,   15,   15, 0x0a,
     197,   15,   15,   15, 0x0a,
     218,   15,   15,   15, 0x0a,
     240,   15,   15,   15, 0x0a,
     261,   15,   15,   15, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_DeManageWidget[] = {
    "DeManageWidget\0\0addUserSlot()\0"
    "delUserSlot()\0modifySlot()\0data\0"
    "slotAddUser(DeUserTable)\0"
    "slotUpdateUser(DeUserTable)\0"
    "addRadioactivitySlot()\0tableData\0"
    "slotAddRadioactiveData(DeRadioactiveSourceTable)\0"
    "on_userBtn_clicked()\0on_radioBtn_clicked()\0"
    "on_funcBtn_clicked()\0on_logoutBtn_clicked()\0"
};

void DeManageWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        DeManageWidget *_t = static_cast<DeManageWidget *>(_o);
        switch (_id) {
        case 0: _t->addUserSlot(); break;
        case 1: _t->delUserSlot(); break;
        case 2: _t->modifySlot(); break;
        case 3: _t->slotAddUser((*reinterpret_cast< DeUserTable(*)>(_a[1]))); break;
        case 4: _t->slotUpdateUser((*reinterpret_cast< DeUserTable(*)>(_a[1]))); break;
        case 5: _t->addRadioactivitySlot(); break;
        case 6: _t->slotAddRadioactiveData((*reinterpret_cast< DeRadioactiveSourceTable(*)>(_a[1]))); break;
        case 7: _t->on_userBtn_clicked(); break;
        case 8: _t->on_radioBtn_clicked(); break;
        case 9: _t->on_funcBtn_clicked(); break;
        case 10: _t->on_logoutBtn_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData DeManageWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject DeManageWidget::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_DeManageWidget,
      qt_meta_data_DeManageWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DeManageWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DeManageWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DeManageWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DeManageWidget))
        return static_cast<void*>(const_cast< DeManageWidget*>(this));
    return QDialog::qt_metacast(_clname);
}

int DeManageWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
