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
	///����ͨ�����
	void signalChannelResult(ChannelResultData);

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
	///��¼��ʼʱ��
	quint64 m_startTimer;

	///����ʹ�õ�����
	MEMBER(DeviceStatus, m_deviceData);
	MEMBER(AlphaAndBeta, m_alphaBetaData);
	MEMBER(KeyAlphaAndBeta, m_keyAlphaBetaData);
	MEMBER(PostionError, m_posError);
	MEMBER(ChannelResultData, m_channelResultData);
};

#endif // DEMO_H
