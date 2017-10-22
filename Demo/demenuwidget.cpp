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

	m_demo = qApp->property("_mainWin").value<Demo *>();
	connect(m_demo, SIGNAL(singalCloseMenu()), this, SLOT(accept()));

	this->setWindowFlags(Qt::ToolTip | Qt::FramelessWindowHint);
	this->setGeometry(m_demo->geometry());
	setAttribute(Qt::WA_TranslucentBackground, true);
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
	DeMessageBox msgBox;
	msgBox.setText(tr("exit?"));
	QPushButton *okButton = msgBox.addButton(tr("yes"), QMessageBox::AcceptRole);  
	msgBox.addButton(tr("no"), QMessageBox::RejectRole); 
	msgBox.exec();
	if ((QPushButton*)msgBox.clickedButton() == okButton)  
		qApp->quit();
}
//----------------------------------------------------------------------------
void DeMenuWidget::setShowMenuStatus(int index)
{
	switch(index)
	{
	case 1:
		{
			ui.label_3->setStyleSheet("image: url(:/Demo/Resources/gongnengyuanze-guanli-xuanzhong.png);");
			ui.userBtn->setStyleSheet("color:#42BDAA");
			break;
		}

	case 2:
		{
			ui.label_4->setStyleSheet("image: url(:/Demo/Resources/gongnengxuanze-shezhi-xuanzhong.png);");
			ui.systemCfgBtn->setStyleSheet("color:#42BDAA");
			break;
		}
	case 3:
		{
			ui.label_5->setStyleSheet("image: url(:/Demo/Resources/gongnengyuanze-xitongceshi-xuanzhong.png);");
			ui.systemTestBtn->setStyleSheet("color:#42BDAA");
			break;
		}
	case 4:
		{
			ui.label_6->setStyleSheet("image: url(:/Demo/Resources/gongnengyuanze-rizhi-xuanzhong.png);");
			ui.logBtn->setStyleSheet("color:#42BDAA");
			break;
		}
	case 5:
		{
			ui.exitBtn->setStyleSheet("color:#42BDAA");
			break;
		}
	default:
		break;
	}
}
//----------------------------------------------------------------------------
