#include "demenuwidget.h"
#include "deloginwidget.h"
#include "demangewidget.h"
#include "desystemconfigwidget.h"
#include "desystemtestwidget.h"
#include <demessagebox.h>
#include "demo.h"

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
	m_demo->slotSetWidget(new DeManageWidget);
	accept();
}
//----------------------------------------------------------------------------
void DeMenuWidget::on_systemCfgBtn_clicked()
{
	m_demo->slotBackMainWidget();
	m_demo->slotSetWidget(new DeSystemConfigWidget);
	accept();
}
//----------------------------------------------------------------------------
void DeMenuWidget::on_systemTestBtn_clicked()
{
	m_demo->slotBackMainWidget();
	m_demo->slotSetWidget(new DeSystemTestWidget);
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