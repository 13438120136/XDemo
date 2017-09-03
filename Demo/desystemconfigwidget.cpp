#include "desystemconfigwidget.h"
#include <QCalendarWidget>
#include "detestdatamodel.h"
#include "dealermeventmodel.h"
#include <demo.h>
#include <QSignalMapper>
#include <depropertyeditwidget.h>
#include "dedevicetable.h"
#include "demenuwidget.h"

Q_DECLARE_METATYPE(Demo *)
//----------------------------------------------------------------------------
DeSystemConfigWidget::DeSystemConfigWidget(QWidget *parent)
	: QDialog(parent)
	,m_execIndex(0)
{
	ui.setupUi(this);
	this->setWindowFlags(Qt::ToolTip);
	ui.tabWidget->findChildren<QTabBar*>().at(2)->hide();
	ui.tabWidget_2->findChildren<QTabBar*>().at(0)->hide();
	ui.tabWidget_3->findChildren<QTabBar*>().at(0)->hide();	

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
		 << TestData(5, 12, 100, 200, 0)
		 << TestData(7, 12, 120, 201, 2)
		 << TestData(8, 12, 140, 200, 4)
		 << TestData(9, 12, 150, 200, 10)
		 << TestData(6, 12, 100, 200, 20);
	mm->setData(data);
	ui.widget->setModel(mm);

	///报警事件
	DeAlermEventModel *eventModel = new DeAlermEventModel(this);
	QList<AlermEventData> eData;
	eData << AlermEventData(1, 2, 3)
		<< AlermEventData(4, 5, 6)
		<< AlermEventData(7, 8, 9)
		<< AlermEventData(20, 22, 23);
	eventModel->setData(eData);	
	ui.widget_2->setModel(eventModel);
}
//----------------------------------------------------------------------------
DeSystemConfigWidget::~DeSystemConfigWidget()
{

}
//----------------------------------------------------------------------------
void DeSystemConfigWidget::initEdit()
{
	//ui.ipEdit->setProperty("customText", tr("IP地址设置"));
	ui.timeEdit->setProperty("customText", tr("测量时间"));
	ui.forceTestTimeEdit->setProperty("customText", tr("强制本底测量时间"));
	ui.checkFatorEdit->setProperty("customText", tr("本底检测平滑因子"));
	ui.rCheckFatorEdit->setProperty("customText", tr("辐射检测平滑因子"));
	ui.personFatorEdit->setProperty("customText", tr("人员屏蔽补偿因子"));
	ui.resetTimeEdit->setProperty("customText", tr("报警自动恢复时间"));

	ui.alphaLowEdit->setProperty("customText", tr("alpha 低本底报警阀值"));
	ui.alphaHighEdit->setProperty("customText", tr("alpha 高本底报警阀值"));
	ui.alphaAlarmEdit->setProperty("customText", tr("alpha 报警系数"));
	ui.alphaSAlarmEdit->setProperty("customText", tr("alpha 严重报警系数"));
	ui.alphaThresholdEdit->setProperty("customText", tr("alpha 报警阀值"));
	ui.alphaSThresholdEdit->setProperty("customText", tr("alpha 严重报警阀值"));

	ui.betaLowEdit->setProperty("customText", tr("beta 低本底报警阀值"));
	ui.betaHighEdit->setProperty("customText", tr("beta 高本底报警阀值"));
	ui.betaAlarmEdit->setProperty("customText", tr("beta 报警系数"));
	ui.betaSAlarmEdit->setProperty("customText", tr("beta 严重报警系数"));
	ui.betaThresholdEdit->setProperty("customText", tr("beta 报警阀值"));
	ui.betaSThresholdEdit->setProperty("customText", tr("beta 严重报警阀值"));

	////新建执行索引
	//ui.ipEdit->setProperty("customIndex", 1);
	ui.timeEdit->setProperty("customIndex", 2);
	ui.forceTestTimeEdit->setProperty("customIndex", 3);
	ui.checkFatorEdit->setProperty("customIndex", 4);
	ui.rCheckFatorEdit->setProperty("customIndex", 5);
	ui.personFatorEdit->setProperty("customIndex", 6);
	ui.resetTimeEdit->setProperty("customIndex", 7);

	ui.alphaLowEdit->setProperty("customIndex", 8);
	ui.alphaHighEdit->setProperty("customIndex", 9);
	ui.alphaAlarmEdit->setProperty("customIndex", 10);
	ui.alphaSAlarmEdit->setProperty("customIndex", 11);
	ui.alphaThresholdEdit->setProperty("customIndex", 12);
	ui.alphaSThresholdEdit->setProperty("customIndex", 13);

	ui.betaLowEdit->setProperty("customIndex", 14);
	ui.betaHighEdit->setProperty("customIndex", 15);
	ui.betaAlarmEdit->setProperty("customIndex", 16);
	ui.betaSAlarmEdit->setProperty("customIndex", 17);
	ui.betaThresholdEdit->setProperty("customIndex", 18);
	ui.betaSThresholdEdit->setProperty("customIndex", 19);

	QSignalMapper *signalMapper = new QSignalMapper(this);
	QList<QAbstractButton *> listButtons = ui.buttonGroup->buttons();
	int nCount = listButtons.size();
	for (int i = 0; i < nCount; i++)
	{
		QPushButton *button = (QPushButton *)listButtons[i];
		connect(button, SIGNAL(clicked()), signalMapper, SLOT(map()));
		signalMapper->setMapping(button, button);
	}

	connect(signalMapper, SIGNAL(mapped(QWidget *)),
		this, SLOT(propertyEditSlot(QWidget *)));
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
	DePropertyEditWidget *widget = new DePropertyEditWidget(this);
	QPushButton *button = (QPushButton *)w;
	QString header = button->property("customText").toString();
	widget->setSystemConfigWidget(this);
	widget->setHeadTitle(header);
	widget->setContentText(button->text());
	m_execIndex = button->property("customIndex").toInt();

	Demo *demo = qApp->property("_mainWin").value<Demo *>();
	demo->slotSetWidget(widget);
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
}
//----------------------------------------------------------------------------
void DeSystemConfigWidget::on_testBtn_clicked()
{
	ui.tabWidget->setCurrentIndex(1);
}
//----------------------------------------------------------------------------
void DeSystemConfigWidget::on_runStateBtn_clicked()
{
	ui.tabWidget_3->setCurrentIndex(0);
}
//----------------------------------------------------------------------------
void DeSystemConfigWidget::on_testParamBtn_clicked()
{
	ui.tabWidget_3->setCurrentIndex(1);
}
//----------------------------------------------------------------------------
void DeSystemConfigWidget::on_alphaBtn_clicked()
{
	ui.tabWidget_3->setCurrentIndex(2);
}
//----------------------------------------------------------------------------
void DeSystemConfigWidget::on_betaBtn_clicked()
{
	ui.tabWidget_3->setCurrentIndex(3);
}
//----------------------------------------------------------------------------
void DeSystemConfigWidget::on_funcBtn_clicked()
{	
	Demo *demo = qApp->property("_mainWin").value<Demo *>();	
	DeMenuWidget widget;
	widget.move(demo->pos());
	widget.resize(demo->width(), demo->height());
	widget.setWindowOpacity(0.9);
	widget.exec();	
}
//----------------------------------------------------------------------------
void DeSystemConfigWidget::on_logoutBtn_clicked()
{
	Demo *demo = qApp->property("_mainWin").value<Demo *>();
	demo->slotBackMainWidget();
}
//----------------------------------------------------------------------------