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

private:
	Ui::DeInitWidget ui;
};

#endif // DEINITWIDGET_H
