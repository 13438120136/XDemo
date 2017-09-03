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

	///信息显示函数
	void showLabelMsg(const QString &msg);

public Q_SLOTS:
	void slotTimeOut();
	void on_exitBtn_clicked();
	void on_loginBtn_clicked();
    void on_chinaBtn_clicked();
    void on_englishBtn_clicked();

private:
	Ui::DeInitWidget ui;
};

#endif // DEINITWIDGET_H
