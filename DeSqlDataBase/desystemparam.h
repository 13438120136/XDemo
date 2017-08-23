#ifndef DESYSTEMPARAM_H
#define DESYSTEMPARAM_H

#include <QOBject>
#include <qbytearray.h>
#include "desqldatabase_global.h"

struct SystemParam;
///����ϵͳ������
class DESQLDATABASE_EXPORT DeSystemParam
{
public:
	DeSystemParam();
	~DeSystemParam();

	DeSystemParam(const DeSystemParam &other);
	DeSystemParam &	operator=(const DeSystemParam & other);

	void setByteArray(const QByteArray &byteArray);
	QByteArray byteArray() const;

	///��ֵ���� 1-��̬��ֵ  2-��̬��ֵ
	void setThresholdType(int type);
	///����ѡ�� 1-����  2-Ӣ��
	void setLanguage(int language);
	///����ip��ַ
	void setIp(const QString &ip);
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

	///��ȡ�ֶ�
	int getThresholdType();
	int getLanguage();
	QString getIp();
	int getMeasurementTime();
	int getCheckTime();
	int getcheckFactor();
	int getRadiationCheckFactor();
	float getPersonnelFactor();
	int getAlarmResetTime();
	int getAlarmTime();

	int getAlphaLowAlarmThreshold();
	int getAlphaHighAlarmThreshold();
	int getAlphaAlramCoefficient();
	int getAlphaSeriousAlramCoefficient();
	int getAlphaThreshold();
	int getAlphaSeriousThreshold();	

	int getBetaLowAlarmThreshold();
	int getBetaHighAlarmThreshold();
	int getBetaAlramCoefficient();
	int getBetaSeriousAlramCoefficient();
	int getBetaThreshold();
	int getBetaSeriousThreshold();	

private:
	///������������ֶε�Ĭ��ֵ
	void setDefaultValues(SystemParam *value);

private:
	SystemParam *pSystemParam;
};

#endif // DESYSTEMPARAM_H
