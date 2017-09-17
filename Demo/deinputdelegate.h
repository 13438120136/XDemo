#ifndef DEINPUTDELEGATE_H
#define DEINPUTDELEGATE_H

#include <QObject>
#include <QPushButton>
#include "dekeyboradwidget.h"

/* 这里列出所有的键盘输入代理类
   目的是用来对不同的输入作区分处理
 */

///处理普通的输入
class DeInputDelegate : public QObject
{
	Q_OBJECT

protected:
     bool eventFilter(QObject *obj, QEvent *event);	
};

///密码的方式输入
class DePasswordDelegate : public QObject
{
	Q_OBJECT

protected:
     bool eventFilter(QObject *obj, QEvent *event);	
};

///只能输入整数
class DeIntDelegate : public QObject
{
	Q_OBJECT

protected:
     bool eventFilter(QObject *obj, QEvent *event);	
};

///按钮ip输入
class DeButtonIPDelegate : public QObject
{
	Q_OBJECT

protected:
     bool eventFilter(QObject *obj, QEvent *event);	
	 QPushButton *m_button;

	public Q_SLOTS:
		void slotButtonChange(const QString &);
};

///按钮整数输入
class DeButtonIntDelegate : public QObject
{
	Q_OBJECT

protected:
     bool eventFilter(QObject *obj, QEvent *event);	
	 QPushButton *m_button;

	public Q_SLOTS:
		void slotButtonChange(const QString &);
};


///按钮小数输入
class DeButtonDoubleDelegate : public QObject
{
	Q_OBJECT

protected:
     bool eventFilter(QObject *obj, QEvent *event);	
	 QPushButton *m_button;

	public Q_SLOTS:
		void slotButtonChange(const QString &);
};


#endif // DEINPUTDELEGATE_H
