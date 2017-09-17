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

	initEdit();
	readDataFromDB();

	//ui.dateEdit->setDate(QDate::currentDate());
	//ui.dateEdit->calendarWidget()->setGridVisible(true);

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
	intTMpList << 2 << 3 << 5 << 7 << 101;
	ui.widget_35->setValueList(intTMpList);
	ui.widget_38->setValueList(intTMpList);
}
//----------------------------------------------------------------------------
DeSystemConfigWidget::~DeSystemConfigWidget()
{

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
		Demo *demo = qApp->property("_mainWin").value<Demo *>();	
		DeMenuWidget widget;
		widget.setShowMenuStatus(2);
		widget.move(demo->pos());
		widget.resize(demo->width(), demo->height());
		widget.setWindowOpacity(0.9);
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
void DeSystemConfigWidget::on_datetimeBtn_clicked()
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
void DeSystemConfigWidget::slotDateClicked(const QDate & date)
{
	Demo *demo = qApp->property("_mainWin").value<Demo *>();

	QCalendarWidget *widget = (QCalendarWidget *)sender();
	ui.datetimeBtn->setText(widget->selectedDate().toString("yyyy-MM-dd"));
	demo->slotBackMainWidget();
}
//----------------------------------------------------------------------------