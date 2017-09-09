#include "demessagebox.h"

//----------------------------------------------------------------------------
DeMessageBox::DeMessageBox(QWidget *parent)
	: QMessageBox(parent)
{
	setWindowFlags(Qt::ToolTip);
	setIcon(QMessageBox::Information);
	this->setStyleSheet("QLabel{font: 16px \"ºÚÌå\";} \
						QPushButton { \
						font: bold 16pt \"ºÚÌå\"; \
						border: 0px solid #8f8f91; \
						border-radius: 5px; \
						color: rgb(254, 255, 253); \
						background-color: rgb(66, 189, 170); \
						min-width: 100px; \
						min-height: 38px;  }");
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