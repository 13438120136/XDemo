#include "deloginwidget.h"


//----------------------------------------------------------------------------
DeLoginWidget::DeLoginWidget(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	ui.keyBoradWidget->hide();
	ui.userLineEdit->installEventFilter(this);
	ui.passwdLineEdit->installEventFilter(this);
	this->setWindowFlags(Qt::ToolTip);
}
//----------------------------------------------------------------------------
DeLoginWidget::~DeLoginWidget()
{

}
//----------------------------------------------------------------------------
void DeLoginWidget::on_okBtn_clicked()
{
	accept();
}
//----------------------------------------------------------------------------
void DeLoginWidget::on_cancelBtn_clicked()
{
	reject();
}
//----------------------------------------------------------------------------
bool DeLoginWidget::eventFilter(QObject *obj, QEvent *event)
 {
	 if (event->type() == QEvent::MouseButtonRelease) 
	 {
		 ui.keyBoradWidget->setEditControl((QLineEdit *)obj);
		 ui.keyBoradWidget->show();
         return true;
     }
	 else 
	 {
         // standard event processing
         return QObject::eventFilter(obj, event);
     }
 }
//----------------------------------------------------------------------------