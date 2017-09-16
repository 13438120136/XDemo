#include "demessagebox.h"

//----------------------------------------------------------------------------
DeMessageBox::DeMessageBox(QWidget *parent)
	: QMessageBox(parent)
{
	setWindowFlags(Qt::ToolTip);
	setIcon(QMessageBox::Information);
	this->setStyleSheet("QLabel{font: 14px \"Î¢ÈíÑÅºÚ\";} \
						QPushButton { \
						font: 14pt \"Î¢ÈíÑÅºÚ\"; \
						border: none; \
						border-radius: 5px; \
						color: #FFFFFF; \
						background-color:  #42BDAA; \
						min-width: 100px; \
						min-height: 30px;  }");
}
//----------------------------------------------------------------------------
DeMessageBox::~DeMessageBox()
{

}
//----------------------------------------------------------------------------
void DeMessageBox::resizeEvent(QResizeEvent *event)
{
	setFixedSize(300, 140);
	QMessageBox::resizeEvent(event);
}
//----------------------------------------------------------------------------