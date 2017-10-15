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
	///�رղ˵��ź�
	void singalCloseMenu();
	void signalCommunication(int type);

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
	void slotDeviceFault(DeviceStatus device);
	///
	DeviceStatus &slotGetCurrentDeviceFault();
	///���ؼ����
	void slotChecking();
	///���뿪�����
	void slotPleaseLeave();
	///׼������
	void slotReady();
	///�뷴ת����
	void slotFlipPalm();

	///��ײ�ͨѶ������
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

	///״̬����
	//DeviceStatus m_deviceData;
	///��¼��ʼʱ��
	quint64 m_startTimer;

	///����ʹ�õ�����
	DEFINESTRUCT(DeviceStatus, m_deviceData);
};

#endif // DEMO_H
