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

///�ӿڲ���
public Q_SLOTS:
	///�����Լ�����
	void slotDeviceSelfChecking();
	///�豸��������
	void slotDeviceFault(bool first, bool sec, bool three, bool four);
	///���ؼ����
	void slotChecking();
	///���뿪�����
	void slotPleaseLeave();
	///��Ⱦ��
	void slotContaminated();
	///׼������
	void slotReady();
	///δ��Ⱦ
	void slotNoContaminated();
	///�ص㲿λ����
	void slotKeyMeasuring();

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
