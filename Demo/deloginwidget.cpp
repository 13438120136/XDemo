#include "deloginwidget.h"
#include <demo.h>
#include <deusertable.h>
#include "demenuwidget.h"
#include <QTranslator>

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
	ui.okBtn->setFocus();

    retranslateUI();
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
void DeLoginWidget::retranslateUI()
{
    Demo *demo = qApp->property("_mainWin").value<Demo *>();
    QTranslator translator;
    if (demo->getLangeuage())
        translator.load(":/Demo/demo_zh.qm");
    else
        translator.load(":/Demo/demo_en.qm");
    qApp->installTranslator(&translator);
    ui.retranslateUi(this);
}
//----------------------------------------------------------------------------
