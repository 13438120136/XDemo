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
#include "dealermtable.h"

Q_DECLARE_METATYPE(Demo *)
//----------------------------------------------------------------------------
Demo::Demo(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	connect(this, SIGNAL(signalCommunication(int)), this, SLOT(slotCommunication(int)), Qt::QueuedConnection);

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

	QTimer::singleShot(3000, this, SLOT(slotBackMainWidget()));

	///////////////////////////////////////////////////
	m_startTimer = QDateTime::currentMSecsSinceEpoch();
	this->startTimer(10000);
	qApp->installEventFilter(this);

	slotCommunication(TYPE_BOTTOMCHECKING);
	return ;
	AlphaAndBeta &data = this->get_AlphaAndBeta();
	data.alarmStates[0] = 1;
	saveAlarmData();
	data.alarmStates[0] = 0;
		AlphaAndBeta &data1 = this->get_AlphaAndBeta();
	data1.alarmStates[1] = 1;
	saveAlarmData();
	data.alarmStates[1] = 0;

		AlphaAndBeta &data2 = this->get_AlphaAndBeta();
	data2.alarmStates[2] = 1;
	saveAlarmData();
	data.alarmStates[2] = 0;
		AlphaAndBeta &data3 = this->get_AlphaAndBeta();
	data3.alarmStates[3] = 1;
	saveAlarmData();
	data.alarmStates[3] = 0;

		AlphaAndBeta &data4 = this->get_AlphaAndBeta();
	data4.alarmStates[4] = 1;
	saveAlarmData();

	data.alarmStates[4] = 0;
		AlphaAndBeta &data5 = this->get_AlphaAndBeta();
	data5.alarmStates[5] = 1;
	saveAlarmData();
	data.alarmStates[5] = 0;
}
//----------------------------------------------------------------------------
Demo::~Demo()
{
	m_sqlDatabase.closeDataBase();
}
//----------------------------------------------------------------------------
void Demo::timerEvent(QTimerEvent *ev)
{
	Q_UNUSED(ev);

	quint64 currTime = QDateTime::currentMSecsSinceEpoch();
	///15分钟没有操作就退出登录
	if (currTime - m_startTimer > 1000 * 60 * 15)
	{
		while (m_widgetStack.size() > 1)
			slotBackMainWidget();

		emit singalCloseMenu();
	}
}
//----------------------------------------------------------------------------
bool Demo::eventFilter(QObject *obj, QEvent *event)
{
	switch (event->type())
	{
	case QEvent::MouseButtonRelease:
	case QEvent::MouseMove:
		m_startTimer = QDateTime::currentMSecsSinceEpoch();
		break;
	}

	return QObject::eventFilter(obj, event);
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
void Demo::communicate_with_demo(int type)
{
	emit signalCommunication(type);
}
//----------------------------------------------------------------------------
void Demo::slotCommunication(int type)
{
	switch(type)
	{
	case TYPE_BOTTOMCHECKING:
		widget->bottomWuran();
		break;
	case TYPE_DEVICESELFCHECK:
		widget->deviceSelfChecking();
		break;
	case TYPE_CHECKING:
		widget->deviceChecking();
		break;
	case TYPE_PLEASELEAVE:
		widget->pleaseLeave();
		break;
	case TYPE_READY:
		widget->ready();
		break;
	case TYPE_FLIPPALM:
		widget->flipPalm();
		break;
	case TYPE_PALMCHECKING:
		widget->palmWuran();
		break;
	case TYPE_DORSUMCHECKING:
		widget->dorsumWuran();
		break;
	case TYPE_PALMCONTAMINATED:
		widget->palmNoWuran();
		break;
	case TYPE_DORSUMCONTAMINATED:
		widget->dorsumWuran();
		break;
	case TYPE_PALMNOCONTAMINATED:
		widget->palmNoWuran();
		break;
	case TYPE_DORSUMNOCONTAMINATED:
		widget->dorsumNoWuran();
		break;
	case TYPE_KEYMEASURING:
		widget->keyPartMeasuring();
		break;
	case TYPE_KEYCONTAMINATED:
		widget->keyPartNoContaminated();
		break;
	case TYPE_POSITIONERROR:
		widget->posError();	
		break;
	case TYPE_CHANNELRESULT:
		emit signalChannelResult(this->get_ChannelResultData());
		break;
	case TYPE_XIAOLVRESULT:
		emit signalEffectResult(this->get_EffectResultData());
		break;
	}
}
//----------------------------------------------------------------------------
void Demo::saveAlarmData()
{
	AlphaAndBeta &data = this->get_AlphaAndBeta();
	DeAlermTable table(&m_sqlDatabase);

	QList<int> channelResult;
	for (int i = 0; i < 6; i++)
	{
		if (data.alarmStates[i] == 1)
			channelResult.append(i);
	}

	QByteArray byteArray((char *)&data, sizeof(data));

	table.setPolluteChannel(channelResult);
	table.setPolluteData(byteArray);
	table.insertDataToDataBase();
}
//----------------------------------------------------------------------------