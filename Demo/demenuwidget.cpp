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
	this->setWindowFlags(Qt::ToolTip);
	m_isLogIn = false;
	m_demo = qApp->property("_mainWin").value<Demo *>();
}
//----------------------------------------------------------------------------
DeMenuWidget::~DeMenuWidget()
{

}
//----------------------------------------------------------------------------
void DeMenuWidget::on_loginBtn_clicked()
{
	//m_isLogIn = !m_isLogIn;
	//if (!m_isLogIn)
	//{
	//	ui.loginBtn->setText(tr("Login"));
	//	m_demo->setToolStatus(QString::fromLocal8Bit("Î´µÇÂ¼"), false);
	//}
	//else
	//{
	//	DeLoginWidget *window = new DeLoginWidget;
	//	m_demo->slotSetWidget(window);
	//	if (window->exec() == QDialog::Accepted)
	//	{
	//		ui.loginBtn->setText(tr("Logout"));
	//		m_demo->setToolStatus(QString::fromLocal8Bit("ÒÑ¾­µÇÂ¼"), true);
	//	}

	//	m_demo->slotBackMainWidget();
	//}
}
//----------------------------------------------------------------------------
void DeMenuWidget::on_userBtn_clicked()
{
	DeManageWidget *window = new DeManageWidget(this);
	m_demo->slotSetWidget(window);
	accept();
}
//----------------------------------------------------------------------------
void DeMenuWidget::on_systemCfgBtn_clicked()
{
	DeSystemConfigWidget *window = new DeSystemConfigWidget;
	m_demo->slotSetWidget(window);
	accept();
}
//----------------------------------------------------------------------------
void DeMenuWidget::on_systemTestBtn_clicked()
{
	DeSystemTestWidget *window = new DeSystemTestWidget;
	m_demo->slotSetWidget(window);
	accept();
}
//----------------------------------------------------------------------------
void DeMenuWidget::on_exitBtn_clicked()
{
	DeMessageBox msgBox(this);
	msgBox.setText(tr("exit?"));
	QPushButton *okButton = msgBox.addButton(tr("yes"), QMessageBox::AcceptRole);  
	msgBox.addButton(tr("no"), QMessageBox::RejectRole); 
	msgBox.exec();
	if ((QPushButton*)msgBox.clickedButton() == okButton)  
		qApp->quit();
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