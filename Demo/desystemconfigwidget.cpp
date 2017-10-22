#include "desystemconfigwidget.h"
#include <QCalendarWidget>
#include "detestdatamodel.h"
#include "dealermeventmodel.h"
#include <demo.h>
#include "dedevicetable.h"
#include "demenuwidget.h"
#include <qcalendarwidget.h>
#include "dedetectormodel.h"

Q_DECLARE_METATYPE(Demo *)
//----------------------------------------------------------------------------
DeSystemConfigWidget::DeSystemConfigWidget(bool isMaintain, QWidget *parent)
	: QDialog(parent)
	,m_execIndex(0)
	,m_isMaintain(isMaintain)
{
	ui.setupUi(this);
	this->setWindowFlags(Qt::ToolTip);
	ui.tabWidget->findChildren<QTabBar*>().at(1)->hide();
	ui.tabWidget_3->findChildren<QTabBar*>().at(0)->hide();	

	on_deviceBtn_clicked();
	on_runStateBtn_clicked();

	initUI();
	readDataFromDB();

	if (!m_isMaintain)
	{
		ui.logoutBtn->setText("");
		ui.logoutBtn->setEnabled(false);
		ui.detectorBtn->hide();	
		ui.funcBtn->setText(tr("返回"));

		QList<DeCheckBox *> decheckList = this->findChildren<DeCheckBox *>();
		foreach (DeCheckBox *oneCheckbox, decheckList)
		{
			oneCheckbox->setReadOnly();
		}
	}
	else
		initEdit();

	///测量次数
	DeTestDataModel *mm = new DeTestDataModel(this);

	QList<TestData> data;
	data << TestData(1, 12, 100, 200, 0) 
		 << TestData(2, 12, 100, 200, 0) 
		 << TestData(3, 12, 100, 200, 0) 
		 << TestData(4, 12, 100, 200, 0)
		 << TestData(5, 12, 120, 201, 2)
		 << TestData(6, 12, 140, 200, 4);
	mm->setData(data);
	ui.widget->setModel(mm);
	ui.widget->hideMenu();

	///报警事件
	DeAlermEventModel *eventModel = new DeAlermEventModel(this);
	QList<AlermEventData> eData;
	eData << AlermEventData(1, 2, 3)
		<< AlermEventData(4, 5, 6)
		<< AlermEventData(7, 8, 9)
		<< AlermEventData(20, 22, 23)
		<< AlermEventData(20, 22, 23)
		<< AlermEventData(20, 22, 23);
	eventModel->setData(eData);	
	ui.widget_2->tableView()->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui.widget_2->tableView()->setSelectionMode(QAbstractItemView::SingleSelection);
	ui.widget_2->setModel(eventModel);

	DeDetectorModel *detectorModel = new DeDetectorModel(this);
	ui.channelTabelView->setModel(detectorModel);
	ui.channelTabelView->hideMenu();

	QList<int> intTMpList;
	intTMpList << 1 << 2 << 3 << 4;
	ui.widget_35->setValueList(intTMpList);
	intTMpList.clear();
	intTMpList << 200 << 250 << 500 << 1000;
	ui.widget_38->setValueList(intTMpList);
}
//----------------------------------------------------------------------------
DeSystemConfigWidget::~DeSystemConfigWidget()
{

}
//----------------------------------------------------------------------------
void DeSystemConfigWidget::initUI()
{
	ui.widget_31->setInitValue(tr("静态阀值"), true);
	ui.widget_42->setInitValue(tr("动态阀值"), false);

	ui.widget_43->setInitValue(tr("α"), true);
	ui.widget_44->setInitValue(tr("β"), false);
	ui.widget_45->setInitValue(tr("α+β"), false);	

	ui.widget_46->setInitValue(tr("1"), true);	
	ui.widget_47->setInitValue(tr("2"), true);	
	ui.widget_48->setInitValue(tr("3"), true);	
	ui.widget_49->setInitValue(tr("4"), true);	

	ui.datetimeBtn->setInitValue(QDateTime::currentDateTime().toString("yyyy-MM-dd"), true);
	ui.dateWeekBtn->setInitValue(tr("本周"), false);
	ui.dateDayBtn->setInitValue(tr("本日"), false);

	connect(ui.datetimeBtn, SIGNAL(signalCheckedChanged(bool)), this, SLOT(slotDatetimeBtn()));
	connect(ui.dateWeekBtn, SIGNAL(signalCheckedChanged(bool)), this, SLOT(slotDateWeekBtn()));
	connect(ui.dateDayBtn, SIGNAL(signalCheckedChanged(bool)), this, SLOT(slotDateDayBtn()));

	connect(ui.widget_31, SIGNAL(signalCheckedChanged(bool)), this, SLOT(slotDynamicValue()));
	connect(ui.widget_42, SIGNAL(signalCheckedChanged(bool)), this, SLOT(slotStaticValue()));
}
//----------------------------------------------------------------------------
void DeSystemConfigWidget::initEdit()
{
	ui.ipEdit->installEventFilter(&m_textDelegate);
	ui.timeEdit->installEventFilter(&m_intDelegate);
	ui.forceTestTimeEdit->installEventFilter(&m_intDelegate);
	ui.checkFatorEdit->installEventFilter(&m_intDelegate);
	ui.rCheckFatorEdit->installEventFilter(&m_intDelegate);
	ui.personFatorEdit->installEventFilter(&m_doubleDelegate);
	ui.resetTimeEdit->installEventFilter(&m_intDelegate);

	ui.alphaLowEdit->installEventFilter(&m_intDelegate);
	ui.alphaHighEdit->installEventFilter(&m_intDelegate);
	ui.alphaAlarmEdit->installEventFilter(&m_intDelegate);
	ui.alphaSAlarmEdit->installEventFilter(&m_intDelegate);
	ui.alphaThresholdEdit->installEventFilter(&m_intDelegate);
	ui.alphaSThresholdEdit->installEventFilter(&m_intDelegate);

	ui.betaLowEdit->installEventFilter(&m_intDelegate);
	ui.betaHighEdit->installEventFilter(&m_intDelegate);
	ui.betaAlarmEdit->installEventFilter(&m_intDelegate);
	ui.betaSAlarmEdit->installEventFilter(&m_intDelegate);
	ui.betaThresholdEdit->installEventFilter(&m_intDelegate);
	ui.betaSThresholdEdit->installEventFilter(&m_intDelegate);

	ui.lineEdit_2->installEventFilter(&m_tIntDelegate);
	ui.lineEdit_3->installEventFilter(&m_tIntDelegate);
	ui.lineEdit_6->installEventFilter(&m_tIntDelegate);
	ui.lineEdit_4->installEventFilter(&m_tIntDelegate);
	ui.lineEdit->installEventFilter(&m_tIntDelegate);

	connect(&m_textDelegate, SIGNAL(signalOwnerObj(QObject *)), this, SLOT(slotUpdateDatabase(QObject *)));
	connect(&m_intDelegate, SIGNAL(signalOwnerObj(QObject *)), this, SLOT(slotUpdateDatabase(QObject *)));
	connect(&m_doubleDelegate, SIGNAL(signalOwnerObj(QObject *)), this, SLOT(slotUpdateDatabase(QObject *)));
}
//----------------------------------------------------------------------------
void DeSystemConfigWidget::slotUpdateDatabase(QObject *object)
{
	if (ui.ipEdit == object)
	{
		m_systemParamData.setIp(ui.ipEdit->text());		
	}

	if (ui.timeEdit == object)
	{
		int time = ui.timeEdit->text().toInt();
		m_systemParamData.setMeasurementTime(time);
	}

	if (ui.forceTestTimeEdit == object)
	{
		int time = ui.forceTestTimeEdit->text().toInt();
		m_systemParamData.setCheckTime(time);
	}

	if (ui.checkFatorEdit == object)
	{
		int factor = ui.checkFatorEdit->text().toInt();
		m_systemParamData.setcheckFactor(factor);
	}

	if (ui.rCheckFatorEdit == object)
	{
		int factor = ui.rCheckFatorEdit->text().toInt();
		m_systemParamData.setRadiationCheckFactor(factor);
	}

	if (ui.personFatorEdit == object)
	{
		float factor = ui.personFatorEdit->text().toFloat();
		m_systemParamData.setPersonnelFactor(factor);
	}

	///////////////////////alpha//////////////////////////
	if (ui.resetTimeEdit == object)
	{
		int  alarmTime = ui.resetTimeEdit->text().toInt();
		m_systemParamData.setAlarmResetTime(alarmTime);
	}

	if (ui.alphaLowEdit == object)
	{
		int low = ui.alphaLowEdit->text().toInt();
		m_systemParamData.setAlphaLowAlarmThreshold(low);
	}

	if (ui.alphaHighEdit == object)
	{
		int high = ui.alphaHighEdit->text().toInt();
		m_systemParamData.setAlphaHighAlarmThreshold(high);
	}

	if (ui.alphaAlarmEdit == object)
	{			
		int coefficient = ui.alphaAlarmEdit->text().toInt();
		m_systemParamData.setAlphaAlramCoefficient(coefficient);
	}

	if (ui.alphaSAlarmEdit == object)
	{			
		int coefficient = ui.alphaSAlarmEdit->text().toInt();
		m_systemParamData.setAlphaSeriousAlramCoefficient(coefficient);
	}

	if (ui.alphaThresholdEdit == object)
	{			
		int threshold = ui.alphaThresholdEdit->text().toInt();
		m_systemParamData.setAlphaThreshold(threshold);
	}

	if (ui.alphaSThresholdEdit == object)
	{			
		int threshold = ui.alphaSThresholdEdit->text().toInt();
		m_systemParamData.setAlphaSeriousThreshold(threshold);
	}

	///////////////////////Beta//////////////////////////
	if (ui.betaLowEdit == object)
	{
		int low = ui.betaLowEdit->text().toInt();
		m_systemParamData.setBetaLowAlarmThreshold(low);
	}

	if (ui.betaHighEdit == object)
	{
		int high = ui.betaHighEdit->text().toInt();
		m_systemParamData.setBetaHighAlarmThreshold(high);
	}

	if (ui.betaAlarmEdit == object)
	{
		int coefficient = ui.betaAlarmEdit->text().toInt();
		m_systemParamData.setBetaAlramCoefficient(coefficient);
	}

	if (ui.betaSAlarmEdit == object)
	{
		int coefficient = ui.betaSAlarmEdit->text().toInt();
		m_systemParamData.setBetaSeriousAlramCoefficient(coefficient);
	}

	if (ui.betaThresholdEdit == object)
	{
		int threshold = ui.betaThresholdEdit->text().toInt();
		m_systemParamData.setBetaThreshold(threshold);
	}

	if (ui.betaSThresholdEdit == object)
	{
		int threshold = ui.betaSThresholdEdit->text().toInt();
		m_systemParamData.setBetaSeriousThreshold(threshold);
	}

	updateDataBase();
}
//----------------------------------------------------------------------------
void DeSystemConfigWidget::updateDataBase()
{
	Demo *demo = qApp->property("_mainWin").value<Demo *>();
	DeDeviceTable deviceTable(demo->dataBase());
	deviceTable.updateDataToDataBase(m_systemParamData);
}
//----------------------------------------------------------------------------
void DeSystemConfigWidget::readDataFromDB()
{
	///从数据库获取设备数据
	Demo *demo = qApp->property("_mainWin").value<Demo *>();
	DeDeviceTable deviceTable(demo->dataBase());
	m_systemParamData = deviceTable.selectDB();

	ui.ipEdit->setText(m_systemParamData.getIp());
	ui.timeEdit->setText(QString::number(m_systemParamData.getMeasurementTime()));
	ui.forceTestTimeEdit->setText(QString::number(m_systemParamData.getCheckTime()));
	ui.checkFatorEdit->setText(QString::number(m_systemParamData.getcheckFactor()));
	ui.rCheckFatorEdit->setText(QString::number(m_systemParamData.getRadiationCheckFactor()));
	ui.personFatorEdit->setText(QString::number(m_systemParamData.getPersonnelFactor()));
	ui.resetTimeEdit->setText(QString::number(m_systemParamData.getAlarmResetTime()));

	ui.alphaLowEdit->setText(QString::number(m_systemParamData.getAlphaLowAlarmThreshold()));
	ui.alphaHighEdit->setText(QString::number(m_systemParamData.getAlphaHighAlarmThreshold()));
	ui.alphaAlarmEdit->setText(QString::number(m_systemParamData.getAlphaAlramCoefficient()));
	ui.alphaSAlarmEdit->setText(QString::number(m_systemParamData.getAlphaSeriousAlramCoefficient()));
	ui.alphaThresholdEdit->setText(QString::number(m_systemParamData.getAlphaThreshold()));
	ui.alphaSThresholdEdit->setText(QString::number(m_systemParamData.getAlphaSeriousThreshold()));

	ui.betaLowEdit->setText(QString::number(m_systemParamData.getBetaLowAlarmThreshold()));
	ui.betaHighEdit->setText(QString::number(m_systemParamData.getBetaHighAlarmThreshold()));
	ui.betaAlarmEdit->setText(QString::number(m_systemParamData.getBetaAlramCoefficient()));
	ui.betaSAlarmEdit->setText(QString::number(m_systemParamData.getBetaSeriousAlramCoefficient()));
	ui.betaThresholdEdit->setText(QString::number(m_systemParamData.getBetaThreshold()));
	ui.betaSThresholdEdit->setText(QString::number(m_systemParamData.getBetaSeriousThreshold()));
}
//----------------------------------------------------------------------------
void DeSystemConfigWidget::on_deviceBtn_clicked()
{
	ui.tabWidget->setCurrentIndex(0);
	ui.deviceBtn->setStyleSheet("border:2px solid black; \
								border-top-width:0px; \
								border-right-width:0px; \
								border-left-width:0px; \
								border-bottom-width:2px; \
								border-bottom-color:#42BDAA;\
								color: #42BDAA;");
	ui.testBtn->setStyleSheet("border:none;");
	ui.detectorBtn->setStyleSheet("border:none;");
}
//----------------------------------------------------------------------------
void DeSystemConfigWidget::on_testBtn_clicked()
{
	ui.tabWidget->setCurrentIndex(1);
	ui.testBtn->setStyleSheet("border:2px solid black; \
								border-top-width:0px; \
								border-right-width:0px; \
								border-left-width:0px; \
								border-bottom-width:2px; \
								border-bottom-color:#42BDAA; \
								color: #42BDAA;");
	ui.deviceBtn->setStyleSheet("border:none;");
	ui.detectorBtn->setStyleSheet("border:none;");
}
//----------------------------------------------------------------------------
void DeSystemConfigWidget::on_detectorBtn_clicked()
{
	ui.tabWidget->setCurrentIndex(2);
	ui.detectorBtn->setStyleSheet("border:2px solid black; \
								  border-top-width:0px; \
								  border-right-width:0px; \
								  border-left-width:0px; \
								  border-bottom-width:2px; \
								  border-bottom-color:#42BDAA;\
								  color: #42BDAA;");
	ui.testBtn->setStyleSheet("border:none;");
	ui.deviceBtn->setStyleSheet("border:none;");
}
//----------------------------------------------------------------------------
void DeSystemConfigWidget::on_runStateBtn_clicked()
{
	ui.tabWidget_3->setCurrentIndex(0);
	ui.runStateBtn->setStyleSheet("border:2px solid black; \
								  border-top-width:0px; \
								  border-right-width:0px; \
								  border-left-width:0px; \
								  border-bottom-width:2px; \
								  border-bottom-color:#42BDAA;\
								  color: #42BDAA;");
	ui.testParamBtn->setStyleSheet("border:none;");
	ui.alphaBtn->setStyleSheet("border:none;");
	ui.betaBtn->setStyleSheet("border:none;");
}
//----------------------------------------------------------------------------
void DeSystemConfigWidget::on_testParamBtn_clicked()
{
	ui.tabWidget_3->setCurrentIndex(1);
	ui.testParamBtn->setStyleSheet("border:2px solid black; \
								  border-top-width:0px; \
								  border-right-width:0px; \
								  border-left-width:0px; \
								  border-bottom-width:2px; \
								  border-bottom-color:#42BDAA;\
								  color: #42BDAA;");
	ui.runStateBtn->setStyleSheet("border:none;");
	ui.alphaBtn->setStyleSheet("border:none;");
	ui.betaBtn->setStyleSheet("border:none;");
}
//----------------------------------------------------------------------------
void DeSystemConfigWidget::on_alphaBtn_clicked()
{
	ui.tabWidget_3->setCurrentIndex(2);
	ui.alphaBtn->setStyleSheet("border:2px solid black; \
								  border-top-width:0px; \
								  border-right-width:0px; \
								  border-left-width:0px; \
								  border-bottom-width:2px; \
								  border-bottom-color:#42BDAA;\
								  color: #42BDAA;");
	ui.runStateBtn->setStyleSheet("border:none;");
	ui.testParamBtn->setStyleSheet("border:none;");
	ui.betaBtn->setStyleSheet("border:none;");
}
//----------------------------------------------------------------------------
void DeSystemConfigWidget::on_betaBtn_clicked()
{
	ui.tabWidget_3->setCurrentIndex(3);	
	ui.betaBtn->setStyleSheet("border:2px solid black; \
								  border-top-width:0px; \
								  border-right-width:0px; \
								  border-left-width:0px; \
								  border-bottom-width:2px; \
								  border-bottom-color:#42BDAA;\
								  color: #42BDAA;");
	ui.runStateBtn->setStyleSheet("border:none;");
	ui.testParamBtn->setStyleSheet("border:none;");
	ui.alphaBtn->setStyleSheet("border:none;");
}
//----------------------------------------------------------------------------
void DeSystemConfigWidget::on_funcBtn_clicked()
{
	if (m_isMaintain)
	{	
		DeMenuWidget widget;
		widget.setShowMenuStatus(2);
		widget.exec();	
	}
	else
	{
		Demo *demo = qApp->property("_mainWin").value<Demo *>();
		demo->slotBackMainWidget();
	}
}
//----------------------------------------------------------------------------
void DeSystemConfigWidget::on_logoutBtn_clicked()
{
	Demo *demo = qApp->property("_mainWin").value<Demo *>();
	demo->slotBackMainWidget();
}
//----------------------------------------------------------------------------
void DeSystemConfigWidget::slotDatetimeBtn()
{
	Demo *demo = qApp->property("_mainWin").value<Demo *>();
	///自定义系统的日期选择菜单
	QCalendarWidget *calendarWidget = new QCalendarWidget;
	calendarWidget->setSelectionMode(QCalendarWidget::SingleSelection);
	connect(calendarWidget, SIGNAL(clicked(const QDate &)), this, SLOT(slotDateClicked(const QDate &)), Qt::QueuedConnection);

	calendarWidget->setGridVisible(true);
	calendarWidget->setStyleSheet("QToolButton{min-width:60px; min-height:40px;border:none} \
								  QWidget{font:24px bold \"黑体\";}");

	QWidget *contentWidget = calendarWidget->findChild<QWidget *>("qt_calendar_calendarview");
	contentWidget->setStyleSheet("selection-background-color: rgb(66, 189, 170); \
								 selection-color: rgb(254, 255, 253);");

	QWidget *headWidget = calendarWidget->findChild<QWidget *>("qt_calendar_navigationbar");
	headWidget->setStyleSheet("background-color: rgb(240, 240, 240); \
							  color: rgb(66, 189, 170)");

	demo->slotSetWidget(calendarWidget);
}
//----------------------------------------------------------------------------
void DeSystemConfigWidget::slotDateClicked(const QDate &)
{
	Demo *demo = qApp->property("_mainWin").value<Demo *>();

	QCalendarWidget *widget = (QCalendarWidget *)sender();
	ui.datetimeBtn->setInitValue(widget->selectedDate().toString("yyyy-MM-dd"), true);
	ui.dateWeekBtn->setChecked(false);
	ui.dateDayBtn->setChecked(false);
	demo->slotBackMainWidget();
}
//----------------------------------------------------------------------------
void DeSystemConfigWidget::slotDateWeekBtn()
{
	ui.datetimeBtn->setChecked(false);
	ui.dateWeekBtn->setChecked(true);
	ui.dateDayBtn->setChecked(false);
}
//----------------------------------------------------------------------------
void DeSystemConfigWidget::slotDateDayBtn()
{
	ui.datetimeBtn->setChecked(false);
	ui.dateWeekBtn->setChecked(false);
	ui.dateDayBtn->setChecked(true);
}
//----------------------------------------------------------------------------
void DeSystemConfigWidget::slotDynamicValue()
{
	ui.widget_31->setChecked(true);
	ui.widget_42->setChecked(false);
}
//----------------------------------------------------------------------------
void DeSystemConfigWidget::slotStaticValue()
{
	ui.widget_42->setChecked(true);
	ui.widget_31->setChecked(false);
}
//----------------------------------------------------------------------------