#include "demangewidget.h"
#include "deadduserdlg.h"
#include "demodifyuserdlg.h"
#include <qmessagebox.h>
#include "deuserlistmodel.h"
#include "deradioactivitymodel.h"
#include <demo.h>
#include "demessagebox.h"
#include "deaddradioactivedlg.h"
#include "demenuwidget.h"
#include <QTabBar>

Q_DECLARE_METATYPE(Demo *)
//----------------------------------------------------------------------------
DeManageWidget::DeManageWidget(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	ui.tabWidget->findChildren<QTabBar*>().at(0)->hide();
	this->setWindowFlags(Qt::ToolTip);
	connect(ui.addUserBtn, SIGNAL(clicked()), this, SLOT(addUserSlot()));
	connect(ui.delUserBtn, SIGNAL(clicked()), this, SLOT(delUserSlot()));	
	connect(ui.changeUserBtn, SIGNAL(clicked()), this, SLOT(modifySlot()));
	connect(ui.addRadioactivityBtn, SIGNAL(clicked()), this, SLOT(addRadioactivitySlot()));

	///数据库对象
	Demo *demo = qApp->property("_mainWin").value<Demo *>();
	DeSqlDataBase *dataBase = demo->dataBase();
	DeUserTable table(dataBase);

	///用户管理
	QList<DeValueObjectInterface *> usrData = table.selectDataFromDB();
	m_userModel = new DeUserListModel(this);
	QList<DeUserTable> tmpUserData; 
	for (int i = 0; i < usrData.count(); i++)
		tmpUserData.append(*(DeUserTable *)usrData[i]);
	m_userModel->setData(tmpUserData);
	qDeleteAll(usrData);

	ui.widget->tableView()->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui.widget->tableView()->setSelectionMode(QAbstractItemView::SingleSelection);
	ui.widget->setModel(m_userModel);

	///放射源管理
	m_activeityModel= new DeRadioactivityModel(this);
	DeRadioactiveSourceTable radioactiveSourceTable(dataBase);
	QList<DeValueObjectInterface *> radioactiveSourceData = radioactiveSourceTable.selectDataFromDB();
	QList<DeRadioactiveSourceTable> tmpRadioactiveSourceData;
	for (int i = 0; i < radioactiveSourceData.count(); i++)
		tmpRadioactiveSourceData.append(*(DeRadioactiveSourceTable *)radioactiveSourceData[i]);
	m_activeityModel->setData(tmpRadioactiveSourceData);
	qDeleteAll(radioactiveSourceData);

	ui.widget_2->tableView()->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui.widget_2->tableView()->setSelectionMode(QAbstractItemView::SingleSelection);
	ui.widget_2->setModel(m_activeityModel);
}
//----------------------------------------------------------------------------
DeManageWidget::~DeManageWidget()
{

}
//----------------------------------------------------------------------------
void DeManageWidget::addUserSlot()
{
	Demo *demo = qApp->property("_mainWin").value<Demo *>();
	DeAddUserDlg *dlg = new DeAddUserDlg(this);
	connect(dlg, SIGNAL(signalAddUser(DeUserTable)), this, SLOT(slotAddUser(DeUserTable)));
	demo->slotSetWidget(dlg);
}
//----------------------------------------------------------------------------
void DeManageWidget::modifySlot()
{
	int nRow = selectCurrentRow();
	if (nRow == -1)
	{
		DeMessageBox msgBox(this);
		msgBox.setText("Empty");
		msgBox.setStandardButtons(QMessageBox::Ok);
		msgBox.exec();
		return ;
	}

	DeUserTable userTable = m_userModel->data()[nRow];
	DeModifyUserDlg *dlg = new DeModifyUserDlg(this);
	connect(dlg, SIGNAL(signalUpdateUser(DeUserTable)), this, SLOT(slotUpdateUser(DeUserTable)));
	dlg->setData(userTable);

	Demo *demo = qApp->property("_mainWin").value<Demo *>();
	demo->slotSetWidget(dlg);
}
//----------------------------------------------------------------------------
void DeManageWidget::delUserSlot()
{
	int nRow = selectCurrentRow();
	if (nRow == -1)
	{
		DeMessageBox msgBox(this);
		msgBox.setText("Empty");
		msgBox.setStandardButtons(QMessageBox::Ok);
		msgBox.exec();
		return ;
	}
	
	QString str = m_userModel->data()[nRow].getUerName();
	DeMessageBox msgBox(this);
	msgBox.setText(str);
	msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
	if (msgBox.exec() == QMessageBox::Yes)
	{
		///系统用户不能删除
		if (str == "admin")
			return ;

		///更新数据库
		Demo *demo = qApp->property("_mainWin").value<Demo *>();
		DeSqlDataBase *dataBase = demo->dataBase();
		DeUserTable table(dataBase);
		table.delUser(str);

		///更新界面
		m_userModel->data().removeAt(nRow);
		ui.widget->setModel(m_userModel);
	}
}
//----------------------------------------------------------------------------
void DeManageWidget::slotAddUser(DeUserTable data)
{
	m_userModel->data().append(data);
	ui.widget->setModel(m_userModel);
}
//----------------------------------------------------------------------------
void DeManageWidget::slotUpdateUser(DeUserTable data)
{
	///更新数据库

	///更新界面
	int nRow = selectCurrentRow();
	m_userModel->data()[nRow] = data;
	ui.widget->setModel(m_userModel);
}
//----------------------------------------------------------------------------
int DeManageWidget::selectCurrentRow()
{
	QItemSelectionModel *itemSelectionModel = ui.widget->tableView()->selectionModel();
	QModelIndexList indexList = itemSelectionModel->selectedIndexes();

	if (indexList.isEmpty())
		return -1;

	int nRow = indexList.first().row();
	return nRow;	
}
//---------------------------------------------------------------------------
void DeManageWidget::addRadioactivitySlot()
{
	DeAddRadioactiveDlg *dlg = new DeAddRadioactiveDlg;
	connect(dlg, SIGNAL(signalAddRadioactiveData(DeRadioactiveSourceTable)), this, SLOT(slotAddRadioactiveData(DeRadioactiveSourceTable)));
	Demo *demo = qApp->property("_mainWin").value<Demo *>();
	demo->slotSetWidget(dlg);
}
//---------------------------------------------------------------------------
void DeManageWidget::slotAddRadioactiveData(DeRadioactiveSourceTable tableData)
{
	m_activeityModel->data().append(tableData);
	ui.widget_2->setModel(m_activeityModel);
}
//---------------------------------------------------------------------------
void DeManageWidget::on_userBtn_clicked()
{
	ui.tabWidget->setCurrentIndex(0);
}
//---------------------------------------------------------------------------
void DeManageWidget::on_radioBtn_clicked()
{
	ui.tabWidget->setCurrentIndex(1);
}
//---------------------------------------------------------------------------
void DeManageWidget::on_funcBtn_clicked()
{
	Demo *demo = qApp->property("_mainWin").value<Demo *>();	
	DeMenuWidget widget;
	widget.move(demo->pos());
	widget.resize(demo->width(), demo->height());
	widget.setWindowOpacity(0.9);
	widget.exec();
}
//---------------------------------------------------------------------------
void DeManageWidget::on_logoutBtn_clicked()
{
	Demo *demo = qApp->property("_mainWin").value<Demo *>();
	demo->slotBackMainWidget();
}
//----------------------------------------------------------------------------