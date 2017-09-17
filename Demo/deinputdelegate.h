#ifndef DEINPUTDELEGATE_H
#define DEINPUTDELEGATE_H

#include <QObject>
#include <QPushButton>
#include "dekeyboradwidget.h"

/* �����г����еļ������������
   Ŀ���������Բ�ͬ�����������ִ���
 */

///������ͨ������
class DeInputDelegate : public QObject
{
	Q_OBJECT

protected:
     bool eventFilter(QObject *obj, QEvent *event);	
};

///����ķ�ʽ����
class DePasswordDelegate : public QObject
{
	Q_OBJECT

protected:
     bool eventFilter(QObject *obj, QEvent *event);	
};

///ֻ����������
class DeIntDelegate : public QObject
{
	Q_OBJECT

protected:
     bool eventFilter(QObject *obj, QEvent *event);	
};

///��ťip����
class DeButtonIPDelegate : public QObject
{
	Q_OBJECT

protected:
     bool eventFilter(QObject *obj, QEvent *event);	
	 QPushButton *m_button;

	public Q_SLOTS:
		void slotButtonChange(const QString &);
};

///��ť��������
class DeButtonIntDelegate : public QObject
{
	Q_OBJECT

protected:
     bool eventFilter(QObject *obj, QEvent *event);	
	 QPushButton *m_button;

	public Q_SLOTS:
		void slotButtonChange(const QString &);
};


///��ťС������
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
