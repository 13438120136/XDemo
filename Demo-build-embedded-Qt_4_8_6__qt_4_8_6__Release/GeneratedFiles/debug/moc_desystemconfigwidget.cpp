/****************************************************************************
** Meta object code from reading C++ file 'desystemconfigwidget.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../Demo/desystemconfigwidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'desystemconfigwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DeSystemConfigWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      22,   21,   21,   21, 0x0a,
      49,   21,   21,   21, 0x0a,
      72,   21,   21,   21, 0x0a,
      93,   21,   21,   21, 0x0a,
     118,   21,   21,   21, 0x0a,
     144,   21,   21,   21, 0x0a,
     166,   21,   21,   21, 0x0a,
     187,   21,   21,   21, 0x0a,
     208,   21,   21,   21, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_DeSystemConfigWidget[] = {
    "DeSystemConfigWidget\0\0propertyEditSlot(QWidget*)\0"
    "on_deviceBtn_clicked()\0on_testBtn_clicked()\0"
    "on_runStateBtn_clicked()\0"
    "on_testParamBtn_clicked()\0"
    "on_alphaBtn_clicked()\0on_betaBtn_clicked()\0"
    "on_funcBtn_clicked()\0on_logoutBtn_clicked()\0"
};

void DeSystemConfigWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        DeSystemConfigWidget *_t = static_cast<DeSystemConfigWidget *>(_o);
        switch (_id) {
        case 0: _t->propertyEditSlot((*reinterpret_cast< QWidget*(*)>(_a[1]))); break;
        case 1: _t->on_deviceBtn_clicked(); break;
        case 2: _t->on_testBtn_clicked(); break;
        case 3: _t->on_runStateBtn_clicked(); break;
        case 4: _t->on_testParamBtn_clicked(); break;
        case 5: _t->on_alphaBtn_clicked(); break;
        case 6: _t->on_betaBtn_clicked(); break;
        case 7: _t->on_funcBtn_clicked(); break;
        case 8: _t->on_logoutBtn_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData DeSystemConfigWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject DeSystemConfigWidget::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_DeSystemConfigWidget,
      qt_meta_data_DeSystemConfigWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DeSystemConfigWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DeSystemConfigWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DeSystemConfigWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DeSystemConfigWidget))
        return static_cast<void*>(const_cast< DeSystemConfigWidget*>(this));
    return QDialog::qt_metacast(_clname);
}

int DeSystemConfigWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
