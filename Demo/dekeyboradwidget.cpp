#include "dekeyboradwidget.h"
#include "demo.h"

Q_DECLARE_METATYPE(Demo *)
//----------------------------------------------------------------------------
DeKeyBoradWidget::DeKeyBoradWidget(const QString &text, DeKeyBoradWidget::KeyBoradType type, QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.lineEdit->setText(text);
	ui.widget_2->setEditControl(ui.lineEdit);
	connect(ui.widget_2, SIGNAL(signalOk()), this, SLOT(slotOkBtnClick()));

	switch(type)
	{
	case Normal:
		{
			ui.lineEdit->setEchoMode(QLineEdit::Normal);
			break;
		}
	case Password:
		{
			ui.lineEdit->setEchoMode(QLineEdit::Password);
			break;
		}
	}
}
//----------------------------------------------------------------------------
DeKeyBoradWidget::~DeKeyBoradWidget()
{

}
//----------------------------------------------------------------------------
void DeKeyBoradWidget::on_backBtn_clicked()
{
	Demo *demo = qApp->property("_mainWin").value<Demo *>();
	demo->slotBackMainWidget();
}
//----------------------------------------------------------------------------
void DeKeyBoradWidget::slotOkBtnClick()
{
	QString str = ui.lineEdit->text();
	emit signalOk(str);
	Demo *demo = qApp->property("_mainWin").value<Demo *>();
	demo->slotBackMainWidget();	
}
//----------------------------------------------------------------------------