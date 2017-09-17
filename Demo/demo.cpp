#include "demo.h"
#include <QTimer>
#include <QDateTime>
#include <QVariant>
#include "detablemodel.h"
#include "detableview.h"
#include "detestdatamodel.h"
#include <deusertable.h>
#include <dedevicetable.h>
#include <deradioactivesourcetable.h>
#include "delogger.h"
#include <delogowidget.h>
#include <QTranslator>
#include <qdebug.h>

Q_DECLARE_METATYPE(Demo *)
//----------------------------------------------------------------------------
Demo::Demo(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{	
	///注册为全局唯一的主窗口对象
	QVariant variant; 
	variant.setValue(this);
	qApp->setProperty("_mainWin", variant);
	ui.setupUi(this);

	///首页
	widget = new DeInitWidget;
	slotSetWidget(widget);

	///显示欢迎界面
	DelogoWidget *logoWidget = new DelogoWidget;
	slotSetWidget(logoWidget);

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

	QTimer::singleShot(1000, this, SLOT(slotBackMainWidget()));
	slotPositionError();
}
//----------------------------------------------------------------------------
Demo::~Demo()
{
	m_sqlDatabase.closeDataBase();
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
void Demo::setToolStatus(const QString &text, bool isLogin)
{
	m_loginStatus = text;
	if (isLogin)
		emit signalLogin();
	else
		emit signalLogout();
}
//----------------------------------------------------------------------------
void Demo::changeEvent(QEvent *e)
{
    if (e->type() == QEvent::LanguageChange)
    {
        ui.retranslateUi(this);
    }
}
//----------------------------------------------------------------------------
void Demo::execTranslator()
{
	if (m_currLanguage)
		m_translator->load(":/Demo/demo_zh.qm");
	else
		m_translator->load(":/Demo/demo_en.qm");
	qApp->installTranslator(m_translator);
}
//----------------------------------------------------------------------------
void Demo::setTranlator(QTranslator *translator)
{
	m_translator = translator;
}
//----------------------------------------------------------------------------
void Demo::setBLanguage(bool bLanguage)
{
	m_currLanguage = bLanguage;
	if (bLanguage)
		m_translator->load(":/Demo/demo_zh.qm");
	else
		m_translator->load(":/Demo/demo_en.qm");
	qApp->installTranslator(m_translator);
}
//----------------------------------------------------------------------------
void Demo::eventSleep(int msec)
{
	QEventLoop ev;
	QTimer::singleShot(msec, &ev, SLOT(quit()));
	ev.exec();
}
//----------------------------------------------------------------------------
void Demo::slotDeviceSelfChecking()
{
	widget->deviceSelfChecking();
}
//----------------------------------------------------------------------------
void Demo::slotChecking()
{
	widget->deviceChecking();
}
//----------------------------------------------------------------------------
void Demo::slotPleaseLeave()
{
	widget->pleaseLeave();
}
//----------------------------------------------------------------------------
void Demo::slotPalmContaminated()
{
	widget->palmWuran();
}
//----------------------------------------------------------------------------
void Demo::slotDorsumContaminated()
{
	widget->dorsumWuran();
}
//----------------------------------------------------------------------------
void Demo::slotReady()
{
	widget->ready();
}
//----------------------------------------------------------------------------
void Demo::slotPalmNoContaminated()
{
	widget->palmNoWuran();
}
//----------------------------------------------------------------------------
void Demo::slotDorsumNoContaminated()
{
	widget->dorsumNoWuran();
}
//----------------------------------------------------------------------------
void Demo::slotKeyMeasuring()
{
	widget->keyPartMeasuring();
}
//----------------------------------------------------------------------------
void Demo::slotDeviceFault(DeviceStatus device)
{
	m_deviceData = device;
	widget->deviceFault(device);
}
//----------------------------------------------------------------------------
void Demo::slotPalmChecking()
{
	widget->palmChecking();
}
//----------------------------------------------------------------------------
void Demo::slotDorsumChecking()
{
	widget->dorsumChecking();
}
//----------------------------------------------------------------------------
void Demo::slotKeyContaminated()
{
	widget->keyPartContaminated();
}
//----------------------------------------------------------------------------
void Demo::slotKeyNoContaminated()
{
	widget->keyPartNoContaminated();
}
//----------------------------------------------------------------------------
void Demo::slotFlipPalm()
{
	widget->flipPalm();
}
//----------------------------------------------------------------------------
void Demo::slotPositionError()
{
	widget->posError();	
}
//----------------------------------------------------------------------------
DeviceStatus &slotGetCurrentDeviceFault()
{
	return m_deviceData;
}
//----------------------------------------------------------------------------