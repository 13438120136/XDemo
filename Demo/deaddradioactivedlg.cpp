#include "deaddradioactivedlg.h"
#include "demo.h"
#include <QCalendarWidget>

Q_DECLARE_METATYPE(Demo *)
//----------------------------------------------------------------------------
DeAddRadioactiveDlg::DeAddRadioactiveDlg(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	ui.keyBoradWidget->hide();
	ui.okBtn->setEnabled(false);
	ui.dateEdit->setDate(QDate::currentDate());
	ui.dateEdit->calendarWidget()->setGridVisible(true);

	ui.idLineEdit->installEventFilter(this);
	ui.originalLineEdit->installEventFilter(this);

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
	quint64 time = ui.dateEdit->dateTime().currentMSecsSinceEpoch();

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
bool DeAddRadioactiveDlg::eventFilter(QObject *obj, QEvent *event)
{
	if (event->type() == QEvent::MouseButtonRelease) 
	{
		ui.keyBoradWidget->setEditControl((QLineEdit *)obj);
		ui.keyBoradWidget->show();
		return true;
	}
	else 
	{
		// standard event processing
		return QObject::eventFilter(obj, event);
	}
}
//----------------------------------------------------------------------------
void DeAddRadioactiveDlg::slotIDLineEdit(const QString & text)
{
	QString id = ui.idLineEdit->text();
	QString value = ui.originalLineEdit->text();

	ui.okBtn->setEnabled (!id.isEmpty() && !value.isEmpty());
}
//----------------------------------------------------------------------------
void DeAddRadioactiveDlg::slotValueLineEdit(const QString & text)
{
	QString id = ui.idLineEdit->text();
	QString value = ui.originalLineEdit->text();

	ui.okBtn->setEnabled (!id.isEmpty() && !value.isEmpty());
}
//----------------------------------------------------------------------------