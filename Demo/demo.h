#ifndef DEMO_H
#define DEMO_H

#include <QtGui/QMainWindow>
#include "ui_demo.h"
#include <desqldatabase.h>
#include <deinitwidget.h>

class Demo : public QMainWindow
{
	Q_OBJECT

public:
	Demo(QWidget *parent = 0, Qt::WFlags flags = 0);
	~Demo();
	///获取数据库对象
	DeSqlDataBase *dataBase();
	///设置状态栏登录名
	void setToolStatus(const QString &text, bool isLogin);
	///设置翻译对象
	void setTranlator(QTranslator *translator);

Q_SIGNALS:
	///登录信号
	void signalLogin();
	///登出信号
	void signalLogout();
	///辐射检测
	void signalRadiationCheck();

public Q_SLOTS:
	///切换页面到指定窗口
	void slotSetWidget(QWidget *widget);
	///返回上一级页面
	void slotBackMainWidget();
	void execTranslator();
	void setBLanguage(bool bLanguage);
	///延时 单位:毫秒
	void eventSleep(int msec);

///接口部分
public Q_SLOTS:
	///本地自检测界面
	void slotDeviceSelfChecking();
	///设备发生故障
	void slotDeviceFault(bool first, bool sec, bool three, bool four);
	///本地检测中
	void slotChecking();
	///请离开检测区
	void slotPleaseLeave();
	///污染了
	void slotContaminated();
	///准备就绪
	void slotReady();
	///未污染
	void slotNoContaminated();
	///重点部位测量
	void slotKeyMeasuring();

protected:
    virtual void changeEvent(QEvent *);

private:
	void initClickEvents();
	///设置初始状态菜单中按钮状态

private:
	Ui::DemoClass ui;
	QList<QWidget *> m_widgetStack;
	DeSqlDataBase m_sqlDatabase;
	QString m_loginStatus;
    bool m_currLanguage;
	QTranslator *m_translator;
	DeInitWidget *widget;
};

#endif // DEMO_H
