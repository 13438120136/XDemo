#ifndef DESYSTEMCONFIGWIDGET_H
#define DESYSTEMCONFIGWIDGET_H

#include <QDialog>
#include "ui_desystemconfigwidget.h"
#include "desystemparam.h"
#include "deinputdelegate.h"

/*
 * ϵͳ�����Ի���
 * ����ϵͳ���������ü��������ݿ��
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
	///̽��������
	void on_detectorBtn_clicked();
	void on_runStateBtn_clicked();
	void on_testParamBtn_clicked();
	void on_alphaBtn_clicked();
	void on_betaBtn_clicked();
	void on_funcBtn_clicked();
	void on_logoutBtn_clicked();
	///����ѡ��
	void slotDatetimeBtn();
	void slotDateWeekBtn();
	void slotDateDayBtn();
	void slotDateClicked(const QDate & date);
	///��̬�;�̬��ֵѡ��
	void slotDynamicValue();
	void slotStaticValue();

	///���ݽ���������ݿ��е�ֵ
	void slotUpdateDatabase(QObject *);

	///ͨ��ѡ��
	void slotChannelType();
	///����ͨ��ѡ��
	void slotTestChannel();
	///��Ⱦ������ʾ
	void slotShowWuranData(const QModelIndex &);

private:
	///��ʼ���༭
	void initEdit();
	///�������ݿ����е�����
	void updateDataBase();
	///��ȡ���ݿ����ݲ����½���
	void readDataFromDB();
	///��ʼ��������ʾ
	void initUI();
	///����ʱ�䷶Χ��ʾ��Ⱦ��Ϣ
	void showWuranInfor(qint64, qint64);

private:
	Ui::DeSystemConfigWidget ui;
	DeSystemParam m_systemParamData;
	int m_execIndex;
	bool m_isMaintain;  ///��ǰ�Ƿ�Ϊά��ģʽ true-ά��

	////////////////////////////////////
	DeButtonIPDelegate m_textDelegate;
	DeButtonIntDelegate m_intDelegate;
	DeButtonDoubleDelegate m_doubleDelegate;
	DeIntDelegate m_tIntDelegate;

	DeAlermEventModel *eventModel;
	DeTestDataModel *testDataModel;
};

#endif // DESYSTEMCONFIGWIDGET_H
