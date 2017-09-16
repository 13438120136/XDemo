#include "deloginwidget.h"
#include <demo.h>
#include <deusertable.h>
#include "demenuwidget.h"
#include "dekeyboradwidget.h"

Q_DECLARE_METATYPE(Demo *)
//----------------------------------------------------------------------------
DeLoginWidget::DeLoginWidget(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	this->setWindowFlags(Qt::ToolTip);

	ui.userLineEdit->installEventFilter(&m_inputTextDelegate);
	ui.passwdLineEdit->installEventFilter(&m_passwdDelegate);
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

	DeMenuWidget widget;	
	widget.move(demo->pos());
	widget.resize(demo->width(), demo->height());
	widget.setWindowOpacity(0.9);
	widget.exec();
}
//----------------------------------------------------------------------------
void DeLoginWidget::on_cancelBtn_clicked()
{
	Demo *demo = qApp->property("_mainWin").value<Demo *>();
	demo->slotBackMainWidget();
}
//----------------------------------------------------------------------------
