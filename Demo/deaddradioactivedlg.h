#ifndef DEADDRADIOACTIVEDLG_H
#define DEADDRADIOACTIVEDLG_H

#include <QDialog>
#include "ui_deaddradioactivedlg.h"
#include "deradioactivesourcetable.h"

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
	void slotIDLineEdit(const QString & text);
	void slotValueLineEdit(const QString & text);

protected:
	virtual bool eventFilter(QObject *obj, QEvent *event);

private:
	Ui::DeAddRadioactiveDlg ui;
};

#endif // DEADDRADIOACTIVEDLG_H
