#ifndef DEDEVICESELFCHECKSTATE_H
#define DEDEVICESELFCHECKSTATE_H

#include <QState>
#include "demo.h"

///ÒÇÆ÷ÉÏµç×Ô¼ì×´Ì¬
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
