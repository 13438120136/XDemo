#ifndef DEMO_H
#define DEMO_H

#include <QtGui/QMainWindow>
#include "ui_demo.h"
#include <desqldatabase.h>

class Demo : public QMainWindow
{
	Q_OBJECT

public:
	Demo(QWidget *parent = 0, Qt::WFlags flags = 0);
	~Demo();
	///获取数据库对象
	DeSqlDataBase *dataBase();
	///设备自检
	void deviceCheckSelf();
	///设备故障 需要处理
	void deviceFault();
	///强制本底变量
	void deviceForceVariable();
	///本底检测
	void deviceVarCheck();
	///进入维护模式
	void loginMaintainMode();
	///退出维护模式
	void logoutMaintainMode();
	///执行辐射检测
	void radiationChecking();
	///设置状态栏登录名
	void setToolStatus(const QString &text, bool isLogin);

Q_SIGNALS:
	///登录信号
	void signalLogin();
	///登出信号
	void signalLogout();
	///辐射检测
	void signalRadiationCheck();

public Q_SLOTS:
	//显示菜单栏
	void slotShowMenu(bool bShow);
	///切换页面到指定窗口
	void slotSetWidget(QWidget *widget);
	///返回上一级页面
	void slotBackMainWidget();
    void translator(bool language);
    bool getLangeuage();

protected:
	virtual bool eventFilter(QObject *obj, QEvent *event);
    virtual void changeEvent(QEvent *);

private:
	void initClickEvents();
	///设置初始状态菜单中按钮状态

private:
	Ui::DemoClass ui;
	bool m_isShowMenu;
	QList<QWidget *> m_widgetStack;
	DeSqlDataBase m_sqlDatabase;
	QString m_loginStatus;
    bool m_currLanguage;
};

#endif // DEMO_H
