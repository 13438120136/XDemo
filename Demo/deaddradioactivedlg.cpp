#include "deaddradioactivedlg.h"
#include "demo.h"
#include <QCalendarWidget>

Q_DECLARE_METATYPE(Demo *)
//----------------------------------------------------------------------------
DeAddRadioactiveDlg::DeAddRadioactiveDlg(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	ui.okBtn->setEnabled(false);

	ui.idLineEdit->installEventFilter(this);
	ui.originalLineEdit->installEventFilter(this);
	ui.lineEdit->setText(QDateTime::currentDateTime().toString("yyyy/MM/dd"));
	ui.widget_3->addItem(tr("测试1"));
	ui.widget_3->addItem(tr("测试2"));

	connect(ui.idLineEdit, SIGNAL(textChanged(const QString &)), this, SLOT(slotIDLineEdit(const QString &)));
	connect(ui.originalLineEdit, SIGNAL(textChanged(const QString &)), this, SLOT(slotValueLineEdit(const QString &)));
}
//----------------------------------------------------------------------------
DeAddRadioactiveDlg::~DeAddRadioactiveDlg()
{

}
//----------------------------------------------------------------------------
void DeAddRadioactiveDlg::on_okBtn_clicked()
{
	int id = ui.idLineEdit->text().toInt();
	int value = ui.originalLineEdit->text().toInt();
	quint64 time = 0;// ui.dateEdit->dateTime().currentMSecsSinceEpoch();

	Demo *demo = qApp->property("_mainWin").value<Demo *>();
	DeSqlDataBase *dataBase = demo->dataBase();
	DeRadioactiveSourceTable table(dataBase);
	table.setID(id);
	table.setDateProduct(time);
	table.setOriginalValue(value);
	table.insertDataToDB();

	emit signalAddRadioactiveData(table);
	demo->slotBackMainWidget();	
}
//----------------------------------------------------------------------------
void DeAddRadioactiveDlg::on_cancelBtn_clicked()
{
	Demo *demo = qApp->property("_mainWin").value<Demo *>();
	demo->slotBackMainWidget();	
}
//----------------------------------------------------------------------------
void DeAddRadioactiveDlg::slotIDLineEdit(const QString & text)
{
	Q_UNUSED(text)
	QString id = ui.idLineEdit->text();
	QString value = ui.originalLineEdit->text();

	ui.okBtn->setEnabled (!id.isEmpty() && !value.isEmpty());
}
//----------------------------------------------------------------------------
void DeAddRadioactiveDlg::slotValueLineEdit(const QString & text)
{
	Q_UNUSED(text)
	QString id = ui.idLineEdit->text();
	QString value = ui.originalLineEdit->text();

	ui.okBtn->setEnabled (!id.isEmpty() && !value.isEmpty());
}
//----------------------------------------------------------------------------
void DeAddRadioactiveDlg::on_dateBtn_clicked()
{
	Demo *demo = qApp->property("_mainWin").value<Demo *>();
	///自定义系统的日期选择菜单
	QCalendarWidget *calendarWidget = new QCalendarWidget;
	connect(calendarWidget, SIGNAL(activated(const QDate & date)), this, SLOT(slotDateClicked(const QDate & date)));

	calendarWidget->setGridVisible(true);
	calendarWidget->setStyleSheet("QToolButton{min-width:60px; min-height:40px;border:none} \
								  QWidget{font:24px bold \"微软雅黑\";}");

	QWidget *contentWidget = calendarWidget->findChild<QWidget *>("qt_calendar_calendarview");
	contentWidget->setStyleSheet("selection-background-color: rgb(66, 189, 170); \
								 selection-color: rgb(254, 255, 253);");

	QWidget *headWidget = calendarWidget->findChild<QWidget *>("qt_calendar_navigationbar");
	headWidget->setStyleSheet("background-color: rgb(240, 240, 240); \
							  color: rgb(66, 189, 170)");

	demo->slotSetWidget(calendarWidget);
}
//----------------------------------------------------------------------------
void DeAddRadioactiveDlg::slotDateClicked(const QDate & date)
{
	Demo *demo = qApp->property("_mainWin").value<Demo *>();
	demo->slotBackMainWidget();

	ui.lineEdit->setText(date.currentDate().toString("yyyy/MM/dd"));
}
//----------------------------------------------------------------------------