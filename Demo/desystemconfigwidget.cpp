#include "desystemconfigwidget.h"
#include <QCalendarWidget>
#include "detestdatamodel.h"
#include "dealermeventmodel.h"
#include <demo.h>
#include <QSignalMapper>
#include <depropertyeditwidget.h>
#include <deadduserdlg.h>

Q_DECLARE_METATYPE(Demo *)
//----------------------------------------------------------------------------
DeSystemConfigWidget::DeSystemConfigWidget(QWidget *parent)
	: QDialog(parent)
	,m_isFullShow(false)
{
	ui.setupUi(this);
	this->setWindowFlags(Qt::ToolTip);
	ui.dateEdit->setDate(QDate::currentDate());
	ui.dateEdit->calendarWidget()->setGridVisible(true);

	ui.groupBox->installEventFilter(this);
	ui.groupBox_2->installEventFilter(this);
	ui.groupBox_4->installEventFilter(this);
	ui.groupBox_5->installEventFilter(this);

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

	initEdit();
}
//----------------------------------------------------------------------------
DeSystemConfigWidget::~DeSystemConfigWidget()
{

}
//----------------------------------------------------------------------------
void DeSystemConfigWidget::on_okBtn_clicked()
{
	Demo *demo = qApp->property("_mainWin").value<Demo *>();
	demo->slotBackMainWidget();
}
//----------------------------------------------------------------------------
bool DeSystemConfigWidget::eventFilter(QObject *obj, QEvent *event)
 {
	 if (event->type() == QEvent::MouseButtonRelease) 
	 {
		 m_isFullShow = !m_isFullShow;
         return true;
     }
	 else 
	 {
         // standard event processing
         return QObject::eventFilter(obj, event);
     }
 }
//----------------------------------------------------------------------------
void DeSystemConfigWidget::initEdit()
{
	ui.ipEdit->setProperty("customText", tr("IP地址"));

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
void DeSystemConfigWidget::propertyEditSlot(QWidget *w)
{
	DePropertyEditWidget *widget = new DePropertyEditWidget(this);
	QPushButton *button = (QPushButton *)w;
	QString header = button->property("customText").toString();
	widget->setHeadTitle(header);

	Demo *demo = qApp->property("_mainWin").value<Demo *>();
	demo->slotSetWidget(widget);
	//widget->exec();
}
//----------------------------------------------------------------------------