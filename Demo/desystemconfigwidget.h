#ifndef DESYSTEMCONFIGWIDGET_H
#define DESYSTEMCONFIGWIDGET_H

#include <QDialog>
#include "ui_desystemconfigwidget.h"

class DeSystemConfigWidget : public QDialog
{
	Q_OBJECT

public:
	DeSystemConfigWidget(QWidget *parent = 0);
	~DeSystemConfigWidget();

public Q_SLOTS:
	void on_okBtn_clicked();
	void on_pushButton_4_clicked();

protected:
	virtual bool eventFilter(QObject *obj, QEvent *event);

private:
	Ui::DeSystemConfigWidget ui;
	bool m_isFullShow;
};

#endif // DESYSTEMCONFIGWIDGET_H
