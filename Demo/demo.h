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
	void signalCommunication(int type);
	///更新通道结果
	void signalChannelResult(ChannelResultData);

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
	///与底层通讯数据区
	void communicate_with_demo(int type);
	void slotCommunication(int type);

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
	///记录起始时间
	quint64 m_startTimer;

	///定义使用的数据
	MEMBER(DeviceStatus, m_deviceData);
	MEMBER(AlphaAndBeta, m_alphaBetaData);
	MEMBER(KeyAlphaAndBeta, m_keyAlphaBetaData);
	MEMBER(PostionError, m_posError);
	MEMBER(ChannelResultData, m_channelResultData);
};

#endif // DEMO_H
