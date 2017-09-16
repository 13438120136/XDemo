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
	ui.lineEdit->setText(QDateTime::currentDateTime().toString("yyyy/MM/dd hh:mm:ss"));
	ui.widget_3->addItem(tr("²âÊÔ1"));
	ui.widget_3->addItem(tr("²âÊÔ2"));

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