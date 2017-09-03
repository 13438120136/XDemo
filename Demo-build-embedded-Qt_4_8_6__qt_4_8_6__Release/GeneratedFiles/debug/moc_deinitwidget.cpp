/****************************************************************************
** Meta object code from reading C++ file 'deinitwidget.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../Demo/deinitwidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'deinitwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DeInitWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x0a,
      28,   13,   13,   13, 0x0a,
      49,   13,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_DeInitWidget[] = {
    "DeInitWidget\0\0slotTimeOut()\0"
    "on_exitBtn_clicked()\0on_loginBtn_clicked()\0"
};

void DeInitWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        DeInitWidget *_t = static_cast<DeInitWidget *>(_o);
        switch (_id) {
        case 0: _t->slotTimeOut(); break;
        case 1: _t->on_exitBtn_clicked(); break;
        case 2: _t->on_loginBtn_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData DeInitWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject DeInitWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_DeInitWidget,
      qt_meta_data_DeInitWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DeInitWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DeInitWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DeInitWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DeInitWidget))
        return static_cast<void*>(const_cast< DeInitWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int DeInitWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
