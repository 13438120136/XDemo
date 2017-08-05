#ifndef DESTATEMACHINE_H
#define DESTATEMACHINE_H

#include <QStateMachine>
#include "dedeviceselfcheckstate.h"
#include "demaintainstate.h"
#include "deradiationmmeasurestate.h"

///定义一个状态机
class DeStateMachine : public QStateMachine
{
	Q_OBJECT

public:
	DeStateMachine(QObject *parent = 0);
	~DeStateMachine();

private:
	///初始化所有状态信息
	void initStates();
	///注册状态跳转事件
	void registerStateChangeEvents();

private:
	DeDeviceSelfCheckState *m_deviceCheckState;
	DeMaintainState *m_maintainState;
	DeRadiationMmeasureState *m_radiationMeasureState;
};

#endif // DESTATEMACHINE_H
