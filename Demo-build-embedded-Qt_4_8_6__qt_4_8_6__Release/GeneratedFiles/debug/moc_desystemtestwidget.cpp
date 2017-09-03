/****************************************************************************
** Meta object code from reading C++ file 'desystemtestwidget.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../Demo/desystemtestwidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'desystemtestwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DeSystemTestWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      20,   19,   19,   19, 0x0a,
      43,   19,   19,   19, 0x0a,
      62,   19,   19,   19, 0x0a,
      86,   19,   19,   19, 0x0a,
     109,   19,   19,   19, 0x0a,
     130,   19,   19,   19, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_DeSystemTestWidget[] = {
    "DeSystemTestWidget\0\0slotPhysicalTest(bool)\0"
    "on_ioBtn_clicked()\0on_channelBtn_clicked()\0"
    "on_xiaolvBtn_clicked()\0on_funcBtn_clicked()\0"
    "on_logoutBtn_clicked()\0"
};

void DeSystemTestWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        DeSystemTestWidget *_t = static_cast<DeSystemTestWidget *>(_o);
        switch (_id) {
        case 0: _t->slotPhysicalTest((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->on_ioBtn_clicked(); break;
        case 2: _t->on_channelBtn_clicked(); break;
        case 3: _t->on_xiaolvBtn_clicked(); break;
        case 4: _t->on_funcBtn_clicked(); break;
        case 5: _t->on_logoutBtn_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData DeSystemTestWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject DeSystemTestWidget::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_DeSystemTestWidget,
      qt_meta_data_DeSystemTestWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DeSystemTestWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DeSystemTestWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DeSystemTestWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DeSystemTestWidget))
        return static_cast<void*>(const_cast< DeSystemTestWidget*>(this));
    return QDialog::qt_metacast(_clname);
}

int DeSystemTestWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
