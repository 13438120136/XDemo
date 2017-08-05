#include "deinitwidget.h"
#include <qeventloop.h>
#include <QTimer>

//----------------------------------------------------------------------------
DeInitWidget::DeInitWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}
//----------------------------------------------------------------------------
DeInitWidget::~DeInitWidget()
{

}
//----------------------------------------------------------------------------
void DeInitWidget::showLabelMsg(const QString &msg)
{
	ui.msgLabel->setText(msg);
}
//----------------------------------------------------------------------------
