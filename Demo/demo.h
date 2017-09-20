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
	///关闭菜单信号
	void singalCloseMenu();

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
	///手心检测中
	void slotPalmChecking();
	///手背检测中
	void slotDorsumChecking();
	///手心污染了
	void slotPalmContaminated();
	///手背污染了
	void slotDorsumContaminated();
	///手心未污染
	void slotPalmNoContaminated();
	///手背未污染
	void slotDorsumNoContaminated();
	///重点部位测量
	void slotKeyMeasuring();
	///重点部位污染
	void slotKeyContaminated();
	///重点部位不污染
	void slotKeyNoContaminated();
	///位置错误
	void slotPositionError();

	///本地自检测界面
	void slotDeviceSelfChecking();
	///设备发生故障
	void slotDeviceFault(DeviceStatus device);
	///
	DeviceStatus &slotGetCurrentDeviceFault();
	///本地检测中
	void slotChecking();
	///请离开检测区
	void slotPleaseLeave();
	///准备就绪
	void slotReady();
	///请反转手掌
	void slotFlipPalm();

protected:
    virtual void changeEvent(QEvent *);
	virtual void timerEvent(QTimerEvent * event);
	virtual bool eventFilter(QObject *obj, QEvent *event);

private:
	Ui::DemoClass ui;
	QList<QWidget *> m_widgetStack;
	DeSqlDataBase m_sqlDatabase;
	QString m_loginStatus;
    bool m_currLanguage;
	QTranslator *m_translator;
	DeInitWidget *widget;

	///状态数据
	DeviceStatus m_deviceData;

	///记录起始时间
	quint64 m_startTimer;
};

#endif // DEMO_H
