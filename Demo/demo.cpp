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
#include "delogger.h"
#include <QTranslator>

Q_DECLARE_METATYPE(Demo *)
//----------------------------------------------------------------------------
Demo::Demo(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
	,m_isShowMenu(false)
{	
	///ע��Ϊȫ��Ψһ�������ڶ���
	QVariant variant; 
	variant.setValue(this);
	qApp->setProperty("_mainWin", variant);

	ui.setupUi(this);
	initClickEvents();
	this->setWindowFlags(Qt::FramelessWindowHint);
	m_loginStatus = QString::fromLocal8Bit("δ��¼");

	///��ʼ�����ݿ����
	m_sqlDatabase.openDataBase();
	///����ϵͳĬ���û�
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
void Demo::slotShowMenu(bool bShow)
{
	//ui.menuWidget->setVisible(bShow);
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
	//ui.menuWidget->setVisible(false);
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
	//ui.menuWidget->setDefaultButtonsStatus();
	//ui.menuWidget->setMaintainButtonsStatus();
	ui.widget->showLabelMsg(QString::fromLocal8Bit("�Լ���..... ���Ժ�"));
}
//----------------------------------------------------------------------------
void Demo::deviceFault()
{
	ui.widget->showLabelMsg(QString::fromLocal8Bit("�豸���� ��ά��"));
}
//----------------------------------------------------------------------------
void Demo::deviceForceVariable()
{
	ui.widget->showLabelMsg(QString::fromLocal8Bit("ǿ�Ʊ��ײ���"));
}
//----------------------------------------------------------------------------
void Demo::deviceVarCheck()
{
	ui.widget->showLabelMsg(QString::fromLocal8Bit("���׼��"));
}
//----------------------------------------------------------------------------
void Demo::loginMaintainMode()
{
	//ui.menuWidget->setMaintainButtonsStatus();
	ui.widget->showLabelMsg(QString::fromLocal8Bit("����ά��ģʽ"));
}
//----------------------------------------------------------------------------
void Demo::logoutMaintainMode()
{
	//ui.menuWidget->setDefaultButtonsStatus();
	ui.widget->showLabelMsg(QString::fromLocal8Bit("�˳�ά��ģʽ"));
}
//----------------------------------------------------------------------------
void Demo::radiationChecking()
{
	ui.widget->showLabelMsg(QString::fromLocal8Bit("���������"));
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