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
	Q_UNUSED(event)
}
//----------------------------------------------------------------------------
void DeMaintainState::onExit(QEvent *event)
{
	Q_UNUSED(event)
}
//----------------------------------------------------------------------------