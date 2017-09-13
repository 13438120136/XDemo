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

	///设置输入控件
	void setEditControl(QLineEdit *lineEdit);

public Q_SLOTS:
	///上档按键事件
	void on_shiftBtn_clicked();
	///空格事件
	void on_spaceBtn_clicked();
	///回退键事件
	void on_backBtn_clicked();
	///键盘隐藏
	void on_hideBtn_clicked();
	///响应按键
	void virtualKeyPressEvent(QWidget *button);
	//切换到数字键盘
	void on_changeNumBtn_clicked();
	///切换到字母键盘
	void on_changeCharBtn_clicked();

private:
	Ui::DeVirtualKeyboradWidget ui;
	QLineEdit *m_lineEdit;
	QSignalMapper *m_signalMapper;
};

#endif // DEVIRTUALKEYBORADWIDGET_H
