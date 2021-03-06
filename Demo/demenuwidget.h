#ifndef DEMENUWIDGET_H
#define DEMENUWIDGET_H

#include "ui_demenuwidget.h"
#include "demo.h"
#include <QDialog>
#include <QMap>
#include <QPainter>

class DeMenuWidget : public QDialog
{
	Q_OBJECT

	enum WidgetType
	{
		MANAGE,
		SYSTEM,
		TEST
	};

public:
	DeMenuWidget(QWidget *parent = 0);
	~DeMenuWidget();

	///���ò˵���ʾ״̬
	void setShowMenuStatus(int index = 0);

public Q_SLOTS:
	void on_userBtn_clicked();
	void on_systemCfgBtn_clicked();
	void on_systemTestBtn_clicked();
	void on_exitBtn_clicked();

private:
	Ui::DeMenuWidget ui;
	Demo *m_demo;
	bool m_isLogIn;
};

#endif // DEMENUWIDGET_H
