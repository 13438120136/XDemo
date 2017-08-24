#include "deloginwidget.h"
#include <demo.h>
#include <deusertable.h>

Q_DECLARE_METATYPE(Demo *)
//----------------------------------------------------------------------------
DeLoginWidget::DeLoginWidget(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	ui.keyBoradWidget->hide();
	ui.userLineEdit->installEventFilter(this);
	ui.passwdLineEdit->installEventFilter(this);
	this->setWindowFlags(Qt::ToolTip);
}
//----------------------------------------------------------------------------
DeLoginWidget::~DeLoginWidget()
{

}
//----------------------------------------------------------------------------
void DeLoginWidget::on_okBtn_clicked()
{
	QString user = ui.userLineEdit->text();
	QString passwd = ui.passwdLineEdit->text();

	Demo *demo = qApp->property("_mainWin").value<Demo *>();
	DeSqlDataBase *dataBase = demo->dataBase();
	DeUserTable table(dataBase);
	table.setUserName(user);
	table.setUserPasswd(passwd);

	///是否合法 可以登录
	bool bOk = table.isValid();
	accept();
}
//----------------------------------------------------------------------------
void DeLoginWidget::on_cancelBtn_clicked()
{
	reject();
}
//----------------------------------------------------------------------------
bool DeLoginWidget::eventFilter(QObject *obj, QEvent *event)
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