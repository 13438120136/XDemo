#include "deadduserdlg.h"
#include <QListView>
#include "demo.h"
#include "deusertable.h"
#include <demessagebox.h>
#include <QTranslator>

Q_DECLARE_METATYPE(Demo *)
//----------------------------------------------------------------------------
DeAddUserDlg::DeAddUserDlg(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	ui.widgePermission->addItem(QString::fromLocal8Bit("管理员"));
	ui.widgePermission->addItem(QString::fromLocal8Bit("维护人员"));
	this->setWindowFlags(Qt::ToolTip);

	///暂时隐藏
	ui.label_3->hide();
	ui.widgePermission->hide();

	connect(ui.userLineEdit, SIGNAL(textChanged(const QString &)), this, SLOT(slotUserLineEdit(const QString &)));
	connect(ui.passwdLineEdit, SIGNAL(textChanged(const QString &)), this, SLOT(slotUserPasswdEdit(const QString &)));
}
//----------------------------------------------------------------------------
DeAddUserDlg::~DeAddUserDlg()
{

}
//----------------------------------------------------------------------------
void DeAddUserDlg::on_okBtn_clicked()
{
	QString user = ui.userLineEdit->text().trimmed();
	QString passwd = ui.passwdLineEdit->text().trimmed();
	int permission = ui.widgePermission->currentIndex();

	///保存数据库
	Demo *demo = qApp->property("_mainWin").value<Demo *>();
	DeSqlDataBase *dataBase = demo->dataBase();
	DeUserTable table(dataBase);
	table.setUserName(user);
	table.setUserPasswd(passwd);
	table.setUserPermission(DeUserTable::UserPermission(permission));
	table.setUserPermissionName((permission == 0)
		?QString::fromLocal8Bit("管理员"):QString::fromLocal8Bit("维护人员"));
	if (table.isExist())
	{
		DeMessageBox::warning(this, "", "exist");
		return ;
	}

	table.insertDataToDB();

	///更新界面
	emit signalAddUser(table);

	demo->slotBackMainWidget();	
}
//----------------------------------------------------------------------------
void DeAddUserDlg::on_cancelBtn_clicked()
{
	Demo *demo = qApp->property("_mainWin").value<Demo *>();
	demo->slotBackMainWidget();	
}
//----------------------------------------------------------------------------
void DeAddUserDlg::slotUserLineEdit(const QString & text)
{
	Q_UNUSED(text)
	QString user = ui.userLineEdit->text().trimmed();
	QString passwd = ui.passwdLineEdit->text().trimmed();
}
//----------------------------------------------------------------------------
void DeAddUserDlg::slotUserPasswdEdit(const QString & text)
{
	Q_UNUSED(text)
	QString user = ui.userLineEdit->text().trimmed();
	QString passwd = ui.passwdLineEdit->text().trimmed();
}
//----------------------------------------------------------------------------