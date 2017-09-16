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
	///���÷������
	void setTranlator(QTranslator *translator);

Q_SIGNALS:
	///��¼�ź�
	void signalLogin();
	///�ǳ��ź�
	void signalLogout();
	///������
	void signalRadiationCheck();

public Q_SLOTS:
	///�л�ҳ�浽ָ������
	void slotSetWidget(QWidget *widget);
	///������һ��ҳ��
	void slotBackMainWidget();
	void execTranslator();
	void setBLanguage(bool bLanguage);
	///��ʱ ��λ:����
	void eventSleep(int msec);

protected:
    virtual void changeEvent(QEvent *);

private:
	void initClickEvents();
	///���ó�ʼ״̬�˵��а�ť״̬

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
