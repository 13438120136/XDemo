#ifndef DEMODIFYUSERDLG_H
#define DEMODIFYUSERDLG_H

#include <QDialog>
#include "ui_demodifyuserdlg.h"
#include <deusertable.h>
#include "deinputdelegate.h"

class DeModifyUserDlg : public QDialog
{
	Q_OBJECT

public:
	DeModifyUserDlg(QWidget *parent = 0);
	~DeModifyUserDlg();

	///设置选中用户数据
	void setData(DeUserTable data);

	Q_SIGNAL void signalUpdateUser(DeUserTable userTable);

public Q_SLOTS:
	void on_okBtn_clicked();
	void on_cancelBtn_clicked();
	void slotUserPasswdEdit(const QString & text);

private:
	Ui::DeModifyUserDlg ui;
	DeInputDelegate m_inputTextDelegate;
	DePasswordDelegate m_passwdDelegate;
};

#endif // DEMODIFYUSERDLG_H
