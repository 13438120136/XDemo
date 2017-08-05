#include "demessagebox.h"

//----------------------------------------------------------------------------
DeMessageBox::DeMessageBox(QWidget *parent)
	: QMessageBox(parent)
{
	setWindowFlags(Qt::ToolTip);
	setIcon(QMessageBox::Information);
	this->setStyleSheet("QLabel{font: 32px \"ËÎÌו\";}");
}
//----------------------------------------------------------------------------
DeMessageBox::~DeMessageBox()
{

}
//----------------------------------------------------------------------------
void DeMessageBox::resizeEvent(QResizeEvent *event)
{
	setFixedSize(300, 200);
	QMessageBox::resizeEvent(event);
}
//----------------------------------------------------------------------------