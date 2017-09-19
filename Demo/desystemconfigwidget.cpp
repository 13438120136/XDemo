#include "desystemconfigwidget.h"
#include <QCalendarWidget>
#include "detestdatamodel.h"
#include "dealermeventmodel.h"
#include <demo.h>
#include <QSignalMapper>
#include <depropertyeditwidget.h>
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

	if (!m_isMaintain)
	{
		ui.logoutBtn->setText("");
		ui.logoutBtn->setEnabled(false);
		ui.detectorBtn->hide();	
		ui.funcBtn->setText(tr("返回"));
	}

	initUI();
	initEdit();
	readDataFromDB();

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
}
//----------------------------------------------------------------------------
bool DeSystemConfigWidget::execValidAndSave(const QString &str)
{
	switch(m_execIndex)
	{
	case 1:
		{
			setIpAddress(str);
			break;
		}
	case 2:
		{
			int time = str.toInt();
			setMeasurementTime(time);
			break;
		}
	case 3:
		{
			int time = str.toInt();
			setCheckTime(time);
			break;
		}
	case 4:
		{
			int time = str.toInt();
			setcheckFactor(time);
			break;
		}
	case 5:
		{
			int time = str.toInt();
			setRadiationCheckFactor(time);
			break;
		}
	case 6:
		{
			float time = str.toFloat();
			setPersonnelFactor(time);
			break;
		}
	case 7:
		{
			int time = str.toInt();
			setAlarmResetTime(time);
			break;
		}

	case 8:
		{
			int time = str.toInt();
			setAlphaLowAlarmThreshold(time);
			break;
		}
	case 9:
		{
			int time = str.toInt();
			setAlphaHighAlarmThreshold(time);
			break;
		}
	case 10:
		{
			int time = str.toInt();
			setAlphaAlramCoefficient(time);
			break;
		}
	case 11:
		{
			int time = str.toInt();
			setAlphaSeriousAlramCoefficient(time);
			break;
		}
	case 12:
		{
			int time = str.toInt();
			setAlphaThreshold(time);
			break;
		}
	case 13:
		{
			int time = str.toInt();
			setAlphaSeriousThreshold(time);
			break;
		}
		///////////////////////Beta//////////////////////////
	case 14:
		{
			int time = str.toInt();
			setBetaLowAlarmThreshold(time);
			break;
		}
	case 15:
		{
			int time = str.toInt();
			setBetaHighAlarmThreshold(time);
			break;
		}
	case 16:
		{
			int time = str.toInt();
			setBetaAlramCoefficient(time);
			break;
		}
	case 17:
		{
			int time = str.toInt();
			setBetaSeriousAlramCoefficient(time);
			break;
		}
	case 18:
		{
			int time = str.toInt();
			setBetaThreshold(time);
			break;
		}
	case 19:
		{
			int time = str.toInt();
			setBetaSeriousThreshold(time);
			break;
		}
	}
	return true;
}
//----------------------------------------------------------------------------
void DeSystemConfigWidget::propertyEditSlot(QWidget *w)
{
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

	//ui.ipEdit->setText(m_systemParamData.getIp());
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
void DeSystemConfigWidget::setIpAddress(const QString &ip)
{
	//ui.ipEdit->setText(ip);
	m_systemParamData.setIp(ip);
	updateDataBase();
}
//----------------------------------------------------------------------------
void DeSystemConfigWidget::setLanguage()
{
	updateDataBase();
}
//----------------------------------------------------------------------------
void DeSystemConfigWidget::setThresholdType(int type)
{
	m_systemParamData.setThresholdType(type);
	updateDataBase();
}
//----------------------------------------------------------------------------
void DeSystemConfigWidget::setMeasurementTime(int time)
{
	ui.timeEdit->setText(QString::number(time));
	m_systemParamData.setMeasurementTime(time);
	updateDataBase();
}
//----------------------------------------------------------------------------
void DeSystemConfigWidget::setCheckTime(int time)
{
	ui.forceTestTimeEdit->setText(QString::number(time));
	m_systemParamData.setCheckTime(time);
	updateDataBase();
}
//----------------------------------------------------------------------------
void DeSystemConfigWidget::setcheckFactor(int factor)
{
	ui.checkFatorEdit->setText(QString::number(factor));
	m_systemParamData.setcheckFactor(factor);
	updateDataBase();
}
//----------------------------------------------------------------------------
void DeSystemConfigWidget::setRadiationCheckFactor(int factor)
{
	ui.rCheckFatorEdit->setText(QString::number(factor));
	m_systemParamData.setRadiationCheckFactor(factor);
	updateDataBase();
}
//----------------------------------------------------------------------------
void DeSystemConfigWidget::setPersonnelFactor(float factor)
{
	ui.personFatorEdit->setText(QString::number(factor));
	m_systemParamData.setPersonnelFactor(factor);
	updateDataBase();
}
//----------------------------------------------------------------------------
void DeSystemConfigWidget::setAlarmResetTime(int alarmTime)
{
	ui.resetTimeEdit->setText(QString::number(alarmTime));
	m_systemParamData.setAlarmResetTime(alarmTime);
	updateDataBase();
}
//----------------------------------------------------------------------------
void DeSystemConfigWidget::setAlarmTime(int alarmTime)
{

}
//----------------------------------------------------------------------------
void DeSystemConfigWidget::setAlphaLowAlarmThreshold(int low)
{
	ui.alphaLowEdit->setText(QString::number(low));
	m_systemParamData.setAlphaLowAlarmThreshold(low);
	updateDataBase();
}
//----------------------------------------------------------------------------
void DeSystemConfigWidget::setAlphaHighAlarmThreshold(int high)
{
	ui.alphaHighEdit->setText(QString::number(high));
	m_systemParamData.setAlphaHighAlarmThreshold(high);
	updateDataBase();
}
//----------------------------------------------------------------------------
void DeSystemConfigWidget::setAlphaAlramCoefficient(int coefficient)
{
	ui.alphaAlarmEdit->setText(QString::number(coefficient));
	m_systemParamData.setAlphaAlramCoefficient(coefficient);
	updateDataBase();
}
//----------------------------------------------------------------------------
void DeSystemConfigWidget::setAlphaSeriousAlramCoefficient(int coefficient)
{
	ui.alphaSAlarmEdit->setText(QString::number(coefficient));
	m_systemParamData.setAlphaSeriousAlramCoefficient(coefficient);
	updateDataBase();
}
//----------------------------------------------------------------------------
void DeSystemConfigWidget::setAlphaThreshold(int threshold)
{
	ui.alphaThresholdEdit->setText(QString::number(threshold));
	m_systemParamData.setAlphaThreshold(threshold);
	updateDataBase();
}
//----------------------------------------------------------------------------
void DeSystemConfigWidget::setAlphaSeriousThreshold(int threshold)
{
	ui.alphaSThresholdEdit->setText(QString::number(threshold));
	m_systemParamData.setAlphaSeriousThreshold(threshold);
	updateDataBase();
}
//----------------------------------------------------------------------------
void DeSystemConfigWidget::setBetaLowAlarmThreshold(int low)
{
	ui.betaLowEdit->setText(QString::number(low));
	m_systemParamData.setBetaLowAlarmThreshold(low);
	updateDataBase();
}
//----------------------------------------------------------------------------
void DeSystemConfigWidget::setBetaHighAlarmThreshold(int high)
{
	ui.betaHighEdit->setText(QString::number(high));
	m_systemParamData.setBetaHighAlarmThreshold(high);
	updateDataBase();
}
//----------------------------------------------------------------------------
void DeSystemConfigWidget::setBetaAlramCoefficient(int coefficient)
{
	ui.betaAlarmEdit->setText(QString::number(coefficient));
	m_systemParamData.setBetaAlramCoefficient(coefficient);
	updateDataBase();
}
//----------------------------------------------------------------------------
void DeSystemConfigWidget::setBetaSeriousAlramCoefficient(int coefficient)
{
	ui.betaSAlarmEdit->setText(QString::number(coefficient));
	m_systemParamData.setBetaSeriousAlramCoefficient(coefficient);
	updateDataBase();
}
//----------------------------------------------------------------------------
void DeSystemConfigWidget::setBetaThreshold(int threshold)
{
	ui.betaThresholdEdit->setText(QString::number(threshold));
	m_systemParamData.setBetaThreshold(threshold);
	updateDataBase();
}
//----------------------------------------------------------------------------
void DeSystemConfigWidget::setBetaSeriousThreshold(int threshold)
{
	ui.betaSThresholdEdit->setText(QString::number(threshold));
	m_systemParamData.setBetaSeriousThreshold(threshold);
	updateDataBase();
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