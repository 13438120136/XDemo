#include "deinputdelegate.h"
#include "demo.h"
#include <QLineEdit>

Q_DECLARE_METATYPE(Demo *)

//----------------------------------------------------------------------------
bool DeInputDelegate::eventFilter(QObject *obj, QEvent *event)
{
	if (event->type() == QEvent::MouseButtonRelease)
	{
		if (!obj->inherits("QLineEdit"))
			return true;

		DeKeyBoradWidget *widget = new DeKeyBoradWidget(((QLineEdit *)obj)->text());
		connect(widget, SIGNAL(signalOk(const QString&)), (QLineEdit *)obj, SLOT(setText(const QString&)));
		Demo *demo = qApp->property("_mainWin").value<Demo *>();
		demo->slotSetWidget(widget);
		return true;
	} 

	return QObject::eventFilter(obj, event);
}
//----------------------------------------------------------------------------
bool DePasswordDelegate::eventFilter(QObject *obj, QEvent *event)
{
	if (event->type() == QEvent::MouseButtonRelease)
	{
		if (!obj->inherits("QLineEdit"))
			return true;

		DeKeyBoradWidget *widget = new DeKeyBoradWidget(((QLineEdit *)obj)->text(), DeKeyBoradWidget::Password);
		connect(widget, SIGNAL(signalOk(const QString&)), (QLineEdit *)obj, SLOT(setText(const QString&)));
		Demo *demo = qApp->property("_mainWin").value<Demo *>();
		demo->slotSetWidget(widget);
		return true;
	} 

	return QObject::eventFilter(obj, event);
}
//----------------------------------------------------------------------------