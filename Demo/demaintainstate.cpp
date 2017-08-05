#include "demaintainstate.h"

Q_DECLARE_METATYPE(Demo *)
//----------------------------------------------------------------------------
DeMaintainState::DeMaintainState(QState *parent)
	: QState(parent)
{
	m_demo = qApp->property("_mainWin").value<Demo *>();
}
//----------------------------------------------------------------------------
DeMaintainState::~DeMaintainState()
{

}
//----------------------------------------------------------------------------
void DeMaintainState::onEntry(QEvent *event)
{
	m_demo->loginMaintainMode();
}
//----------------------------------------------------------------------------
void DeMaintainState::onExit(QEvent *event)
{
	m_demo->logoutMaintainMode();
	m_demo->deviceForceVariable();
	m_demo->deviceVarCheck();
}
//----------------------------------------------------------------------------