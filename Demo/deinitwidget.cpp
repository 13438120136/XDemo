#include "deinitwidget.h"
#include <qeventloop.h>
#include <QTimer>
#include <QDateTime>
#include <demo.h>
#include "deloginwidget.h"
#include "demessagebox.h"
#include "demenuwidget.h"
#include <QTranslator>
#include <QDebug>

Q_DECLARE_METATYPE(Demo *)
//----------------------------------------------------------------------------
DeInitWidget::DeInitWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	QTimer *timer = new QTimer(this);
	timer->start(500);
	connect(timer, SIGNAL(timeout()), this, SLOT(slotTimeOut()));
	slotTimeOut();
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
void DeInitWidget::slotTimeOut()
{
	QString timeString = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
	ui.timeLabel->setText(tr("%1").arg(timeString));
}
//----------------------------------------------------------------------------
void DeInitWidget::on_exitBtn_clicked()
{
	DeMessageBox msgBox(this);
	msgBox.setText(tr("exit?"));
	QPushButton *okButton = msgBox.addButton(tr("yes"), QMessageBox::AcceptRole);  
	msgBox.addButton(tr("no"), QMessageBox::RejectRole); 
	msgBox.exec();
	if ((QPushButton*)msgBox.clickedButton() == okButton)  
		qApp->quit();
}
//----------------------------------------------------------------------------
void DeInitWidget::on_loginBtn_clicked()
{
	Demo *demo = qApp->property("_mainWin").value<Demo *>();
	DeLoginWidget *window = new DeLoginWidget;
	demo->slotSetWidget(window);
}
//----------------------------------------------------------------------------
void DeInitWidget::on_chinaBtn_clicked()
{
    QTranslator translator;
    translator.load(":/Demo/demo_zh.qm");
    qApp->installTranslator(&translator);
    ui.retranslateUi(this);

    Demo *demo = qApp->property("_mainWin").value<Demo *>();
    demo->translator(true);
}
//----------------------------------------------------------------------------
void DeInitWidget::on_englishBtn_clicked()
{
    QTranslator translator;
    translator.load(":/Demo/demo_en.qm");
    qApp->installTranslator(&translator);
    ui.retranslateUi(this);

    Demo *demo = qApp->property("_mainWin").value<Demo *>();
    demo->translator(false);
}
//----------------------------------------------------------------------------
