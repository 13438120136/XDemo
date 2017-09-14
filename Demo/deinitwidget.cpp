#include "deinitwidget.h"
#include <qeventloop.h>
#include <QTimer>
#include <QDateTime>
#include <demo.h>
#include "deloginwidget.h"
#include "demessagebox.h"
#include "demenuwidget.h"
#include <QTranslator>
#include <QMovie>
#include "desystemconfigwidget.h"

Q_DECLARE_METATYPE(Demo *)
//----------------------------------------------------------------------------
DeInitWidget::DeInitWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.tabWidget->findChild<QTabBar *>()->hide();

	QTimer *timer = new QTimer(this);
	timer->start(500);
	connect(timer, SIGNAL(timeout()), this, SLOT(slotTimeOut()));
	slotTimeOut();

	playLabelForGif(ui.label_39, ":/Demo/Resources/jianceyemian-teshu-jiancezhong.gif");
}
//----------------------------------------------------------------------------
DeInitWidget::~DeInitWidget()
{

}
//----------------------------------------------------------------------------
void DeInitWidget::playLabelForGif(QLabel *label, const QString &gif, int speed)
{
	QMovie *movie = new QMovie(gif);
	label->setMovie(movie);
	if (speed >= 1)
		movie->setSpeed(speed * 100);
	movie->setScaledSize(QSize(label->width(), label->height()));
	movie->start();
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
    Demo *demo = qApp->property("_mainWin").value<Demo *>();
	demo->setBLanguage(true);
	ui.retranslateUi(this);
}
//----------------------------------------------------------------------------
void DeInitWidget::on_englishBtn_clicked()
{
    Demo *demo = qApp->property("_mainWin").value<Demo *>();
	demo->setBLanguage(false);
	ui.retranslateUi(this);
}
//----------------------------------------------------------------------------
void DeInitWidget::on_deviceBtn_clicked()
{
	Demo *demo = qApp->property("_mainWin").value<Demo *>();
	DeSystemConfigWidget *window = new DeSystemConfigWidget(false);
	demo->slotSetWidget(window);
}
//----------------------------------------------------------------------------
