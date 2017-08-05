#ifndef DERADIATIONMMEASURESTATE_H
#define DERADIATIONMMEASURESTATE_H

#include <QState>
#include "demo.h"

///½øÈë·øÉä²âÁ¿×´Ì¬
class DeRadiationMmeasureState : public QState
{
	Q_OBJECT

public:
	DeRadiationMmeasureState(QState *parent = 0);
	~DeRadiationMmeasureState();

protected:
    void onEntry(QEvent *event);
	void onExit(QEvent *event);

private:
	Demo *m_demo;
};

#endif // DERADIATIONMMEASURESTATE_H
