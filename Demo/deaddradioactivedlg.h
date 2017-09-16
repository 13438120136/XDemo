#ifndef DEADDRADIOACTIVEDLG_H
#define DEADDRADIOACTIVEDLG_H

#include <QDialog>
#include "ui_deaddradioactivedlg.h"
#include "deradioactivesourcetable.h"
#include <QDate>

class DeAddRadioactiveDlg : public QDialog
{
	Q_OBJECT

public:
	DeAddRadioactiveDlg(QWidget *parent = 0);
	~DeAddRadioactiveDlg();

	Q_SIGNAL void signalAddRadioactiveData(DeRadioactiveSourceTable tableData);

public Q_SLOTS:
	void on_okBtn_clicked();
	void on_cancelBtn_clicked();
	void on_dateBtn_clicked();
	void slotIDLineEdit(const QString & text);
	void slotValueLineEdit(const QString & text);
	void slotDateClicked(const QDate & date);

private:
	Ui::DeAddRadioactiveDlg ui;
};

#endif // DEADDRADIOACTIVEDLG_H
