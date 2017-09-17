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
class DeSystemConfigWidget : public QDialog
{
	Q_OBJECT

public:
	DeSystemConfigWidget(bool isMaintain = true, QWidget *parent = 0);
	~DeSystemConfigWidget();

	///执行校验和保存
	bool execValidAndSave(const QString &str);

	///设置IP地址 格式为127.0.0.1
	void setIpAddress(const QString &ip);
	///设置语言
	void setLanguage();
	///阀值类型 1-静态阀值  2-动态阀值
	void setThresholdType(int type);
	///测量时间 默认值为5
	void setMeasurementTime(int time);
	//强制本底检测时间 默认为5
	void setCheckTime(int time);
	///本底检测平滑因子 默认值为10
	void setcheckFactor(int factor);
	///辐射检测平滑因子 默认为3
	void setRadiationCheckFactor(int factor);
	///人员补偿因子 默认为0.01
	void setPersonnelFactor(float factor);
	///仪器报警恢复时间 默认为10s 最大不超过180s
	void setAlarmResetTime(int alarmTime);
	///报警持续时间
	void setAlarmTime(int alarmTime);

	//设置alpha
	void setAlphaLowAlarmThreshold(int low);
	void setAlphaHighAlarmThreshold(int high);
	void setAlphaAlramCoefficient(int coefficient);
	void setAlphaSeriousAlramCoefficient(int coefficient);
	void setAlphaThreshold(int threshold);
	void setAlphaSeriousThreshold(int threshold);	

	///设置Beta
	void setBetaLowAlarmThreshold(int low);
	void setBetaHighAlarmThreshold(int high);
	void setBetaAlramCoefficient(int coefficient);
	void setBetaSeriousAlramCoefficient(int coefficient);
	void setBetaThreshold(int threshold);
	void setBetaSeriousThreshold(int threshold);
	

public Q_SLOTS:
	void propertyEditSlot(QWidget *);
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
	void on_datetimeBtn_clicked();
	void slotDateClicked(const QDate & date);

private:
	///初始化编辑
	void initEdit();
	///更新数据库表格中的数据
	void updateDataBase();
	///读取数据库数据并更新界面
	void readDataFromDB();

private:
	Ui::DeSystemConfigWidget ui;
	DeSystemParam m_systemParamData;
	int m_execIndex;
	bool m_isMaintain;  ///当前是否为维护模式 true-维护

	////////////////////////////////////
	DeButtonIPDelegate m_textDelegate;
	DeButtonIntDelegate m_intDelegate;
	DeButtonDoubleDelegate m_doubleDelegate;
};

#endif // DESYSTEMCONFIGWIDGET_H
