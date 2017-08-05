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

	///�ϵ������¼�
	Q_SLOT void on_shiftBtn_clicked();
	///�ո��¼�
	Q_SLOT void on_spaceBtn_clicked();
	///���˼��¼�
	Q_SLOT void on_backBtn_clicked();
	///��������
	Q_SLOT void on_hideBtn_clicked();
	///��Ӧ����
	Q_SLOT void virtualKeyPressEvent(QWidget *button);

private:
	Ui::DeVirtualKeyboradWidget ui;
	QLineEdit *m_lineEdit;
	QSignalMapper *m_signalMapper;
};

#endif // DEVIRTUALKEYBORADWIDGET_H
