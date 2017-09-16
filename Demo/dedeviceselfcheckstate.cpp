#include "dedeviceselfcheckstate.h"

Q_DECLARE_METATYPE(Demo *)
//----------------------------------------------------------------------------
DeDeviceSelfCheckState::DeDeviceSelfCheckState(QState *parent)
	: QState(parent)
{
	m_demo = qApp->property("_mainWin").value<Demo *>();
}
//----------------------------------------------------------------------------
DeDeviceSelfCheckState::~DeDeviceSelfCheckState()
{

}
//----------------------------------------------------------------------------
void DeDeviceSelfCheckState::onEntry(QEvent *event)
{
	Q_UNUSED(event);
}
//----------------------------------------------------------------------------