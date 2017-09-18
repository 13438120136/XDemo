#include "decheckbox.h"

//----------------------------------------------------------------------------
DeCheckBox::DeCheckBox(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.label->setText("unkown");
	installEventFilter(this);
}
//----------------------------------------------------------------------------
DeCheckBox::~DeCheckBox()
{

}
//----------------------------------------------------------------------------
void DeCheckBox::setInitValue(const QString &text, bool checked)
{
	ui.label->setText(text);
	m_isEnabled = checked;
	setChecked(m_isEnabled);
}
//----------------------------------------------------------------------------
void DeCheckBox::setText(const QString &text)
{
	ui.label->setText(text);
}
//----------------------------------------------------------------------------
QString DeCheckBox::text()
{
	return ui.label->text();
}
//----------------------------------------------------------------------------
bool DeCheckBox::checked()
{
	return m_isEnabled;
}
//----------------------------------------------------------------------------
bool DeCheckBox::eventFilter(QObject *obj, QEvent *event)
 {
     if (event->type() == QEvent::MouseButtonRelease) 
	 {
		 m_isEnabled = !m_isEnabled;
		 setChecked(m_isEnabled);
		 emit signalCheckedChanged(m_isEnabled);
         return true;
     } 
	 else 
		 return QObject::eventFilter(obj, event);
 }
//----------------------------------------------------------------------------
void DeCheckBox::setChecked(bool check)
{
	if (check)
		ui.label_2->setText("¡Ì");
	else
		ui.label_2->clear();
}
//----------------------------------------------------------------------------