#ifndef DEKEYBORADWIDGET_H
#define DEKEYBORADWIDGET_H

#include <QWidget>
#include "ui_dekeyboradwidget.h"

class DeKeyBoradWidget : public QWidget
{
	Q_OBJECT

public:
	enum KeyBoradType
	{
		Normal = 1,
		Password,
		Int,
		Float,
		Ip,
	};

	DeKeyBoradWidget(const QString &text, DeKeyBoradWidget::KeyBoradType type = DeKeyBoradWidget::Normal, QWidget *parent = 0);
	~DeKeyBoradWidget();

Q_SIGNALS:
	void signalOk(const QString &text);

public Q_SLOTS:
	void on_backBtn_clicked();
	void slotOkBtnClick();

private:
	Ui::DeKeyBoradWidget ui;
};

#endif // DEKEYBORADWIDGET_H
