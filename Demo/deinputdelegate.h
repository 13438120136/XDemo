#ifndef DEINPUTDELEGATE_H
#define DEINPUTDELEGATE_H

#include <QObject>
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



#endif // DEINPUTDELEGATE_H
