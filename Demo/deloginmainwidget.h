#ifndef DELOGINMAINWIDGET_H
#define DELOGINMAINWIDGET_H

#include <QWidget>
#include "ui_deloginmainwidget.h"

class DeLoginMainWidget : public QWidget
{
	Q_OBJECT

public:
	DeLoginMainWidget(QWidget *parent = 0);
	~DeLoginMainWidget();

public Q_SLOTS:
	void on_funcBtn_clicked();
	void on_loginOut_clicked();
	void slotTimeOut();

private:
	Ui::DeLoginMainWidget ui;
};

#endif // DELOGINMAINWIDGET_H
