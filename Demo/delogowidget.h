#ifndef DELOGOWIDGET_H
#define DELOGOWIDGET_H

#include <QWidget>
#include "ui_delogowidget.h"
#include <QMovie>

class DelogoWidget : public QWidget
{
	Q_OBJECT

public:
	DelogoWidget(QWidget *parent = 0);
	~DelogoWidget();

protected:
	void hideEvent(QHideEvent * event);

private:
	void playGif();

private:
	Ui::DelogoWidget ui;
	QMovie *m_movie;
};

#endif // DELOGOWIDGET_H
