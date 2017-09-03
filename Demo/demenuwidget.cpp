#include "demenuwidget.h"
#include "deloginwidget.h"
#include "demangewidget.h"
#include "desystemconfigwidget.h"
#include "desystemtestwidget.h"
#include <demo.h>
#include <demessagebox.h>

Q_DECLARE_METATYPE(Demo *)
//----------------------------------------------------------------------------
DeMenuWidget::DeMenuWidget(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	m_isLogIn = false;
	this->setWindowFlags(Qt::ToolTip);
	m_demo = qApp->property("_mainWin").value<Demo *>();
}
//----------------------------------------------------------------------------
DeMenuWidget::~DeMenuWidget()
{

}
//----------------------------------------------------------------------------
void DeMenuWidget::on_userBtn_clicked()
{
	m_demo->slotBackMainWidget();
	DeManageWidget *window = new DeManageWidget(this);
	m_demo->slotSetWidget(window);
	accept();
}
//----------------------------------------------------------------------------
void DeMenuWidget::on_systemCfgBtn_clicked()
{
	m_demo->slotBackMainWidget();
	DeSystemConfigWidget *window = new DeSystemConfigWidget;
	m_demo->slotSetWidget(window);
	accept();
}
//----------------------------------------------------------------------------
void DeMenuWidget::on_systemTestBtn_clicked()
{
	m_demo->slotBackMainWidget();
	DeSystemTestWidget *window = new DeSystemTestWidget;
	m_demo->slotSetWidget(window);
	accept();
}
//----------------------------------------------------------------------------
void DeMenuWidget::on_exitBtn_clicked()
{
	reject();
}
//----------------------------------------------------------------------------
void DeMenuWidget::setDefaultButtonsStatus()
{
	ui.userBtn->setEnabled(false);
	ui.systemCfgBtn->setEnabled(false);
	ui.systemTestBtn->setEnabled(false);
	ui.logBtn->setEnabled(false);
}
//----------------------------------------------------------------------------
void DeMenuWidget::setMaintainButtonsStatus()
{
	ui.userBtn->setEnabled(true);
	ui.systemCfgBtn->setEnabled(true);
	ui.systemTestBtn->setEnabled(true);
	ui.logBtn->setEnabled(true);
}
//----------------------------------------------------------------------------