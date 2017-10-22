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
	///本底检测
	void deviceChecking();
	///请离开
	void pleaseLeave();
	///本底污染状态
	void bottomWuran();
	
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

	///反转手掌
	void flipPalm();
	///位置错误
	void posError();

private:
	void playLabelForGif(QLabel *label, const QString &gif, int speed = 1);
	void stopLabelForGif(QLabel *label);

private:
	Ui::DeInitWidget ui;
};

#endif // DEINITWIDGET_H
