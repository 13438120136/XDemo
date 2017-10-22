#ifndef DEVALUESELECTWIDGET_H
#define DEVALUESELECTWIDGET_H

#include <QWidget>
#include "ui_devalueselectwidget.h"
#include <QList>

class DeValueSelectWidget : public QWidget
{
	Q_OBJECT

public:
	DeValueSelectWidget(QWidget *parent = 0);
	~DeValueSelectWidget();

	void setValueList(const QList<int> &value);
	int getCurrentValue();
	QList<int> getValues();

Q_SIGNALS:
	void signalValueChanged(int currentIndex);

public Q_SLOTS:
	void on_prevBtn_clicked();
	void on_nextBtn_clicked();

private:
	Ui::DeValueSelectWidget ui;
	QList<int> m_valueList;
	int m_index;
};

#endif // DEVALUESELECTWIDGET_H
