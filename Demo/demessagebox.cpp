#include "demessagebox.h"

//----------------------------------------------------------------------------
DeMessageBox::DeMessageBox(QWidget *parent)
	: QMessageBox(parent)
{
	setWindowFlags(Qt::ToolTip);
	setIcon(QMessageBox::Information);
	this->setStyleSheet("QLabel{font: 20px \"����\";}");
}
//----------------------------------------------------------------------------
DeMessageBox::~DeMessageBox()
{

}
//----------------------------------------------------------------------------
void DeMessageBox::resizeEvent(QResizeEvent *event)
{
	setFixedSize(300, 160);
	QMessageBox::resizeEvent(event);
}
//----------------------------------------------------------------------------