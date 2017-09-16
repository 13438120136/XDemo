#ifndef DEINITWIDGET_H
#define DEINITWIDGET_H

#include <QWidget>
#include "ui_deinitwidget.h"
#include <QMouseEvent>

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
	void deviceFault(bool first, bool sec, bool three, bool four);
	void deviceChecking();
	void pleaseLeave();
	void wuran();
	void ready();
	void nowuran();
	void keyPartMeasuring();

private:
	void playLabelForGif(QLabel *label, const QString &gif, int speed = 1);
private:
	Ui::DeInitWidget ui;
};

#endif // DEINITWIDGET_H
