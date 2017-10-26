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

	ui.pushButton_12->setEnabled(false);
	ui.pushButton_12->setText("");
	ui.pushButton_16->setEnabled(false);
	ui.pushButton_16->setText("");
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
void DeInitWidget::stopLabelForGif(QLabel *label)
{
	QMovie *movie = label->movie();
	if (movie == NULL)
		return ;

	movie->stop();
	delete movie;
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
	ui.msgLabel->setText(tr("自检\nSelf-Checking"));
}
//----------------------------------------------------------------------------
void DeInitWidget::deviceChecking()
{
	Demo *demo = qApp->property("_mainWin").value<Demo *>();
	AlphaAndBeta &pValue = demo->get_AlphaAndBeta();

	ui.tabWidget->setCurrentIndex(2);
	ui.label_30->setText(tr("本底检测中\nBKG Meassuring"));
	ui.label_29->setText(QString("β   %2\nα   %1")
		.arg(pValue.abValue[0][0], 2, 10, QLatin1Char( ' ' ) )
		.arg(pValue.abValue[0][1], 2, 10, QLatin1Char( ' ' ) ));
	ui.label_32->setText(QString("β   %2\nα   %1")
		.arg(pValue.abValue[1][0], 2, 10, QLatin1Char( ' ' ) )
		.arg(pValue.abValue[1][1], 2, 10, QLatin1Char( ' ' ) ));
	ui.label_36->setText(QString("β   %2\nα   %1")
		.arg(pValue.abValue[2][0], 2, 10, QLatin1Char( ' ' ) )
		.arg(pValue.abValue[2][1], 2, 10, QLatin1Char( ' ' ) ));
	ui.label_37->setText(QString("β   %2\nα   %1")
		.arg(pValue.abValue[3][0], 2, 10, QLatin1Char( ' ' ) )
		.arg(pValue.abValue[3][1], 2, 10, QLatin1Char( ' ' ) ));

	playLabelForGif(ui.label_26, ":/Demo/Resources/jianceyemian-left-bendijiance.gif", 2);
	playLabelForGif(ui.label_31, ":/Demo/Resources/jianceyemian-right-bendijiance.gif", 2);
	playLabelForGif(ui.label_33, ":/Demo/Resources/jianceyemian-jiao-left-bendijiance.gif", 2);
	playLabelForGif(ui.label_34, ":/Demo/Resources/jianceyemian-jiao-right-bendijiance.gif", 2);

	ui.pushButton_11->hide();
}
//----------------------------------------------------------------------------
void DeInitWidget::bottomWuran()
{
	Demo *demo = qApp->property("_mainWin").value<Demo *>();
	AlphaAndBeta &pValue = demo->get_AlphaAndBeta();

	ui.tabWidget->setCurrentIndex(2);
	ui.label_30->setText(tr("污染\nComtaminated"));
	ui.label_29->setText(QString("β   %2\nα   %1")
		.arg(pValue.abValue[0][0], 2, 10, QLatin1Char( ' ' ) )
		.arg(pValue.abValue[0][1], 2, 10, QLatin1Char( ' ' ) ));
	ui.label_32->setText(QString("β   %2\nα   %1")
		.arg(pValue.abValue[1][0], 2, 10, QLatin1Char( ' ' ) )
		.arg(pValue.abValue[1][1], 2, 10, QLatin1Char( ' ' ) ));
	ui.label_36->setText(QString("β   %2\nα   %1")
		.arg(pValue.abValue[2][0], 2, 10, QLatin1Char( ' ' ) )
		.arg(pValue.abValue[2][1], 2, 10, QLatin1Char( ' ' ) ));
	ui.label_37->setText(QString("β   %2\nα   %1")
		.arg(pValue.abValue[3][0], 2, 10, QLatin1Char( ' ' ) )
		.arg(pValue.abValue[3][1], 2, 10, QLatin1Char( ' ' ) ));

	stopLabelForGif(ui.label_26);
	stopLabelForGif(ui.label_31);
	stopLabelForGif(ui.label_33);
	stopLabelForGif(ui.label_34);

	if (pValue.alarmStates[0] == 0)
	{
		ui.label_26->setStyleSheet("image: url(:/Demo/Resources/jianceyemian-shou-left-zhunbeijiuxu.png); \
								   min-width:94px; \
								   min-height:98px; \
								   max-width:94px; \
								   max-height:98px;");
	}
	else
	{
		ui.label_26->setStyleSheet("image: url(:/Demo/Resources/jianceyemian-shou-left-wuran.png); \
								   min-width:94px; \
								   min-height:98px; \
								   max-width:94px; \
								   max-height:98px;");
	}

	if (pValue.alarmStates[1] == 0)
	{
		ui.label_31->setStyleSheet("image: url(:/Demo/Resources/jianceyemian-shou-right-zhunbeijiuxu.png); \
								   min-width:94px; \
								   min-height:98px; \
								   max-width:94px; \
								   max-height:98px;");
	}
	else
	{
		ui.label_31->setStyleSheet("image: url(:/Demo/Resources/jianceyemian-shou-right-wuran.png); \
								   min-width:94px; \
								   min-height:98px; \
								   max-width:94px; \
								   max-height:98px;");
	}

	if (pValue.alarmStates[2] == 0)
	{
		ui.label_33->setStyleSheet("image: url(:/Demo/Resources/jianceyemian-jiao-left-zhunbeijiuxu.png);\
								   min-width:50px; \
								   min-height:126px;\
								   max-width:50px;\
								   max-height:126px;");
	}
	else
	{
		ui.label_33->setStyleSheet("image: url(:/Demo/Resources/jianceyemian-jiao-left-wuran.png);\
								   min-width:50px; \
								   min-height:126px;\
								   max-width:50px;\
								   max-height:126px;");
	}

	if (pValue.alarmStates[3] == 0)
	{
		ui.label_34->setStyleSheet("image: url(:/Demo/Resources/jianceyemian-jiao-right-zhunbeijiuxu.png);\
								   min-width:50px; \
								   min-height:126px;\
								   max-width:50px;\
								   max-height:126px;");
	}
	else
	{
		ui.label_34->setStyleSheet("image: url(:/Demo/Resources/jianceyemian-jiao-right-wuran.png);\
								   min-width:50px; \
								   min-height:126px;\
								   max-width:50px;\
								   max-height:126px;");
	}

	ui.pushButton_11->show();
}
//----------------------------------------------------------------------------
void DeInitWidget::pleaseLeave()
{
	Demo *demo = qApp->property("_mainWin").value<Demo *>();
	AlphaAndBeta &pValue = demo->get_AlphaAndBeta();

	ui.tabWidget->setCurrentIndex(2);
	ui.label_30->setText(tr("请离开检测区域\nPlease leave"));
	ui.label_29->setText(QString("β   %2\nα   %1")
		.arg(pValue.abValue[0][0], 2, 10, QLatin1Char( ' ' ) )
		.arg(pValue.abValue[0][1], 2, 10, QLatin1Char( ' ' ) ));
	ui.label_32->setText(QString("β   %2\nα   %1")
		.arg(pValue.abValue[1][0], 2, 10, QLatin1Char( ' ' ) )
		.arg(pValue.abValue[1][1], 2, 10, QLatin1Char( ' ' ) ));
	ui.label_36->setText(QString("β   %2\nα   %1")
		.arg(pValue.abValue[2][0], 2, 10, QLatin1Char( ' ' ) )
		.arg(pValue.abValue[2][1], 2, 10, QLatin1Char( ' ' ) ));
	ui.label_37->setText(QString("β   %2\nα   %1")
		.arg(pValue.abValue[3][0], 2, 10, QLatin1Char( ' ' ) )
		.arg(pValue.abValue[3][1], 2, 10, QLatin1Char( ' ' ) ));

	playLabelForGif(ui.label_26, ":/Demo/Resources/jianceyemian-left-bendijiance.gif", 2);
	playLabelForGif(ui.label_31, ":/Demo/Resources/jianceyemian-right-bendijiance.gif", 2);
	playLabelForGif(ui.label_33, ":/Demo/Resources/jianceyemian-jiao-left-bendijiance.gif", 2);
	playLabelForGif(ui.label_34, ":/Demo/Resources/jianceyemian-jiao-right-bendijiance.gif", 2);

	ui.pushButton_11->hide();
}
//----------------------------------------------------------------------------
void DeInitWidget::palmWuran()
{
	Demo *demo = qApp->property("_mainWin").value<Demo *>();
	AlphaAndBeta &pValue = demo->get_AlphaAndBeta();

	ui.tabWidget->setCurrentIndex(2);
	ui.label_30->setText(tr("手心污染\nContaminated"));
	ui.label_29->setText(QString("β   %2\nα   %1")
		.arg(pValue.abValue[0][0], 2, 10, QLatin1Char( ' ' ) )
		.arg(pValue.abValue[0][1], 2, 10, QLatin1Char( ' ' ) ));
	ui.label_32->setText(QString("β   %2\nα   %1")
		.arg(pValue.abValue[1][0], 2, 10, QLatin1Char( ' ' ) )
		.arg(pValue.abValue[1][1], 2, 10, QLatin1Char( ' ' ) ));
	ui.label_36->setText(QString("β   %2\nα   %1")
		.arg(pValue.abValue[2][0], 2, 10, QLatin1Char( ' ' ) )
		.arg(pValue.abValue[2][1], 2, 10, QLatin1Char( ' ' ) ));
	ui.label_37->setText(QString("β   %2\nα   %1")
		.arg(pValue.abValue[3][0], 2, 10, QLatin1Char( ' ' ) )
		.arg(pValue.abValue[3][1], 2, 10, QLatin1Char( ' ' ) ));

	stopLabelForGif(ui.label_26);
	stopLabelForGif(ui.label_31);
	stopLabelForGif(ui.label_33);
	stopLabelForGif(ui.label_34);

	if (pValue.channelContaminatedStatus[0] == 0)
	{
		ui.label_26->setStyleSheet("image: url(:/Demo/Resources/jianceyemian-shou-left-wuwuran.png); \
								   min-width:94px; \
								   min-height:98px; \
								   max-width:94px; \
								   max-height:98px;");
	}
	else
	{
		ui.label_26->setStyleSheet("image: url(:/Demo/Resources/jianceyemian-shou-left-wuran.png); \
								   min-width:94px; \
								   min-height:98px; \
								   max-width:94px; \
								   max-height:98px;");
	}

	if (pValue.channelContaminatedStatus[1] == 0)
	{
		ui.label_31->setStyleSheet("image: url(:/Demo/Resources/jianceyemian-shou-right-wuwuran.png); \
								   min-width:94px; \
								   min-height:98px; \
								   max-width:94px; \
								   max-height:98px;");
	}
	else
	{
		ui.label_31->setStyleSheet("image: url(:/Demo/Resources/jianceyemian-shou-right-wuran.png); \
								   min-width:94px; \
								   min-height:98px; \
								   max-width:94px; \
								   max-height:98px;");
	}

	if (pValue.channelContaminatedStatus[2] == 0)
	{
		ui.label_33->setStyleSheet("image: url(:/Demo/Resources/jianceyemian-jiao-left-wuwuran.png);\
								   min-width:50px; \
								   min-height:126px;\
								   max-width:50px;\
								   max-height:126px;");
	}
	else
	{
		ui.label_33->setStyleSheet("image: url(:/Demo/Resources/jianceyemian-jiao-left-wuran.png);\
								   min-width:50px; \
								   min-height:126px;\
								   max-width:50px;\
								   max-height:126px;");
	}

	if (pValue.channelContaminatedStatus[3] == 0)
	{
		ui.label_34->setStyleSheet("image: url(:/Demo/Resources/jianceyemian-jiao-right-wuwuran.png);\
								   min-width:50px; \
								   min-height:126px;\
								   max-width:50px;\
								   max-height:126px;");
	}
	else
	{
		ui.label_34->setStyleSheet("image: url(:/Demo/Resources/jianceyemian-jiao-right-wuran.png);\
								   min-width:50px; \
								   min-height:126px;\
								   max-width:50px;\
								   max-height:126px;");
	}

	ui.pushButton_11->show();
}
//----------------------------------------------------------------------------
void DeInitWidget::dorsumWuran()
{
	Demo *demo = qApp->property("_mainWin").value<Demo *>();
	AlphaAndBeta &pValue = demo->get_AlphaAndBeta();

	ui.tabWidget->setCurrentIndex(2);
	ui.label_30->setText(tr("手背污染\nContaminated"));
	ui.label_29->setText(QString("β   %2\nα   %1")
		.arg(pValue.abValue[4][0], 2, 10, QLatin1Char( ' ' ) )
		.arg(pValue.abValue[4][1], 2, 10, QLatin1Char( ' ' ) ));
	ui.label_32->setText(QString("β   %2\nα   %1")
		.arg(pValue.abValue[5][0], 2, 10, QLatin1Char( ' ' ) )
		.arg(pValue.abValue[5][1], 2, 10, QLatin1Char( ' ' ) ));
	ui.label_36->setText(QString("β   %2\nα   %1")
		.arg(pValue.abValue[2][0], 2, 10, QLatin1Char( ' ' ) )
		.arg(pValue.abValue[2][1], 2, 10, QLatin1Char( ' ' ) ));
	ui.label_37->setText(QString("β   %2\nα   %1")
		.arg(pValue.abValue[3][0], 2, 10, QLatin1Char( ' ' ) )
		.arg(pValue.abValue[3][1], 2, 10, QLatin1Char( ' ' ) ));

	stopLabelForGif(ui.label_26);
	stopLabelForGif(ui.label_31);
	stopLabelForGif(ui.label_33);
	stopLabelForGif(ui.label_34);

	if (pValue.channelContaminatedStatus[4] == 0)
	{
	ui.label_26->setStyleSheet("image: url(:/Demo/Resources/jianceyemian-shou-right-wuwuran.png); \
							   min-width:94px; \
							   min-height:98px; \
							   max-width:94px; \
							   max-height:98px;");
	}
	else
	{
		ui.label_26->setStyleSheet("image: url(:/Demo/Resources/jianceyemian-shou-right-wuran.png); \
								   min-width:94px; \
								   min-height:98px; \
								   max-width:94px; \
								   max-height:98px;");
	}

	if (pValue.channelContaminatedStatus[5] == 0)
	{
		ui.label_31->setStyleSheet("image: url(:/Demo/Resources/jianceyemian-shou-left-wuwuran.png); \
								   min-width:94px; \
								   min-height:98px; \
								   max-width:94px; \
								   max-height:98px;");
	}
	else
	{
		ui.label_31->setStyleSheet("image: url(:/Demo/Resources/jianceyemian-shou-left-wuran.png); \
								   min-width:94px; \
								   min-height:98px; \
								   max-width:94px; \
								   max-height:98px;");
	}

	if (pValue.channelContaminatedStatus[2] == 0)
	{
		ui.label_33->setStyleSheet("image: url(:/Demo/Resources/jianceyemian-jiao-left-wuwuran.png);\
								   min-width:50px; \
								   min-height:126px;\
								   max-width:50px;\
								   max-height:126px;");

	}
	else
	{
		ui.label_33->setStyleSheet("image: url(:/Demo/Resources/jianceyemian-jiao-left-wuran.png);\
								   min-width:50px; \
								   min-height:126px;\
								   max-width:50px;\
								   max-height:126px;");
	}

	if (pValue.channelContaminatedStatus[3] == 0)
	{
		ui.label_34->setStyleSheet("image: url(:/Demo/Resources/jianceyemian-jiao-right-wuwuran.png);\
								   min-width:50px; \
								   min-height:126px;\
								   max-width:50px;\
								   max-height:126px;");
	}
	else
	{
		ui.label_34->setStyleSheet("image: url(:/Demo/Resources/jianceyemian-jiao-right-wuran.png);\
								   min-width:50px; \
								   min-height:126px;\
								   max-width:50px;\
								   max-height:126px;");
	}

	ui.pushButton_11->show();
}
//----------------------------------------------------------------------------
void DeInitWidget::ready()
{
	ui.tabWidget->setCurrentIndex(2);

	Demo *demo = qApp->property("_mainWin").value<Demo *>();
	AlphaAndBeta &pValue = demo->get_AlphaAndBeta();

	ui.label_30->setText(tr("准备就绪\nReady"));
	ui.label_29->setText(QString("β   %2\nα   %1")
		.arg(pValue.abValue[0][0], 2, 10, QLatin1Char( ' ' ) )
		.arg(pValue.abValue[0][1], 2, 10, QLatin1Char( ' ' ) ));
	ui.label_32->setText(QString("β   %2\nα   %1")
		.arg(pValue.abValue[1][0], 2, 10, QLatin1Char( ' ' ) )
		.arg(pValue.abValue[1][1], 2, 10, QLatin1Char( ' ' ) ));
	ui.label_36->setText(QString("β   %2\nα   %1")
		.arg(pValue.abValue[2][0], 2, 10, QLatin1Char( ' ' ) )
		.arg(pValue.abValue[2][1], 2, 10, QLatin1Char( ' ' ) ));
	ui.label_37->setText(QString("β   %2\nα   %1")
		.arg(pValue.abValue[3][0], 2, 10, QLatin1Char( ' ' ) )
		.arg(pValue.abValue[3][1], 2, 10, QLatin1Char( ' ' ) ));

	stopLabelForGif(ui.label_26);
	stopLabelForGif(ui.label_31);
	stopLabelForGif(ui.label_33);
	stopLabelForGif(ui.label_34);
}
//----------------------------------------------------------------------------
void DeInitWidget::palmNoWuran()
{
	Demo *demo = qApp->property("_mainWin").value<Demo *>();
	AlphaAndBeta &pValue = demo->get_AlphaAndBeta();

	ui.tabWidget->setCurrentIndex(2);
	ui.label_30->setText(tr("手心未污染\nNot Contaminated"));
	ui.label_29->setText(QString("β   %2\nα   %1")
		.arg(pValue.abValue[0][0], 2, 10, QLatin1Char( ' ' ) )
		.arg(pValue.abValue[0][1], 2, 10, QLatin1Char( ' ' ) ));
	ui.label_32->setText(QString("β   %2\nα   %1")
		.arg(pValue.abValue[1][0], 2, 10, QLatin1Char( ' ' ) )
		.arg(pValue.abValue[1][1], 2, 10, QLatin1Char( ' ' ) ));
	ui.label_36->setText(QString("β   %2\nα   %1")
		.arg(pValue.abValue[2][0], 2, 10, QLatin1Char( ' ' ) )
		.arg(pValue.abValue[2][1], 2, 10, QLatin1Char( ' ' ) ));
	ui.label_37->setText(QString("β   %2\nα   %1")
		.arg(pValue.abValue[3][0], 2, 10, QLatin1Char( ' ' ) )
		.arg(pValue.abValue[3][1], 2, 10, QLatin1Char( ' ' ) ));

	stopLabelForGif(ui.label_26);
	stopLabelForGif(ui.label_31);
	stopLabelForGif(ui.label_33);
	stopLabelForGif(ui.label_34);

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

	ui.pushButton_11->show();
}
//----------------------------------------------------------------------------
void DeInitWidget::dorsumNoWuran()
{	
	Demo *demo = qApp->property("_mainWin").value<Demo *>();
	AlphaAndBeta &pValue = demo->get_AlphaAndBeta();

	ui.tabWidget->setCurrentIndex(2);
	ui.label_30->setText(tr("手背未污染\nNot Contaminated"));
	ui.label_29->setText(QString("β   %2\nα   %1")
		.arg(pValue.abValue[4][0], 2, 10, QLatin1Char( ' ' ) )
		.arg(pValue.abValue[4][1], 2, 10, QLatin1Char( ' ' ) ));
	ui.label_32->setText(QString("β   %2\nα   %1")
		.arg(pValue.abValue[5][0], 2, 10, QLatin1Char( ' ' ) )
		.arg(pValue.abValue[5][1], 2, 10, QLatin1Char( ' ' ) ));
	ui.label_36->setText(QString("β   %2\nα   %1")
		.arg(pValue.abValue[2][0], 2, 10, QLatin1Char( ' ' ) )
		.arg(pValue.abValue[2][1], 2, 10, QLatin1Char( ' ' ) ));
	ui.label_37->setText(QString("β   %2\nα   %1")
		.arg(pValue.abValue[3][0], 2, 10, QLatin1Char( ' ' ) )
		.arg(pValue.abValue[3][1], 2, 10, QLatin1Char( ' ' ) ));

	stopLabelForGif(ui.label_26);
	stopLabelForGif(ui.label_31);
	stopLabelForGif(ui.label_33);
	stopLabelForGif(ui.label_34);

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

	ui.pushButton_11->show();
}
//----------------------------------------------------------------------------
void DeInitWidget::keyPartMeasuring()
{
	ui.tabWidget->setCurrentIndex(3);
	ui.label_38->setText(tr("重点部位测量\nKey Part Measuring"));
	playLabelForGif(ui.label_39, ":/Demo/Resources/jianceyemian-teshu-jiancezhong.gif");

	ui.pushButton_15->hide();
}
//----------------------------------------------------------------------------
void DeInitWidget::keyPartContaminated()
{
	//Demo *demo = qApp->property("_mainWin").value<Demo *>();
	//AlphaAndBeta &pValue = demo->get_AlphaAndBeta();

	ui.tabWidget->setCurrentIndex(3);
	ui.label_38->setText(tr("污染\nContaminated"));
	QString str = "image: url(:/Demo/Resources/jianceyemian-teshu-wuran.png); \
				  min-width:96px; \
				  min-height:124px;   \
				  max-width:96px; \
				  max-height:124px;";
	ui.label_39->setStyleSheet(str);
	ui.label_39->setMovie(NULL);

	ui.pushButton_15->show();
}
//----------------------------------------------------------------------------
void DeInitWidget::keyPartNoContaminated()
{
	//Demo *demo = qApp->property("_mainWin").value<Demo *>();
	//AlphaAndBeta &pValue = demo->get_AlphaAndBeta();

	ui.tabWidget->setCurrentIndex(3);
	ui.label_38->setText(tr("未污染"));
	QString str = "image: url(:/Demo/Resources/jianceyemian-teshu-wuwuran.png); \
				  min-width:96px; \
				  min-height:124px;   \
				  max-width:96px; \
				  max-height:124px;";
	ui.label_39->setStyleSheet(str);
	ui.label_39->setMovie(NULL);

	ui.pushButton_15->show();
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
}
//----------------------------------------------------------------------------
void DeInitWidget::flipPalm()
{
	ui.tabWidget->setCurrentIndex(2);
	ui.label_30->setText(tr("请反转手掌\nPlease Filp Palm"));
	ui.label_29->setText("β   -\nα   -");
	ui.label_32->setText("β   -\nα   -");
	ui.label_36->setText("β   -\nα   -");
	ui.label_37->setText("β   -\nα   -");

	stopLabelForGif(ui.label_26);
	stopLabelForGif(ui.label_31);
	stopLabelForGif(ui.label_33);
	stopLabelForGif(ui.label_34);

	ui.label_26->setStyleSheet("image: url(:/Demo/Resources/jianceyemian-shou-right-zhunbeijiuxu.png); \
							   min-width:94px; \
							   min-height:98px; \
							   max-width:94px; \
							   max-height:98px;");
	ui.label_31->setStyleSheet("image: url(:/Demo/Resources/jianceyemian-shou-left-zhunbeijiuxu.png); \
							   min-width:94px; \
							   min-height:98px; \
							   max-width:94px; \
							   max-height:98px;");
	ui.label_33->setStyleSheet("image: url(:/Demo/Resources/jianceyemian-jiao-left-jiuwei.png);\
							   min-width:50px; \
							   min-height:126px;\
							   max-width:50px;\
							   max-height:126px;");
	ui.label_34->setStyleSheet("image: url(:/Demo/Resources/jianceyemian-jiao-right-jiuwei.png);\
							   min-width:50px; \
							   min-height:126px;\
							   max-width:50px;\
							   max-height:126px;");

	ui.pushButton_11->hide();
}
//----------------------------------------------------------------------------
void DeInitWidget::posError()
{
	ui.tabWidget->setCurrentIndex(2);
	ui.label_30->setText(tr("位置错误\nCorrect position"));
	ui.label_29->setText("β   -\nα   -");
	ui.label_32->setText("β   -\nα   -");
	ui.label_36->setText("β   -\nα   -");
	ui.label_37->setText("β   -\nα   -");	
	
	stopLabelForGif(ui.label_26);
	stopLabelForGif(ui.label_31);
	stopLabelForGif(ui.label_33);
	stopLabelForGif(ui.label_34);

	Demo *demo = qApp->property("_mainWin").value<Demo *>();

	ui.label_26->setStyleSheet("image: url(:/Demo/Resources/jianceyemian-shou-left-jiuwei.png); \
							   min-width:94px; \
							   min-height:98px; \
							   max-width:94px; \
							   max-height:98px;");
	ui.label_31->setStyleSheet("image: url(:/Demo/Resources/jianceyemian-shou-right-jiuwei.png); \
							   min-width:94px; \
							   min-height:98px; \
							   max-width:94px; \
							   max-height:98px;");
	ui.label_33->setStyleSheet("image: url(:/Demo/Resources/jianceyemian-jiao-left-jiuwei.png);\
							   min-width:50px; \
							   min-height:126px;\
							   max-width:50px;\
							   max-height:126px;");
	ui.label_34->setStyleSheet("image: url(:/Demo/Resources/jianceyemian-jiao-right-jiuwei.png);\
							   min-width:50px; \
							   min-height:126px;\
							   max-width:50px;\
							   max-height:126px;");

	switch(demo->get_PostionError().errorIndex)
	{
	case 0:
		ui.label_26->setStyleSheet("image: url(:/Demo/Resources/jianceyemian-shou-left-zhunbeijiuxu.png); \
								   min-width:94px; \
								   min-height:98px; \
								   max-width:94px; \
								   max-height:98px;");
		break;
	case 1:
		ui.label_31->setStyleSheet("image: url(:/Demo/Resources/jianceyemian-shou-right-zhunbeijiuxu.png); \
								   min-width:94px; \
								   min-height:98px; \
								   max-width:94px; \
								   max-height:98px;");
		break;
	case 2:
		ui.label_33->setStyleSheet("image: url(:/Demo/Resources/jianceyemian-jiao-left-zhunbeijiuxu.png);\
								   min-width:50px; \
								   min-height:126px;\
								   max-width:50px;\
								   max-height:126px;");
		break;
	case 3:
		ui.label_34->setStyleSheet("image: url(:/Demo/Resources/jianceyemian-jiao-right-zhunbeijiuxu.png);\
								   min-width:50px; \
								   min-height:126px;\
								   max-width:50px;\
								   max-height:126px;");
		break;
	default:
		break;
	}

	ui.pushButton_11->hide();
}
//----------------------------------------------------------------------------