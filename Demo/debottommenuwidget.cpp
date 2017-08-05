#include "debottommenuwidget.h"
#include "demenuwidget.h"
#include <QScrollBar>

//----------------------------------------------------------------------------
DeBottomMenuWidget::DeBottomMenuWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	connect(ui.leftBtn, SIGNAL(clicked()), this, SLOT(leftButtonSlot()));
	connect(ui.rightBtn, SIGNAL(clicked()), this, SLOT(rightButtonSlot()));

	DeMenuWidget *menu = new DeMenuWidget(this);
	ui.scrollArea->setWidget(menu);
}
//----------------------------------------------------------------------------
DeBottomMenuWidget::~DeBottomMenuWidget()
{

}
//----------------------------------------------------------------------------
void DeBottomMenuWidget::leftButtonSlot()
{
	QScrollBar *scrollBar = ui.scrollArea->horizontalScrollBar();
	int min = scrollBar->minimum();
	int max = scrollBar->maximum();

	int value = scrollBar->value();
	if (value == 0)
		return ;

	int step = value - 200;
	if (step <= 0)
		step = 0;

	scrollBar->setValue(step);
}
//----------------------------------------------------------------------------
void DeBottomMenuWidget::rightButtonSlot()
{
	QScrollBar *scrollBar = ui.scrollArea->horizontalScrollBar();
	int min = scrollBar->minimum();
	int max = scrollBar->maximum();

	int value = scrollBar->value();
	if (value == max)
		return ;

	int step = value + 200;
	if (step >= max)
		step = max;

	scrollBar->setValue(step);
}
//----------------------------------------------------------------------------
void DeBottomMenuWidget::setDefaultButtonsStatus()
{
	DeMenuWidget *menu = (DeMenuWidget *)ui.scrollArea->widget();
	menu->setDefaultButtonsStatus();
}
//----------------------------------------------------------------------------
void DeBottomMenuWidget::setMaintainButtonsStatus()
{
	DeMenuWidget *menu = (DeMenuWidget *)ui.scrollArea->widget();
	menu->setMaintainButtonsStatus();
}
//----------------------------------------------------------------------------