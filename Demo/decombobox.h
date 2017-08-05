#ifndef DECOMBOBOX_H
#define DECOMBOBOX_H

#include <QWidget>
#include "ui_decombobox.h"

///�Զ���combobox�ؼ� ͨ����ť�ķ�ʽ��ѡ��
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
	///��һ������
	void on_addBtn_clicked();
	///ǰһ������
	void on_subBtn_clicked();

private:
	Ui::DeComboBox ui;

	QList<QString> m_data;
	int m_index;
};

#endif // DECOMBOBOX_H
