#ifndef DESTATEMACHINE_H
#define DESTATEMACHINE_H

#include <QStateMachine>
#include "dedeviceselfcheckstate.h"
#include "demaintainstate.h"
#include "deradiationmmeasurestate.h"

///����һ��״̬��
class DeStateMachine : public QStateMachine
{
	Q_OBJECT

public:
	DeStateMachine(QObject *parent = 0);
	~DeStateMachine();

private:
	///��ʼ������״̬��Ϣ
	void initStates();
	///ע��״̬��ת�¼�
	void registerStateChangeEvents();

private:
	DeDeviceSelfCheckState *m_deviceCheckState;
	DeMaintainState *m_maintainState;
	DeRadiationMmeasureState *m_radiationMeasureState;
};

#endif // DESTATEMACHINE_H
