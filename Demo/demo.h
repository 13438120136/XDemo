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
	///��ȡ���ݿ����
	DeSqlDataBase *dataBase();
	///�豸�Լ�
	void deviceCheckSelf();
	///�豸���� ��Ҫ����
	void deviceFault();
	///ǿ�Ʊ��ױ���
	void deviceForceVariable();
	///���׼��
	void deviceVarCheck();
	///����ά��ģʽ
	void loginMaintainMode();
	///�˳�ά��ģʽ
	void logoutMaintainMode();
	///ִ�з�����
	void radiationChecking();
	///����״̬����¼��
	void setToolStatus(const QString &text, bool isLogin);

Q_SIGNALS:
	///��¼�ź�
	void signalLogin();
	///�ǳ��ź�
	void signalLogout();
	///������
	void signalRadiationCheck();

public Q_SLOTS:
	//��ʾ�˵���
	void slotShowMenu(bool bShow);
	///�л�ҳ�浽ָ������
	void slotSetWidget(QWidget *widget);
	///������һ��ҳ��
	void slotBackMainWidget();
    void translator(bool language);
    bool getLangeuage();

protected:
	virtual bool eventFilter(QObject *obj, QEvent *event);
    virtual void changeEvent(QEvent *);

private:
	void initClickEvents();
	///���ó�ʼ״̬�˵��а�ť״̬

private:
	Ui::DemoClass ui;
	bool m_isShowMenu;
	QList<QWidget *> m_widgetStack;
	DeSqlDataBase m_sqlDatabase;
	QString m_loginStatus;
    bool m_currLanguage;
};

#endif // DEMO_H
