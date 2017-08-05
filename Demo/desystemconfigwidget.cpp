#include "desystemconfigwidget.h"
#include <QCalendarWidget>
#include "detestdatamodel.h"
#include "dealermeventmodel.h"

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
}
//----------------------------------------------------------------------------
DeSystemConfigWidget::~DeSystemConfigWidget()
{

}
//----------------------------------------------------------------------------
void DeSystemConfigWidget::on_okBtn_clicked()
{
	accept();
}
//----------------------------------------------------------------------------
void DeSystemConfigWidget::on_pushButton_4_clicked()
{
	QCalendarWidget *dateEdit = new QCalendarWidget(0);
	dateEdit->show();
}
//----------------------------------------------------------------------------
bool DeSystemConfigWidget::eventFilter(QObject *obj, QEvent *event)
 {
	 if (event->type() == QEvent::MouseButtonRelease) 
	 {
		 m_isFullShow = !m_isFullShow;

		 ui.groupBox->setVisible(!m_isFullShow);
		 ui.groupBox_2->setVisible(!m_isFullShow);
		 ui.groupBox_4->setVisible(!m_isFullShow);
		 ui.groupBox_5->setVisible(!m_isFullShow);

		 if (m_isFullShow)
			 ((QGroupBox *)obj)->setVisible(m_isFullShow);

         return true;
     }
	 else 
	 {
         // standard event processing
         return QObject::eventFilter(obj, event);
     }
 }
//----------------------------------------------------------------------------