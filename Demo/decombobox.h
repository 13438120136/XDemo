#ifndef DECOMBOBOX_H
#define DECOMBOBOX_H

#include <QWidget>
#include "ui_decombobox.h"

///自定义combobox控件 通过按钮的方式来选择
class DeComboBox : public QWidget
{
	Q_OBJECT

public:
	DeComboBox(QWidget *parent = 0);
	~DeComboBox();

	void addItem(const QString &item);
	void setCurrentIndex(int index);
	int currentIndex();

public Q_SLOTS:
	///后一个内容
	void on_addBtn_clicked();
	///前一个内容
	void on_subBtn_clicked();

private:
	Ui::DeComboBox ui;

	QList<QString> m_data;
	int m_index;
};

#endif // DECOMBOBOX_H
