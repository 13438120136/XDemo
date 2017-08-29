#ifndef DEUSERWIDGET_H
#define DEUSERWIDGET_H

#include <QDialog>
#include "ui_demangewidget.h"
#include <deusertable.h>
#include "deradioactivesourcetable.h"

class DeUserListModel;
class DeRadioactivityModel;
class DeManageWidget : public QDialog
{
	Q_OBJECT

public:
	DeManageWidget(QWidget *parent = 0);
	~DeManageWidget();

public Q_SLOTS:
	void addUserSlot();
	void delUserSlot();
	void modifySlot();

	///���½�����ʾ
	void slotAddUser(DeUserTable data);
	void slotUpdateUser(DeUserTable data);

	void addRadioactivitySlot();
	void slotAddRadioactiveData(DeRadioactiveSourceTable tableData);

	///
	void on_userBtn_clicked();
	void on_radioBtn_clicked();

private:
	int selectCurrentRow();

private:
	Ui::DeMangeWidget ui;
	DeUserListModel *m_userModel;				///�û�
	DeRadioactivityModel *m_activeityModel;		///����Դ
};

#endif // DEUSERWIDGET_H
