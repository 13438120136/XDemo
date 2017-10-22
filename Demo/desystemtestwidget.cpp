#include "desystemtestwidget.h"
#include "dechanneltestmodel.h"
#include "detestinformodel.h"
#include "demo.h"
#include "demenuwidget.h"
#include <QMovie>

Q_DECLARE_METATYPE(Demo *)
//----------------------------------------------------------------------------
void playLabelForGif(QLabel *label, const QString &gif, int speed)
{
	QMovie *movie = new QMovie(gif);
	label->setMovie(movie);
	if (speed >= 1)
		movie->setSpeed(speed * 100);
	movie->setScaledSize(QSize(80, 80));
	movie->start();
}
//----------------------------------------------------------------------------
void stopLabelForGif(QLabel *label)
{
	QMovie *movie = label->movie();
	if (movie == NULL)
		return ;

	movie->stop();
	delete movie;
}
//----------------------------------------------------------------------------
DeSystemTestWidget::DeSystemTestWidget(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	m_isIOTest = false;
	this->setWindowFlags(Qt::ToolTip);
	ui.tabWidget->findChildren<QTabBar*>().at(0)->hide();

	m_channelMode = new DeChannelTestModel(this);
	ui.widget_4->setModel(m_channelMode);

	DeTestInforModel *inforModel = new DeTestInforModel(this);
	ui.widget_5->setModel(inforModel);
	
	connect(ui.physicalTest, SIGNAL(toggled(bool)), this, SLOT(slotPhysicalTest(bool)));

	on_ioBtn_clicked();

	ui.lineEdit->installEventFilter(&m_tIntDelegate);
	ui.lineEdit_2->installEventFilter(&m_tIntDelegate);
	ui.lineEdit_3->installEventFilter(&m_tIntDelegate);
	ui.lineEdit_4->installEventFilter(&m_tIntDelegate);

	ui.lineEdit_5->installEventFilter(&m_tIntDelegate);
	ui.lineEdit_6->installEventFilter(&m_tIntDelegate);
	ui.lineEdit_7->installEventFilter(&m_tIntDelegate);
	ui.lineEdit_8->installEventFilter(&m_tIntDelegate);
	ui.lineEdit_9->installEventFilter(&m_tIntDelegate);
	ui.lineEdit_10->installEventFilter(&m_tIntDelegate);
	ui.lineEdit_11->installEventFilter(&m_tIntDelegate);

	///playLabelForGif(ui.label, ":/Demo/Resources/xitongceshi-jinxingzhong.gif", 2);
	QList<int> intTMpList;
	intTMpList << 1 << 2 << 3 << 4;
	ui.widget_3->setValueList(intTMpList);
	ui.widget_7->setValueList(intTMpList);

	Demo *demo = qApp->property("_mainWin").value<Demo *>();
	connect(demo, SIGNAL(signalChannelResult(ChannelResultData)), this, SLOT(slotChannelResult(ChannelResultData)));

	connect(ui.widget_3, SIGNAL(signalValueChanged(int)), this, SLOT(slotChannelValueChanged(int)));
}
//----------------------------------------------------------------------------
DeSystemTestWidget::~DeSystemTestWidget()
{
	
}
//----------------------------------------------------------------------------
void DeSystemTestWidget::slotPhysicalTest(bool enable)
{
	ui.groupBox_2->setEnabled(enable);
}
//----------------------------------------------------------------------------
void DeSystemTestWidget::on_ioBtn_clicked()
{
	ui.tabWidget->setCurrentIndex(0);
	ui.ioBtn->setStyleSheet("border:2px solid black; \
								border-top-width:0px; \
								border-right-width:0px; \
								border-left-width:0px; \
								border-bottom-width:2px; \
								border-bottom-color:#42BDAA; \
								color: #42BDAA;");
	ui.channelBtn->setStyleSheet("border:none;");
	ui.xiaolvBtn->setStyleSheet("border:none;");
}
//----------------------------------------------------------------------------
void DeSystemTestWidget::on_channelBtn_clicked()
{
	ui.tabWidget->setCurrentIndex(1);
	ui.channelBtn->setStyleSheet("border:2px solid black; \
								border-top-width:0px; \
								border-right-width:0px; \
								border-left-width:0px; \
								border-bottom-width:2px; \
								border-bottom-color:#42BDAA; \
								color: #42BDAA;");
	ui.ioBtn->setStyleSheet("border:none;");
	ui.xiaolvBtn->setStyleSheet("border:none;");
}
//----------------------------------------------------------------------------
void DeSystemTestWidget::on_xiaolvBtn_clicked()
{
	ui.tabWidget->setCurrentIndex(2);
	ui.xiaolvBtn->setStyleSheet("border:2px solid black; \
								border-top-width:0px; \
								border-right-width:0px; \
								border-left-width:0px; \
								border-bottom-width:2px; \
								border-bottom-color:#42BDAA; \
								color: #42BDAA;");
	ui.ioBtn->setStyleSheet("border:none;");
	ui.channelBtn->setStyleSheet("border:none;");
}
//----------------------------------------------------------------------------
void DeSystemTestWidget::on_funcBtn_clicked()
{
	DeMenuWidget widget;
	widget.setShowMenuStatus(3);
	widget.exec();
}
//---------------------------------------------------------------------------
void DeSystemTestWidget::on_logoutBtn_clicked()
{
	Demo *demo = qApp->property("_mainWin").value<Demo *>();
	demo->slotBackMainWidget();
}
//----------------------------------------------------------------------------
void DeSystemTestWidget::setIOTestReulst(const QBitArray &value)
{
	if (!m_isIOTest)
		return ;

	QString propertyStr = "min-width:92px; \
				  max-width:92px; \
				  min-height:132px; \
				  max-height:132px;";
	if (value.testBit(0))
		ui.label->setStyleSheet(propertyStr + "image: url(:/Demo/Resources/xitongceshi-renyuanjiejin-zhengchang.png);");
	else
		ui.label->setStyleSheet(propertyStr + "image: url(:/Demo/Resources/xitongceshi-renyuanjiejin-yichang.png);");

	propertyStr = "min-width:114px; \
				  max-width:114px; \
				  min-height:116px; \
				  max-height:116px;";
	if (value.testBit(1))
		ui.label_3->setStyleSheet(propertyStr + "image: url(:/Demo/Resources/xitongceshi-jiaobuyali-zhengchang.png);");
	else
		ui.label_3->setStyleSheet(propertyStr + "image: url(:/Demo/Resources/xitongceshi-jiaobuyali-yichang.png);");


	propertyStr = "min-width:104px; \
				  max-width:104px; \
				  min-height:106px; \
				  max-height:106px;";
	if (value.testBit(2))
		ui.label_9->setStyleSheet(propertyStr + "image: url(:/Demo/Resources/xitongceshi-youshoutanceqi-zhengchang.png);");
	else
		ui.label_9->setStyleSheet(propertyStr + "image: url(:/Demo/Resources/xitongceshi-youshoutanceqi-yichang.png);");


	propertyStr = "min-width:94px; \
				  max-width:94px; \
				  min-height:118px; \
				  max-height:118px;";
	if (value.testBit(3))
		ui.label_5->setStyleSheet(propertyStr + "image: url(:/Demo/Resources/xitongceshi-zuoshouduisheshihongwai-zhengchang.png);");
	else
		ui.label_5->setStyleSheet(propertyStr + "image: url(:/Demo/Resources/xitongceshi-zuoshouduisheshihongwai-yichang.png);");


	propertyStr = "min-width:94px; \
				  max-width:94px; \
				  min-height:118px; \
				  max-height:118px;";
	if (value.testBit(4))
		ui.label_7->setStyleSheet(propertyStr + "image: url(:/Demo/Resources/xitongceshi-youshouduisheshihongwai-zhengchang.png);");
	else
		ui.label_7->setStyleSheet(propertyStr + "image: url(:/Demo/Resources/xitongceshi-youshouduisheshihongwai-yichang.png);");
}
//----------------------------------------------------------------------------
void DeSystemTestWidget::on_ioTestBtn_clicked()
{
	m_isIOTest = !m_isIOTest;
	if (m_isIOTest)
	{
		ui.ioTestBtn->setText(tr("È¡Ïû²âÊÔ"));
		ui.label_15->setText(tr("×´Ì¬: ÒÑ²âÊÔ"));
		QString	propertyStr = ui.ioTestBtn->styleSheet();
		///ÐÞ¸Ä±³¾°ÑÕÉ«Öµ
		propertyStr.replace("#42BDAA","#A20000");
		ui.ioTestBtn->setStyleSheet(propertyStr);

		QBitArray bitArray;
		bitArray.fill(false, 6);
		bitArray.setBit(1);
		setIOTestReulst(bitArray);
	}
	else
	{
		ui.ioTestBtn->setText(tr("¿ªÊ¼²âÊÔ"));
		ui.label_15->setText(tr("×´Ì¬: Î´²âÊÔ"));
		QString	propertyStr = ui.ioTestBtn->styleSheet();
		///ÐÞ¸Ä±³¾°ÑÕÉ«Öµ
		propertyStr.replace("#A20000", "#42BDAA");
		ui.ioTestBtn->setStyleSheet(propertyStr);

		initWidget();
	}
}
//----------------------------------------------------------------------------
void DeSystemTestWidget::initWidget()
{
	QString propertyStr = "min-width:92px; \
						  max-width:92px; \
						  min-height:132px; \
						  max-height:132px;";

	ui.label->setStyleSheet(propertyStr + "image: url(:/Demo/Resources/xitongceshi-renyuanjiejin.png);");

	propertyStr = "min-width:114px; \
				  max-width:114px; \
				  min-height:116px; \
				  max-height:116px;";
	ui.label_3->setStyleSheet(propertyStr + "image: url(:/Demo/Resources/xitongceshi-jiaobuyali.png);");


	propertyStr = "min-width:104px; \
				  max-width:104px; \
				  min-height:106px; \
				  max-height:106px;";
	ui.label_9->setStyleSheet(propertyStr + "image: url(:/Demo/Resources/xitongceshi-youshoutanceqi.png);");


	propertyStr = "min-width:94px; \
				  max-width:94px; \
				  min-height:118px; \
				  max-height:118px;";
	ui.label_5->setStyleSheet(propertyStr + "image: url(:/Demo/Resources/xitongceshi-zuoshouduisheshihongwai.png);");


	propertyStr = "min-width:94px; \
				  max-width:94px; \
				  min-height:118px; \
				  max-height:118px;";
	ui.label_7->setStyleSheet(propertyStr + "image: url(:/Demo/Resources/xitongceshi-youshouduisheshihongwai.png);");
}
//----------------------------------------------------------------------------
void DeSystemTestWidget::on_channelTestBtn_clicked()
{
}
//----------------------------------------------------------------------------
void DeSystemTestWidget::slotChannelValueChanged(int value)
{
}
//----------------------------------------------------------------------------
void DeSystemTestWidget::setChannelParam(int highValue, int value, int coefficient1, int coefficient2)
{
	ui.lineEdit->setText(QString::number(highValue));
	ui.lineEdit_2->setText(QString::number(highValue));
	ui.lineEdit_3->setText(QString::number(highValue));
	ui.lineEdit_4->setText(QString::number(highValue));
}
//----------------------------------------------------------------------------
void DeSystemTestWidget::slotChannelResult(ChannelResultData data)
{
	ChannelData resultData;
	resultData.alphaBeta = data.alphaBeta;
	resultData.alpha = data.alpha;
	resultData.Beta = data.Beta;
	m_channelMode->data().append(resultData);
	ui.widget_4->setModel(m_channelMode);
}
//----------------------------------------------------------------------------