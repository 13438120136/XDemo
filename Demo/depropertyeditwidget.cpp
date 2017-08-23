#include "depropertyeditwidget.h"
#include "desystemconfigwidget.h"
#include <demo.h>

Q_DECLARE_METATYPE(Demo *)
//----------------------------------------------------------------------------
DePropertyEditWidget::DePropertyEditWidget(QWidget *parent)
	: QDialog(parent)
{
	m_systemConfigWidget = NULL;
	ui.setupUi(this);
	ui.virtualBoradWidget->hide();
	this->setWindowFlags(Qt::ToolTip);
	ui.lineEdit->installEventFilter(this);
}
//----------------------------------------------------------------------------
DePropertyEditWidget::~DePropertyEditWidget()
{

}
//----------------------------------------------------------------------------
void DePropertyEditWidget::setHeadTitle(const QString &title)
{
	ui.groupBox->setTitle(title);
}
//----------------------------------------------------------------------------
void DePropertyEditWidget::setContentText(const QString &text)
{
	ui.lineEdit->setText(text);
}
//----------------------------------------------------------------------------
void DePropertyEditWidget::setSystemConfigWidget(DeSystemConfigWidget *widget)
{
	m_systemConfigWidget = widget;
}
//----------------------------------------------------------------------------
void DePropertyEditWidget::on_btnOk_clicked()
{
	QString content = ui.lineEdit->text();
	if (content.isEmpty() || content.isNull())
		return ;

	if (!m_systemConfigWidget->execValidAndSave(content))
		return ;

	Demo *demo = qApp->property("_mainWin").value<Demo *>();
	demo->slotBackMainWidget();
}
//----------------------------------------------------------------------------
void DePropertyEditWidget::on_btnCancel_clicked()
{	
	Demo *demo = qApp->property("_mainWin").value<Demo *>();
	demo->slotBackMainWidget();
}
//----------------------------------------------------------------------------
bool DePropertyEditWidget::eventFilter(QObject *obj, QEvent *event)
{
	if (event->type() == QEvent::MouseButtonRelease) 
	{
		ui.virtualBoradWidget->setEditControl((QLineEdit *)obj);
		ui.virtualBoradWidget->show();
		return true;
	}
	else 
	{
		// standard event processing
		return QObject::eventFilter(obj, event);
	}
}
//----------------------------------------------------------------------------