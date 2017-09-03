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
	void slotPhysicalTest(bool);
	void on_ioBtn_clicked();
	void on_channelBtn_clicked();
	void on_xiaolvBtn_clicked();
	void on_funcBtn_clicked();
	void on_logoutBtn_clicked();

protected:
	virtual bool eventFilter(QObject *obj, QEvent *event);

private:
	Ui::DeSystemTestWidget ui;
};

#endif // DESYSTEMTESTWIDGET_H
