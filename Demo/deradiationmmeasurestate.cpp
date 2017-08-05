#include "deradiationmmeasurestate.h"

Q_DECLARE_METATYPE(Demo *)
//----------------------------------------------------------------------------
DeRadiationMmeasureState::DeRadiationMmeasureState(QState *parent)
	: QState(parent)
{
	m_demo = qApp->property("_mainWin").value<Demo *>();
}
//----------------------------------------------------------------------------
DeRadiationMmeasureState::~DeRadiationMmeasureState()
{

}
//----------------------------------------------------------------------------
void DeRadiationMmeasureState::onEntry(QEvent *event)
{
	m_demo->radiationChecking();
}
//----------------------------------------------------------------------------
void DeRadiationMmeasureState::onExit(QEvent *event)
{
}
//----------------------------------------------------------------------------