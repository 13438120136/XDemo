#include "demo.h"
#include <QTimer>
#include <QDateTime>
#include <QVariant>
#include "detablemodel.h"
#include "detableview.h"
#include "detestdatamodel.h"
#include <deinitwidget.h>
#include <deusertable.h>
#include <dedevicetable.h>
#include <deradioactivesourcetable.h>

Q_DECLARE_METATYPE(Demo *)
//----------------------------------------------------------------------------
Demo::Demo(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
	,m_isShowMenu(false)
{	
	///注册为全局唯一的主窗口对象
	QVariant variant; 
	variant.setValue(this);
	qApp->setProperty("_mainWin", variant);

	ui.setupUi(this);
	initClickEvents();
	this->setWindowFlags(Qt::FramelessWindowHint);
	m_loginStatus = QString::fromLocal8Bit("未登录");

	///初始化数据库对象
	m_sqlDatabase.openDataBase();
	///建立系统默认用户
	DeUserTable userTable(&m_sqlDatabase);
	if (userTable.isEmptyTable())
	{
		userTable.setUserName("admin");
		userTable.setUserPasswd("123456");
		userTable.setUserPermissionName(tr("sys user"));
		userTable.setUserPermission(DeUserTable::ADMIN);
		userTable.insertDataToDB();
	}
}
//----------------------------------------------------------------------------
Demo::~Demo()
{
	m_sqlDatabase.closeDataBase();
}
//----------------------------------------------------------------------------
void Demo::slotTimeOut()
{
	QString timeString = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
	QString versionString = "V1.0";
	ui.statusBar->showMessage(tr("当前时间:%1     软件版本:%2   %3").arg(timeString).arg(versionString).arg(m_loginStatus));
}
//----------------------------------------------------------------------------
void Demo::slotShowMenu(bool bShow)
{
	ui.menuWidget->setVisible(bShow);
}
//----------------------------------------------------------------------------
bool Demo::eventFilter(QObject *obj, QEvent *event)
 {
	 if (event->type() == QEvent::MouseButtonRelease) 
	 {
		 m_isShowMenu = !m_isShowMenu;
		 slotShowMenu(m_isShowMenu);
         return true;
     }
	 else 
	 {
         // standard event processing
         return QObject::eventFilter(obj, event);
     }
 }
//----------------------------------------------------------------------------
void Demo::initClickEvents()
{
	ui.widget->installEventFilter(this);
	ui.menuWidget->setVisible(false);

	QTimer *timer = new QTimer(this);
	timer->start(500);
	connect(timer, SIGNAL(timeout()), this, SLOT(slotTimeOut()));
	slotTimeOut();
}
//----------------------------------------------------------------------------
void Demo::slotSetWidget(QWidget *widget)
{
	m_widgetStack.push_back(widget);
	ui.contentWidget->addWidget(widget);
	ui.contentWidget->setCurrentWidget(widget);
}
//----------------------------------------------------------------------------
void Demo::slotBackMainWidget()
{
	if (m_widgetStack.isEmpty())
	{
		ui.contentWidget->setCurrentIndex(0);
	}
	else
	{
		QWidget *widget = m_widgetStack.takeLast();
		ui.contentWidget->removeWidget(widget);
		delete widget;

		if (!m_widgetStack.isEmpty())
			ui.contentWidget->setCurrentWidget(m_widgetStack.last());
		else
			ui.contentWidget->setCurrentIndex(0);
	}
}
//----------------------------------------------------------------------------
DeSqlDataBase *Demo::dataBase()
{
	return &m_sqlDatabase;
}
//----------------------------------------------------------------------------
void Demo::deviceCheckSelf()
{
	ui.menuWidget->setDefaultButtonsStatus();
	//ui.menuWidget->setMaintainButtonsStatus();
	ui.widget->showLabelMsg(QString::fromLocal8Bit("自检中..... 请稍后"));
}
//----------------------------------------------------------------------------
void Demo::deviceFault()
{
	ui.widget->showLabelMsg(QString::fromLocal8Bit("设备故障 请维修"));
}
//----------------------------------------------------------------------------
void Demo::deviceForceVariable()
{
	ui.widget->showLabelMsg(QString::fromLocal8Bit("强制本底测量"));
}
//----------------------------------------------------------------------------
void Demo::deviceVarCheck()
{
	ui.widget->showLabelMsg(QString::fromLocal8Bit("本底检测"));
}
//----------------------------------------------------------------------------
void Demo::loginMaintainMode()
{
	ui.menuWidget->setMaintainButtonsStatus();
	ui.widget->showLabelMsg(QString::fromLocal8Bit("进入维护模式"));
}
//----------------------------------------------------------------------------
void Demo::logoutMaintainMode()
{
	ui.menuWidget->setDefaultButtonsStatus();
	ui.widget->showLabelMsg(QString::fromLocal8Bit("退出维护模式"));
}
//----------------------------------------------------------------------------
void Demo::radiationChecking()
{
	ui.widget->showLabelMsg(QString::fromLocal8Bit("进入辐射检测"));
}
//----------------------------------------------------------------------------
void Demo::setToolStatus(const QString &text, bool isLogin)
{
	m_loginStatus = text;
	if (isLogin)
		emit signalLogin();
	else
		emit signalLogout();
}
//----------------------------------------------------------------------------
