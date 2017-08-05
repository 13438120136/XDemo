#ifndef DEMAINTAINSTATE_H
#define DEMAINTAINSTATE_H

#include <QState>
#include "demo.h"

///½øÈëÎ¬»¤×´Ì¬
class DeMaintainState : public QState
{
	Q_OBJECT

public:
	DeMaintainState(QState *parent = 0);
	~DeMaintainState();

protected:
    void onEntry(QEvent *event);
	void onExit(QEvent *event);
	
private:
	Demo *m_demo;
};

#endif // DEMAINTAINSTATE_H
