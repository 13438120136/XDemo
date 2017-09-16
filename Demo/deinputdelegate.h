#ifndef DEINPUTDELEGATE_H
#define DEINPUTDELEGATE_H

#include <QObject>
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



#endif // DEINPUTDELEGATE_H
