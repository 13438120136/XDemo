#ifndef DESYSTEMCONFIGWIDGET_H
#define DESYSTEMCONFIGWIDGET_H

#include <QDialog>
#include "ui_desystemconfigwidget.h"
#include "desystemparam.h"
#include "deinputdelegate.h"

/*
 * 系统参数对话框
 * 包含系统参数的设置及保存数据库表
 */
class DeAlermEventModel;
class DeTestDataModel;
class DeSystemConfigWidget : public QDialog
{
	Q_OBJECT

public:
	DeSystemConfigWidget(bool isMaintain = true, QWidget *parent = 0);
	~DeSystemConfigWidget();

public Q_SLOTS:
	void on_deviceBtn_clicked();
	void on_testBtn_clicked();
	///探测器参数
	void on_detectorBtn_clicked();
	void on_runStateBtn_clicked();
	void on_testParamBtn_clicked();
	void on_alphaBtn_clicked();
	void on_betaBtn_clicked();
	void on_funcBtn_clicked();
	void on_logoutBtn_clicked();
	///日期选择
	void slotDatetimeBtn();
	void slotDateWeekBtn();
	void slotDateDayBtn();
	void slotDateClicked(const QDate & date);
	///动态和静态阔值选择
	void slotDynamicValue();
	void slotStaticValue();

	///根据界面更新数据库中的值
	void slotUpdateDatabase(QObject *);

	///通道选择
	void slotChannelType();
	///测量通道选择
	void slotTestChannel();
	///污染数据显示
	void slotShowWuranData(const QModelIndex &);

private:
	///初始化编辑
	void initEdit();
	///更新数据库表格中的数据
	void updateDataBase();
	///读取数据库数据并更新界面
	void readDataFromDB();
	///初始化界面显示
	void initUI();
	///根据时间范围显示污染信息
	void showWuranInfor(qint64, qint64);

private:
	Ui::DeSystemConfigWidget ui;
	DeSystemParam m_systemParamData;
	int m_execIndex;
	bool m_isMaintain;  ///当前是否为维护模式 true-维护

	////////////////////////////////////
	DeButtonIPDelegate m_textDelegate;
	DeButtonIntDelegate m_intDelegate;
	DeButtonDoubleDelegate m_doubleDelegate;
	DeIntDelegate m_tIntDelegate;

	DeAlermEventModel *eventModel;
	DeTestDataModel *testDataModel;
};

#endif // DESYSTEMCONFIGWIDGET_H
