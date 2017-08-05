#ifndef DEDEVICESELFCHECKSTATE_H
#define DEDEVICESELFCHECKSTATE_H

#include <QState>
#include "demo.h"

///�����ϵ��Լ�״̬
class DeDeviceSelfCheckState : public QState
{
	Q_OBJECT

public:
	DeDeviceSelfCheckState(QState *parent = 0);
	~DeDeviceSelfCheckState();

protected:
    void onEntry(QEvent *event);

private:
	Demo *m_demo;
};

#endif // DEDEVICESELFCHECKSTATE_H
