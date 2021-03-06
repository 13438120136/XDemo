#include "demodifyuserdlg.h"
#include "demo.h"
#include "deusertable.h"
#include <demessagebox.h>

Q_DECLARE_METATYPE(Demo *)
//----------------------------------------------------------------------------
DeModifyUserDlg::DeModifyUserDlg(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	ui.userLineEdit->installEventFilter(&m_inputTextDelegate);
	ui.passwdLineEdit->installEventFilter(&m_passwdDelegate);

	//暂时隐藏
	ui.label_3->hide();
	ui.widgePermission->hide();

	connect(ui.passwdLineEdit, SIGNAL(textChanged(const QString &)), this, SLOT(slotUserPasswdEdit(const QString &)));
}
//----------------------------------------------------------------------------
DeModifyUserDlg::~DeModifyUserDlg()
{

}
//----------------------------------------------------------------------------
void DeModifyUserDlg::on_okBtn_clicked()
{
	int permission = ui.widgePermission->currentIndex();

	Demo *demo = qApp->property("_mainWin").value<Demo *>();
	DeSqlDataBase *dataBase = demo->dataBase();
	DeUserTable data(dataBase);
	data.setUserName(ui.userLineEdit->text());
	data.setUserPasswd(ui.passwdLineEdit->text());
	data.setUserPermission(DeUserTable::UserPermission(permission));
	data.setUserPermissionName((permission == 0)
		?QString::fromLocal8Bit("管理员"):QString::fromLocal8Bit("维护人员"));

	///更新数据
	signalUpdateUser(data);
	demo->slotBackMainWidget();	
}
//----------------------------------------------------------------------------
void DeModifyUserDlg::on_cancelBtn_clicked()
{
	Demo *demo = qApp->property("_mainWin").value<Demo *>();
	demo->slotBackMainWidget();	
}
//----------------------------------------------------------------------------
void DeModifyUserDlg::setData(DeUserTable data)
{
	ui.userLineEdit->setText(data.getUerName());
	ui.widgePermission->addItem(QString::fromLocal8Bit("管理员"));
	ui.widgePermission->addItem(QString::fromLocal8Bit("维护人员"));
	ui.widgePermission->setCurrentIndex(data.getUserPermission());
}
//----------------------------------------------------------------------------
void DeModifyUserDlg::slotUserPasswdEdit(const QString &)
{
	QString passwd = ui.passwdLineEdit->text().trimmed();
	ui.okBtn->setEnabled(!passwd.isEmpty());
}
//----------------------------------------------------------------------------