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

	///信息显示函数
	void showLabelMsg(const QString &msg);

public Q_SLOTS:
	void slotTimeOut();
	void on_exitBtn_clicked();
	void on_loginBtn_clicked();
    void on_chinaBtn_clicked();
    void on_englishBtn_clicked();
	///没有登录时候的按钮
	void on_deviceBtn_clicked();

	///需要被Demo调用的
	void deviceSelfChecking();
	void deviceFault(DeviceStatus device);
	void deviceChecking();
	void pleaseLeave();
	
	void ready();

	///重点部位
	void keyPartMeasuring();
	///重点污染
	void keyPartContaminated();
	///重点不污染
	void keyPartNoContaminated();

	///手心
	void palmChecking();
	void palmWuran();
	void palmNoWuran();

	///手背
	void dorsumChecking();
	void dorsumWuran();
	void dorsumNoWuran();

private:
	void playLabelForGif(QLabel *label, const QString &gif, int speed = 1);

private:
	Ui::DeInitWidget ui;
};

#endif // DEINITWIDGET_H
