#ifndef DEBOTTOMMENUWIDGET_H
#define DEBOTTOMMENUWIDGET_H

#include <QWidget>
#include "ui_debottommenuwidget.h"

///�ײ��˵�
class DeBottomMenuWidget : public QWidget
{
	Q_OBJECT

public:
	DeBottomMenuWidget(QWidget *parent = 0);
	~DeBottomMenuWidget();

	Q_SLOT void leftButtonSlot();
	Q_SLOT void rightButtonSlot();

private:
	Ui::DeBottomMenuWidget ui;
};

#endif // DEBOTTOMMENUWIDGET_H
