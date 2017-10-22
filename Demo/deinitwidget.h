#ifndef DEINITWIDGET_H
#define DEINITWIDGET_H

#include <QWidget>
#include "ui_deinitwidget.h"
#include <QMouseEvent>
#include <decommondef.h>

class DeInitWidget : public QWidget
{
	Q_OBJECT

public:
	DeInitWidget(QWidget *parent = 0);
	~DeInitWidget();

	///��Ϣ��ʾ����
	void showLabelMsg(const QString &msg);

public Q_SLOTS:
	void slotTimeOut();
	void on_exitBtn_clicked();
	void on_loginBtn_clicked();
    void on_chinaBtn_clicked();
    void on_englishBtn_clicked();
	///û�е�¼ʱ��İ�ť
	void on_deviceBtn_clicked();

	///��Ҫ��Demo���õ�
	void deviceSelfChecking();
	void deviceFault(DeviceStatus device);
	///���׼��
	void deviceChecking();
	///���뿪
	void pleaseLeave();
	///������Ⱦ״̬
	void bottomWuran();
	
	void ready();

	///�ص㲿λ
	void keyPartMeasuring();
	///�ص���Ⱦ
	void keyPartContaminated();
	///�ص㲻��Ⱦ
	void keyPartNoContaminated();

	///����
	void palmChecking();
	void palmWuran();
	void palmNoWuran();

	///�ֱ�
	void dorsumChecking();
	void dorsumWuran();
	void dorsumNoWuran();

	///��ת����
	void flipPalm();
	///λ�ô���
	void posError();

private:
	void playLabelForGif(QLabel *label, const QString &gif, int speed = 1);
	void stopLabelForGif(QLabel *label);

private:
	Ui::DeInitWidget ui;
};

#endif // DEINITWIDGET_H
