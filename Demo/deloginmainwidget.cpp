#include "deloginmainwidget.h"
#include "demo.h"
#include "demenuwidget.h"
#include <QTimer>
#include <QDateTime>

Q_DECLARE_METATYPE(Demo *)
//----------------------------------------------------------------------------
DeLoginMainWidget::DeLoginMainWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	QTimer *timer = new QTimer(this);
	timer->start(500);
	connect(timer, SIGNAL(timeout()), this, SLOT(slotTimeOut()));
	slotTimeOut();
}
//----------------------------------------------------------------------------
DeLoginMainWidget::~DeLoginMainWidget()
{

}
//----------------------------------------------------------------------------
void DeLoginMainWidget::on_funcBtn_clicked()
{
	DeMenuWidget widget;	
	widget.exec();
}
//----------------------------------------------------------------------------
void DeLoginMainWidget::on_loginOut_clicked()
{
	Demo *demo = qApp->property("_mainWin").value<Demo *>();
	demo->slotBackMainWidget();
}
//----------------------------------------------------------------------------
void DeLoginMainWidget::slotTimeOut()
{
	QString timeString = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
	ui.label->setText(tr("%1").arg(timeString));
}
//----------------------------------------------------------------------------