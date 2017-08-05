#ifndef DESYSTEMTESTWIDGET_H
#define DESYSTEMTESTWIDGET_H

#include <QDialog>
#include "ui_desystemtestwidget.h"

class DeSystemTestWidget : public QDialog
{
	Q_OBJECT

public:
	DeSystemTestWidget(QWidget *parent = 0);
	~DeSystemTestWidget();

public Q_SLOTS:
	void on_okBtn_clicked();
	void slotPhysicalTest(bool);

protected:
	virtual bool eventFilter(QObject *obj, QEvent *event);

private:
	Ui::DeSystemTestWidget ui;
};

#endif // DESYSTEMTESTWIDGET_H
