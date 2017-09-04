#ifndef DEMENUWIDGET_H
#define DEMENUWIDGET_H

#include <QDialog>
#include <QMap>
#include "ui_demenuwidget.h"
#include "demo.h"

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

	void setDefaultButtonsStatus();
	void setMaintainButtonsStatus();

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
