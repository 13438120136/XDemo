#include "dekeyboradwidget.h"
#include "demo.h"
#include <QIntValidator>
#include <QDoubleValidator>

Q_DECLARE_METATYPE(Demo *)
//----------------------------------------------------------------------------
DeKeyBoradWidget::DeKeyBoradWidget(const QString &text, DeKeyBoradWidget::KeyBoradType type, QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.lineEdit->setText(text);
	ui.widget_2->setEditControl(ui.lineEdit);
	connect(ui.widget_2, SIGNAL(signalOk()), this, SLOT(slotOkBtnClick()));

	////设置具体的模式
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
	case Int:
		{
			ui.lineEdit->setValidator(new QIntValidator(this));
			ui.widget_2->on_changeNumBtn_clicked();
			break;
		}
	case Float:
		{
			ui.lineEdit->setValidator(new QDoubleValidator(this));
			ui.widget_2->on_changeNumBtn_clicked();
			break;
		}
	case Ip:
		{
			ui.lineEdit->setInputMask("000.000.000.000;_");
			ui.widget_2->on_changeNumBtn_clicked();
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