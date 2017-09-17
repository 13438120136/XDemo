#ifndef DEADDUSERDLG_H
#define DEADDUSERDLG_H

#include <QDialog>
#include "ui_deadduserdlg.h"
#include "deusertable.h"
#include "deinputdelegate.h"

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

private:
	Ui::DeAddUserDlg ui;
	DeInputDelegate m_inputTextDelegate;
	DePasswordDelegate m_passwdDelegate;
};

#endif // DEADDUSERDLG_H
