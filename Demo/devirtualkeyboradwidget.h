#ifndef DEVIRTUALKEYBORADWIDGET_H
#define DEVIRTUALKEYBORADWIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QSignalMapper>
#include "ui_devirtualkeyboradwidget.h"

class DeVirtualKeyboradWidget : public QWidget
{
	Q_OBJECT

public:
	DeVirtualKeyboradWidget(QWidget *parent = 0);
	~DeVirtualKeyboradWidget();

	void initAllKeyEvent();

	///��������ؼ�
	void setEditControl(QLineEdit *lineEdit);

public Q_SLOTS:
	///�ϵ������¼�
	void on_shiftBtn_clicked();
	///�ո��¼�
	void on_spaceBtn_clicked();
	///���˼��¼�
	void on_backBtn_clicked();
	///��������
	void on_hideBtn_clicked();
	///��Ӧ����
	void virtualKeyPressEvent(QWidget *button);
	//�л������ּ���
	void on_changeNumBtn_clicked();
	///�л�����ĸ����
	void on_changeCharBtn_clicked();

private:
	Ui::DeVirtualKeyboradWidget ui;
	QLineEdit *m_lineEdit;
	QSignalMapper *m_signalMapper;
};

#endif // DEVIRTUALKEYBORADWIDGET_H
