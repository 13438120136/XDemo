#ifndef DEADDUSERDLG_H
#define DEADDUSERDLG_H

#include <QDialog>
#include "ui_deadduserdlg.h"
#include "deusertable.h"

class DeAddUserDlg : public QDialog
{
	Q_OBJECT

public:
	DeAddUserDlg(QWidget *parent = 0);
	~DeAddUserDlg();

	Q_SIGNAL void signalAddUser(DeUserTable userTable);

public Q_SLOTS:
	void on_okBtn_clicked();
	void on_cancelBtn_clicked();
	void slotUserLineEdit(const QString & text);
	void slotUserPasswdEdit(const QString & text);

protected:
	virtual bool eventFilter(QObject *obj, QEvent *event);

private:
	Ui::DeAddUserDlg ui;
};

#endif // DEADDUSERDLG_H
