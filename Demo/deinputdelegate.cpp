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
bool DeIntDelegate::eventFilter(QObject *obj, QEvent *event)
{
	if (event->type() == QEvent::MouseButtonRelease)
	{
		if (!obj->inherits("QLineEdit"))
			return true;

		DeKeyBoradWidget *widget = new DeKeyBoradWidget(((QLineEdit *)obj)->text(), DeKeyBoradWidget::Int);
		connect(widget, SIGNAL(signalOk(const QString&)), (QLineEdit *)obj, SLOT(setText(const QString&)));
		Demo *demo = qApp->property("_mainWin").value<Demo *>();
		demo->slotSetWidget(widget);
		return true;
	} 

	return QObject::eventFilter(obj, event);
}
//----------------------------------------------------------------------------
bool DeButtonIPDelegate::eventFilter(QObject *obj, QEvent *event)
{
	if (event->type() == QEvent::MouseButtonRelease)
	{
		if (!obj->inherits("QPushButton"))
			return true;

		this->m_button = (QPushButton *)obj;
		DeKeyBoradWidget *widget = new DeKeyBoradWidget(m_button->text(), DeKeyBoradWidget::Ip);
		
		connect(widget, SIGNAL(signalOk(const QString&)), this, SLOT(slotButtonChange(const QString&)));
		Demo *demo = qApp->property("_mainWin").value<Demo *>();
		demo->slotSetWidget(widget);
		return true;
	} 

	return QObject::eventFilter(obj, event);
}
//----------------------------------------------------------------------------
void DeButtonIPDelegate::slotButtonChange(const QString &text)
{
	m_button->setText(text);
	emit signalOwnerObj(m_button);
}
//----------------------------------------------------------------------------
bool DeButtonIntDelegate::eventFilter(QObject *obj, QEvent *event)
{
	if (event->type() == QEvent::MouseButtonRelease)
	{
		if (!obj->inherits("QPushButton"))
			return true;

		this->m_button = (QPushButton *)obj;
		DeKeyBoradWidget *widget = new DeKeyBoradWidget(m_button->text(), DeKeyBoradWidget::Int);
		
		connect(widget, SIGNAL(signalOk(const QString&)), this, SLOT(slotButtonChange(const QString&)));
		Demo *demo = qApp->property("_mainWin").value<Demo *>();
		demo->slotSetWidget(widget);
		return true;
	} 

	return QObject::eventFilter(obj, event);
}
//----------------------------------------------------------------------------
void DeButtonIntDelegate::slotButtonChange(const QString &text)
{
	m_button->setText(text);
	emit signalOwnerObj(m_button);
}
//----------------------------------------------------------------------------
bool DeButtonDoubleDelegate::eventFilter(QObject *obj, QEvent *event)
{
	if (event->type() == QEvent::MouseButtonRelease)
	{
		if (!obj->inherits("QPushButton"))
			return true;

		this->m_button = (QPushButton *)obj;
		DeKeyBoradWidget *widget = new DeKeyBoradWidget(m_button->text(), DeKeyBoradWidget::Float);
		
		connect(widget, SIGNAL(signalOk(const QString&)), this, SLOT(slotButtonChange(const QString&)));
		Demo *demo = qApp->property("_mainWin").value<Demo *>();
		demo->slotSetWidget(widget);
		return true;
	} 

	return QObject::eventFilter(obj, event);
}
//----------------------------------------------------------------------------
void DeButtonDoubleDelegate::slotButtonChange(const QString &text)
{
	m_button->setText(text);
	emit signalOwnerObj(m_button);
}
//----------------------------------------------------------------------------