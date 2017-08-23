#include "depropertyeditwidget.h"
#include <demo.h>

Q_DECLARE_METATYPE(Demo *)
//----------------------------------------------------------------------------
DePropertyEditWidget::DePropertyEditWidget(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	this->setWindowFlags(Qt::ToolTip);
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
void DePropertyEditWidget::on_btnOk_clicked()
{
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