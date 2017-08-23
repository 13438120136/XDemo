#ifndef DEPROPERTYEDITWIDGET_H
#define DEPROPERTYEDITWIDGET_H

#include <QDialog>
#include "ui_depropertyeditwidget.h"

class DePropertyEditWidget : public QDialog
{
	Q_OBJECT

public:
	DePropertyEditWidget(QWidget *parent = 0);
	~DePropertyEditWidget();

	void setHeadTitle(const QString &title);

public Q_SLOTS:
	void on_btnOk_clicked();
	void on_btnCancel_clicked();

private:
	Ui::DePropertyEditWidget ui;
};

#endif // DEPROPERTYEDITWIDGET_H
