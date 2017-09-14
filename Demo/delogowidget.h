#ifndef DELOGOWIDGET_H
#define DELOGOWIDGET_H

#include <QWidget>
#include "ui_delogowidget.h"

class DelogoWidget : public QWidget
{
	Q_OBJECT

public:
	DelogoWidget(QWidget *parent = 0);
	~DelogoWidget();

private:
	void playGif();

private:
	Ui::DelogoWidget ui;
};

#endif // DELOGOWIDGET_H
