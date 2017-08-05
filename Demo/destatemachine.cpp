#include "destatemachine.h"
#include "demo.h"

Q_DECLARE_METATYPE(Demo *)
//----------------------------------------------------------------------------
DeStateMachine::DeStateMachine(QObject *parent)
	: QStateMachine(parent)
{
	initStates();
	registerStateChangeEvents();
}
//----------------------------------------------------------------------------
DeStateMachine::~DeStateMachine()
{

}
//----------------------------------------------------------------------------
void DeStateMachine::initStates()
{
	///设备自检
	m_deviceCheckState = new DeDeviceSelfCheckState();
	this->addState(m_deviceCheckState);

	///维护状态
	m_maintainState = new DeMaintainState();
	this->addState(m_maintainState);

	///辐射检测状态
	m_radiationMeasureState = new DeRadiationMmeasureState();
	this->addState(m_radiationMeasureState);

	///初始化为设备自检
	this->setInitialState(m_deviceCheckState);
}
//----------------------------------------------------------------------------
void DeStateMachine::registerStateChangeEvents()
{
	Demo *demo = qApp->property("_mainWin").value<Demo *>();

	m_deviceCheckState->addTransition(demo, SIGNAL(signalLogin()), m_maintainState);
	m_deviceCheckState->addTransition(demo, SIGNAL(signalRadiationCheck()), m_radiationMeasureState);
	m_maintainState->addTransition(demo, SIGNAL(signalLogout()), m_deviceCheckState);
}
//----------------------------------------------------------------------------