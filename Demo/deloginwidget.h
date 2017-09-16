#ifndef DELOGINWIDGET_H
#define DELOGINWIDGET_H

#include <QDialog>
#include "ui_deloginwidget.h"

class DeLoginWidget : public QDialog
{
	Q_OBJECT

public:
	DeLoginWidget(QWidget *parent = 0);
	~DeLoginWidget();

	Q_SLOT void on_okBtn_clicked();
	Q_SLOT void on_cancelBtn_clicked();

private:
	Ui::DeLoginWidget ui;
};

#endif // DELOGINWIDGET_H
