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

	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(on_chinaBtn_clicked()));
	connect(ui.pushButton_9, SIGNAL(clicked()), this, SLOT(on_chinaBtn_clicked()));
	connect(ui.pushButton_13, SIGNAL(clicked()), this, SLOT(on_chinaBtn_clicked()));
	connect(ui.pushButton_2, SIGNAL(clicked()), this, SLOT(on_englishBtn_clicked()));
	connect(ui.pushButton_10, SIGNAL(clicked()), this, SLOT(on_englishBtn_clicked()));
	connect(ui.pushButton_14, SIGNAL(clicked()), this, SLOT(on_englishBtn_clicked()));
	
	///没有进入维护模式
	connect(ui.pushButton_3, SIGNAL(clicked()), this, SLOT(on_deviceBtn_clicked()));
	connect(ui.pushButton_11, SIGNAL(clicked()), this, SLOT(on_deviceBtn_clicked()));
	connect(ui.pushButton_15, SIGNAL(clicked()), this, SLOT(on_deviceBtn_clicked()));
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
	ui.label_35->setText(tr("%1").arg(timeString));
	ui.label_7->setText(tr("%1").arg(timeString));
	ui.label_43->setText(tr("%1").arg(timeString));	
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
void DeInitWidget::deviceSelfChecking()
{
	ui.tabWidget->setCurrentIndex(0);
	ui.msgLabel->setText(tr("自检\nSelf-checking"));
}
//----------------------------------------------------------------------------
void DeInitWidget::deviceChecking()
{
	ui.tabWidget->setCurrentIndex(2);
	ui.label_30->setText(tr("本底检测中\nBKG Meassuring"));
	ui.label_29->setText("β   -\nα   -");
	ui.label_32->setText("β   -\nα   -");
	ui.label_36->setText("β   -\nα   -");
	ui.label_37->setText("β   -\nα   -");

	playLabelForGif(ui.label_26, ":/Demo/Resources/jianceyemian-left-bendijiance.gif", 2);
	playLabelForGif(ui.label_31, ":/Demo/Resources/jianceyemian-right-bendijiance.gif", 2);
	playLabelForGif(ui.label_33, ":/Demo/Resources/jianceyemian-jiao-left-bendijiance.gif", 2);
	playLabelForGif(ui.label_34, ":/Demo/Resources/jianceyemian-jiao-right-bendijiance.gif", 2);

	ui.pushButton_11->hide();
	ui.pushButton_12->hide();
}
//----------------------------------------------------------------------------
void DeInitWidget::pleaseLeave()
{
	ui.tabWidget->setCurrentIndex(2);
	ui.label_30->setText(tr("请离开检测区域\nPlease leave"));
	ui.label_29->setText("β   -\nα   -");
	ui.label_32->setText("β   -\nα   -");
	ui.label_36->setText("β   -\nα   -");
	ui.label_37->setText("β   -\nα   -");

	playLabelForGif(ui.label_26, ":/Demo/Resources/jianceyemian-left-bendijiance.gif", 2);
	playLabelForGif(ui.label_31, ":/Demo/Resources/jianceyemian-right-bendijiance.gif", 2);
	playLabelForGif(ui.label_33, ":/Demo/Resources/jianceyemian-jiao-left-bendijiance.gif", 2);
	playLabelForGif(ui.label_34, ":/Demo/Resources/jianceyemian-jiao-right-bendijiance.gif", 2);

	ui.pushButton_11->hide();
	ui.pushButton_12->hide();
}
//----------------------------------------------------------------------------
void DeInitWidget::palmWuran()
{
	ui.tabWidget->setCurrentIndex(2);
	ui.label_30->setText(tr("手心污染\nContaminated"));
	ui.label_29->setText("β   -\nα   -");
	ui.label_32->setText("β   -\nα   -");
	ui.label_36->setText("β   -\nα   -");
	ui.label_37->setText("β   -\nα   -");

	ui.label_26->setStyleSheet("image: url(:/Demo/Resources/jianceyemian-shou-left-wuran.png); \
							   min-width:94px; \
							   min-height:98px; \
							   max-width:94px; \
							   max-height:98px;");
	ui.label_31->setStyleSheet("image: url(:/Demo/Resources/jianceyemian-shou-right-wuran.png); \
							   min-width:94px; \
							   min-height:98px; \
							   max-width:94px; \
							   max-height:98px;");
	ui.label_33->setStyleSheet("image: url(:/Demo/Resources/jianceyemian-jiao-left-wuran.png);\
							   min-width:50px; \
							   min-height:126px;\
							   max-width:50px;\
							   max-height:126px;");
	ui.label_34->setStyleSheet("image: url(:/Demo/Resources/jianceyemian-jiao-right-wuran.png);\
							   min-width:50px; \
							   min-height:126px;\
							   max-width:50px;\
							   max-height:126px;");
}
//----------------------------------------------------------------------------
void DeInitWidget::dorsumWuran()
{
	ui.tabWidget->setCurrentIndex(2);
	ui.label_30->setText(tr("手背污染\nContaminated"));
	ui.label_29->setText("β   -\nα   -");
	ui.label_32->setText("β   -\nα   -");
	ui.label_36->setText("β   -\nα   -");
	ui.label_37->setText("β   -\nα   -");

	ui.label_26->setStyleSheet("image: url(:/Demo/Resources/jianceyemian-shou-right-wuran.png); \
							   min-width:94px; \
							   min-height:98px; \
							   max-width:94px; \
							   max-height:98px;");
	ui.label_31->setStyleSheet("image: url(:/Demo/Resources/jianceyemian-shou-left-wuran.png); \
							   min-width:94px; \
							   min-height:98px; \
							   max-width:94px; \
							   max-height:98px;");
	ui.label_33->setStyleSheet("image: url(:/Demo/Resources/jianceyemian-jiao-left-wuran.png);\
							   min-width:50px; \
							   min-height:126px;\
							   max-width:50px;\
							   max-height:126px;");
	ui.label_34->setStyleSheet("image: url(:/Demo/Resources/jianceyemian-jiao-right-wuran.png);\
							   min-width:50px; \
							   min-height:126px;\
							   max-width:50px;\
							   max-height:126px;");
}
//----------------------------------------------------------------------------
void DeInitWidget::ready()
{
	ui.tabWidget->setCurrentIndex(2);
	ui.label_30->setText(tr("准备就绪\nReady"));
	ui.label_29->setText("β   -\nα   -");
	ui.label_32->setText("β   -\nα   -");
	ui.label_36->setText("β   -\nα   -");
	ui.label_37->setText("β   -\nα   -");
}
//----------------------------------------------------------------------------
void DeInitWidget::palmNoWuran()
{
	ui.tabWidget->setCurrentIndex(2);
	ui.label_30->setText(tr("手心未污染\nNot Contaminated"));
	ui.label_29->setText("β   -\nα   -");
	ui.label_32->setText("β   -\nα   -");
	ui.label_36->setText("β   -\nα   -");
	ui.label_37->setText("β   -\nα   -");

	ui.label_26->setStyleSheet("image: url(:/Demo/Resources/jianceyemian-shou-left-wuwuran.png); \
							   min-width:94px; \
							   min-height:98px; \
							   max-width:94px; \
							   max-height:98px;");
	ui.label_31->setStyleSheet("image: url(:/Demo/Resources/jianceyemian-shou-right-wuwuran.png); \
							   min-width:94px; \
							   min-height:98px; \
							   max-width:94px; \
							   max-height:98px;");
	ui.label_33->setStyleSheet("image: url(:/Demo/Resources/jianceyemian-jiao-left-wuwuran.png);\
							   min-width:50px; \
							   min-height:126px;\
							   max-width:50px;\
							   max-height:126px;");
	ui.label_34->setStyleSheet("image: url(:/Demo/Resources/jianceyemian-jiao-right-wuwuran.png);\
							   min-width:50px; \
							   min-height:126px;\
							   max-width:50px;\
							   max-height:126px;");
}
//----------------------------------------------------------------------------
void DeInitWidget::dorsumNoWuran()
{
	ui.tabWidget->setCurrentIndex(2);
	ui.label_30->setText(tr("手背未污染\nNot Contaminated"));
	ui.label_29->setText("β   -\nα   -");
	ui.label_32->setText("β   -\nα   -");
	ui.label_36->setText("β   -\nα   -");
	ui.label_37->setText("β   -\nα   -");

	ui.label_26->setStyleSheet("image: url(:/Demo/Resources/jianceyemian-shou-right-wuwuran.png); \
							   min-width:94px; \
							   min-height:98px; \
							   max-width:94px; \
							   max-height:98px;");
	ui.label_31->setStyleSheet("image: url(:/Demo/Resources/jianceyemian-shou-left-wuwuran.png); \
							   min-width:94px; \
							   min-height:98px; \
							   max-width:94px; \
							   max-height:98px;");
	ui.label_33->setStyleSheet("image: url(:/Demo/Resources/jianceyemian-jiao-left-wuwuran.png);\
							   min-width:50px; \
							   min-height:126px;\
							   max-width:50px;\
							   max-height:126px;");
	ui.label_34->setStyleSheet("image: url(:/Demo/Resources/jianceyemian-jiao-right-wuwuran.png);\
							   min-width:50px; \
							   min-height:126px;\
							   max-width:50px;\
							   max-height:126px;");
}
//----------------------------------------------------------------------------
void DeInitWidget::keyPartMeasuring()
{
	ui.tabWidget->setCurrentIndex(3);
	playLabelForGif(ui.label_39, ":/Demo/Resources/jianceyemian-teshu-jiancezhong.gif");
}
//----------------------------------------------------------------------------
void DeInitWidget::keyPartContaminated()
{
	ui.tabWidget->setCurrentIndex(3);
	ui.label_38->setText(tr("污染"));
	QString str = "image: url(:/Demo/Resources/jianceyemian-teshu-wuran.png); \
				  min-width:96px; \
				  min-height:124px;   \
				  max-width:96px; \
				  max-height:124px;";
	ui.label_39->setStyleSheet(str);
}
//----------------------------------------------------------------------------
void DeInitWidget::keyPartNoContaminated()
{
	ui.tabWidget->setCurrentIndex(3);
	ui.label_38->setText(tr("未污染"));
	QString str = "image: url(:/Demo/Resources/jianceyemian-teshu-wuwuran.png); \
				  min-width:96px; \
				  min-height:124px;   \
				  max-width:96px; \
				  max-height:124px;";
	ui.label_39->setStyleSheet(str);
}
//----------------------------------------------------------------------------
void DeInitWidget::deviceFault(DeviceStatus device)
{
	ui.tabWidget->setCurrentIndex(1);

	QString errorMsg;
	if (device.ultrasonic != 1)
		errorMsg += tr("红外超声波错误\n");	
	ui.label_3->setText(errorMsg);

	if (device.can_1)
	{
		QString str = "image: url(:/Demo/Resources/jianceyemian-shou-left-zhunbeijiuxu.png); \
					  min-width:94px; \
					  min-height:98px; \
					  max-width:94px; \
					  max-height:98px;";
		ui.label_2->setStyleSheet(str);
	}
	else
	{
		QString str = "image: url(:/Demo/Resources/jianceyemian-shou-left-guzhang.png); \
					  min-width:94px; \
					  min-height:98px; \
					  max-width:94px; \
					  max-height:98px;";
		ui.label_2->setStyleSheet(str);
	}

	if (device.can_2)
	{
		QString str = "image: url(:/Demo/Resources/jianceyemian-shou-right-zhunbeijiuxu.png); \
					  min-width:94px; \
					  min-height:98px; \
					  max-width:94px; \
					  max-height:98px;";
		ui.label_4->setStyleSheet(str);
	}
	else
	{
		QString str = "image: url(:/Demo/Resources/jianceyemian-shou-right-guzhang.png); \
					  min-width:94px; \
					  min-height:98px; \
					  max-width:94px; \
					  max-height:98px;";
		ui.label_4->setStyleSheet(str);
	}

	if (device.can_3)
	{
		QString str = "image: url(:/Demo/Resources/jianceyemian-jiao-left-zhunbeijiuxu.png); \
					  min-width:50px; \
					  min-height:126px; \
					  max-width:50px; \
					  max-height:126px;";
		ui.label_5->setStyleSheet(str);
	}
	else
	{
		QString str = "image: url(:/Demo/Resources/jianceyemian-jiao-left-guzhang.png); \
					  min-width:50px; \
					  min-height:126px; \
					  max-width:50px; \
					  max-height:126px;";
		ui.label_5->setStyleSheet(str);
	}

	if (device.can_4)
	{
		QString str = "image: url(:/Demo/Resources/jianceyemian-jiao-right-zhunbeijiuxu.png); \
					  min-width:50px; \
					  min-height:126px; \
					  max-width:50px; \
					  max-height:126px;";
		ui.label_6->setStyleSheet(str);
	}
	else
	{
		QString str = "image: url(:/Demo/Resources/jianceyemian-jiao-right-guzhang.png); \
					  min-width:50px; \
					  min-height:126px; \
					  max-width:50px; \
					  max-height:126px;";
		ui.label_6->setStyleSheet(str);
	}
}
//----------------------------------------------------------------------------
void DeInitWidget::palmChecking()
{
	ui.tabWidget->setCurrentIndex(2);
	ui.label_30->setText(tr("手心检测中\nMeasuring"));
	ui.label_29->setText("β   -\nα   -");
	ui.label_32->setText("β   -\nα   -");
	ui.label_36->setText("β   -\nα   -");
	ui.label_37->setText("β   -\nα   -");

	playLabelForGif(ui.label_26, ":/Demo/Resources/jianceyemian-left-jiancezhong.gif", 2);
	playLabelForGif(ui.label_31, ":/Demo/Resources/jianceyemian-right-jiancezhong.gif", 2);
	playLabelForGif(ui.label_33, ":/Demo/Resources/jianceyemian-jiao-left-jiancezhong.gif", 2);
	playLabelForGif(ui.label_34, ":/Demo/Resources/jianceyemian-jiao-right-jiancezhong.gif", 2);

	ui.pushButton_11->hide();
	ui.pushButton_12->hide();
}
//----------------------------------------------------------------------------
void DeInitWidget::dorsumChecking()
{
	ui.tabWidget->setCurrentIndex(2);
	ui.label_30->setText(tr("手背检测中\nMeasuring"));
	ui.label_29->setText("β   -\nα   -");
	ui.label_32->setText("β   -\nα   -");
	ui.label_36->setText("β   -\nα   -");
	ui.label_37->setText("β   -\nα   -");

	playLabelForGif(ui.label_26, ":/Demo/Resources/jianceyemian-right-jiancezhong.gif", 2);
	playLabelForGif(ui.label_31, ":/Demo/Resources/jianceyemian-left-jiancezhong.gif", 2);
	playLabelForGif(ui.label_33, ":/Demo/Resources/jianceyemian-jiao-left-jiancezhong.gif", 2);
	playLabelForGif(ui.label_34, ":/Demo/Resources/jianceyemian-jiao-right-jiancezhong.gif", 2);

	ui.pushButton_11->hide();
	ui.pushButton_12->hide();
}
//----------------------------------------------------------------------------