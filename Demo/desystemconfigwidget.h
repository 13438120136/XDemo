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
class DeSystemConfigWidget : public QDialog
{
	Q_OBJECT

public:
	DeSystemConfigWidget(bool isMaintain = true, QWidget *parent = 0);
	~DeSystemConfigWidget();

	///ִ��У��ͱ���
	bool execValidAndSave(const QString &str);

	///����IP��ַ ��ʽΪ127.0.0.1
	void setIpAddress(const QString &ip);
	///��������
	void setLanguage();
	///��ֵ���� 1-��̬��ֵ  2-��̬��ֵ
	void setThresholdType(int type);
	///����ʱ�� Ĭ��ֵΪ5
	void setMeasurementTime(int time);
	//ǿ�Ʊ��׼��ʱ�� Ĭ��Ϊ5
	void setCheckTime(int time);
	///���׼��ƽ������ Ĭ��ֵΪ10
	void setcheckFactor(int factor);
	///������ƽ������ Ĭ��Ϊ3
	void setRadiationCheckFactor(int factor);
	///��Ա�������� Ĭ��Ϊ0.01
	void setPersonnelFactor(float factor);
	///���������ָ�ʱ�� Ĭ��Ϊ10s ��󲻳���180s
	void setAlarmResetTime(int alarmTime);
	///��������ʱ��
	void setAlarmTime(int alarmTime);

	//����alpha
	void setAlphaLowAlarmThreshold(int low);
	void setAlphaHighAlarmThreshold(int high);
	void setAlphaAlramCoefficient(int coefficient);
	void setAlphaSeriousAlramCoefficient(int coefficient);
	void setAlphaThreshold(int threshold);
	void setAlphaSeriousThreshold(int threshold);	

	///����Beta
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
	///̽��������
	void on_detectorBtn_clicked();
	void on_runStateBtn_clicked();
	void on_testParamBtn_clicked();
	void on_alphaBtn_clicked();
	void on_betaBtn_clicked();
	void on_funcBtn_clicked();
	void on_logoutBtn_clicked();
	///����ѡ��
	void on_datetimeBtn_clicked();
	void slotDateClicked(const QDate & date);

private:
	///��ʼ���༭
	void initEdit();
	///�������ݿ����е�����
	void updateDataBase();
	///��ȡ���ݿ����ݲ����½���
	void readDataFromDB();

private:
	Ui::DeSystemConfigWidget ui;
	DeSystemParam m_systemParamData;
	int m_execIndex;
	bool m_isMaintain;  ///��ǰ�Ƿ�Ϊά��ģʽ true-ά��

	////////////////////////////////////
	DeButtonIPDelegate m_textDelegate;
	DeButtonIntDelegate m_intDelegate;
	DeButtonDoubleDelegate m_doubleDelegate;
};

#endif // DESYSTEMCONFIGWIDGET_H
