#include "demodifyuserdlg.h"
#include "demo.h"
#include "deusertable.h"
#include <qmessagebox.h>
#include <QTranslator>

Q_DECLARE_METATYPE(Demo *)
//----------------------------------------------------------------------------
DeModifyUserDlg::DeModifyUserDlg(QWidget *parent)
	: QDialog(parent)
{
	Demo *demo = qApp->property("_mainWin").value<Demo *>();
	demo->execTranslator();

	ui.setupUi(this);

	ui.okBtn->setEnabled(false);
	ui.keyBoradWidget->hide();
	ui.passwdLineEdit->installEventFilter(this);

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
bool DeModifyUserDlg::eventFilter(QObject *obj, QEvent *event)
{
	if (event->type() == QEvent::MouseButtonRelease) 
	{
		ui.keyBoradWidget->setEditControl((QLineEdit *)obj);
		ui.keyBoradWidget->show();
		return true;
	}
	else 
	{
		// standard event processing
		return QObject::eventFilter(obj, event);
	}
}
//----------------------------------------------------------------------------
void DeModifyUserDlg::on_okBtn_clicked()
{
	int permission = ui.widgePermission->currentIndex();

	Demo *demo = qApp->property("_mainWin").value<Demo *>();
	DeSqlDataBase *dataBase = demo->dataBase();
	DeUserTable data(dataBase);
	data.setUserName(ui.userLineEdit->text());
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