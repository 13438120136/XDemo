#include "desystemparam.h"
#include <stdio.h>
#include <stdlib.h>
#include <QStringList>

//----------------------------------------------------------------------------
struct systemAlarm
{
	/*�ͱ��ױ�����ֵ*/
	int lowAlarmThreshold;

	/*�߱��ױ�����ֵ*/
	int highAlarmThreshold;

	/*����ϵ��*/
	int alramCoefficient;

	/*���ر���ϵ��*/
	int seriousAlramCoefficient;

	/*������ֵ*/
	int threshold;

	/*���ر�����ֵ*/
	int seriousThreshold;
};
//----------------------------------------------------------------------------
///ϵͳ�����ṹ��
struct SystemParam
{
	/*
	 * ��ֵ���� 1-��̬��ֵ  2-��̬��ֵ
	 */
	int thresholdType;

	/*
	 * ����ѡ�� 1-����  2-Ӣ��
	 */
	int language;

	/*
	 * ip��ַ
	 */
	quint8 ip[4];

	/*alpha ��������*/
	systemAlarm alpha;

	/*Beta ��������*/
	systemAlarm beta;

	/*����ʱ�� Ĭ��ֵΪ5*/
	int measurementTime;

	/*ǿ�Ʊ��׼��ʱ�� Ĭ��Ϊ5*/
	int checkTime;

	/*���׼��ƽ������ Ĭ��ֵΪ10*/
	int checkFactor;

	/*������ƽ������ Ĭ��Ϊ3*/
	int radiationCheckFactor;

	/*��Ա�������� Ĭ��Ϊ0.01*/
	float personnelFactor;

	/*���������ָ�ʱ�� Ĭ��Ϊ10s ��󲻳���180s*/
	int alarmResetTime;

	/*��������ʱ��*/
	int alarmTime;
};
//----------------------------------------------------------------------------
DeSystemParam::DeSystemParam()
{
	pSystemParam = new SystemParam;
	memset(pSystemParam, 0, sizeof(SystemParam));
	setDefaultValues(pSystemParam);
}
//----------------------------------------------------------------------------
DeSystemParam::DeSystemParam(const DeSystemParam &other)
{
	pSystemParam = new SystemParam;
	memset(pSystemParam, 0, sizeof(SystemParam));
	setDefaultValues(pSystemParam);	
	*this  = other;
}
//----------------------------------------------------------------------------
DeSystemParam::~DeSystemParam()
{
	if (pSystemParam != NULL)
	{
		delete pSystemParam;
		pSystemParam = NULL;
	}
}
//----------------------------------------------------------------------------
DeSystemParam &DeSystemParam::operator=(const DeSystemParam & other)
{
	if (this == &other)
		return *this;

	memcpy(this->pSystemParam, other.pSystemParam, sizeof(SystemParam));
	return *this;
}
//----------------------------------------------------------------------------
void DeSystemParam::setDefaultValues(SystemParam *value)
{
	value->thresholdType = 1;
	value->language = 1;
	value->measurementTime = 5;
	value->checkTime = 5;
	value->checkFactor = 10;
	value->radiationCheckFactor = 3;
	value->personnelFactor = 0.01f;
	value->alarmResetTime = 10;
	value->alarmTime = 3;

	value->alpha.lowAlarmThreshold = 1;
	value->alpha.highAlarmThreshold = 10;
	value->alpha.alramCoefficient = 2;
	value->alpha.seriousAlramCoefficient = 8;
	value->alpha.threshold = 3;
	value->alpha.seriousThreshold = 7;

	value->beta.lowAlarmThreshold = 2;
	value->beta.highAlarmThreshold = 10;
	value->beta.alramCoefficient = 2;
	value->beta.seriousAlramCoefficient = 8;
	value->beta.threshold = 3;
	value->beta.seriousThreshold = 7;
}
//----------------------------------------------------------------------------
QByteArray DeSystemParam::byteArray() const
{
	QByteArray byteArray;
	byteArray.append((char *)pSystemParam, sizeof(SystemParam));

	return byteArray;
}
//----------------------------------------------------------------------------
void DeSystemParam::setByteArray(const QByteArray &byteArray)
{
	if (sizeof(SystemParam) != byteArray.size())
		return ;

	char *pData = (char *)byteArray.data();
	memcpy(pSystemParam, pData, sizeof(SystemParam));
}
//----------------------------------------------------------------------------
void DeSystemParam::setThresholdType(int type)
{
	pSystemParam->thresholdType = type;
}
//----------------------------------------------------------------------------
void DeSystemParam::setLanguage(int language)
{
	pSystemParam->language = language;
}
//----------------------------------------------------------------------------
void DeSystemParam::setIp(const QString &ip)
{
	QStringList ipSplit = ip.split(".");
	int nCount = ipSplit.size();
	if (nCount != 4)
		return ;

	for (int i = 0; i < nCount; i++)
		pSystemParam->ip[i] = ipSplit[i].toInt();
}
//----------------------------------------------------------------------------
void DeSystemParam::setMeasurementTime(int time)
{
	pSystemParam->measurementTime = time;
}
//----------------------------------------------------------------------------
void DeSystemParam::setCheckTime(int time)
{
	pSystemParam->checkTime = time;
}
//----------------------------------------------------------------------------
void DeSystemParam::setcheckFactor(int factor)
{
	pSystemParam->checkFactor = factor;
}
//----------------------------------------------------------------------------
void DeSystemParam::setRadiationCheckFactor(int factor)
{
	pSystemParam->radiationCheckFactor = factor;
}
//----------------------------------------------------------------------------
void DeSystemParam::setPersonnelFactor(float factor)
{
	pSystemParam->personnelFactor = factor;
}
//----------------------------------------------------------------------------
void DeSystemParam::setAlarmResetTime(int alarmTime)
{
	pSystemParam->alarmResetTime = alarmTime;
}
//----------------------------------------------------------------------------
void DeSystemParam::setAlarmTime(int alarmTime)
{
	pSystemParam->alarmTime = alarmTime;
}
//----------------------------------------------------------------------------
void DeSystemParam::setAlphaLowAlarmThreshold(int low)
{
	pSystemParam->alpha.lowAlarmThreshold = low;
}
//----------------------------------------------------------------------------
void DeSystemParam::setAlphaHighAlarmThreshold(int high)
{
	pSystemParam->alpha.highAlarmThreshold = high;
}
//----------------------------------------------------------------------------
void DeSystemParam::setAlphaAlramCoefficient(int coefficient)
{
	pSystemParam->alpha.alramCoefficient = coefficient;
}
//----------------------------------------------------------------------------
void DeSystemParam::setAlphaSeriousAlramCoefficient(int coefficient)
{
	pSystemParam->alpha.seriousAlramCoefficient = coefficient;
}
//----------------------------------------------------------------------------
void DeSystemParam::setAlphaThreshold(int threshold)
{
	pSystemParam->alpha.threshold = threshold;
}
//----------------------------------------------------------------------------
void DeSystemParam::setAlphaSeriousThreshold(int threshold)
{
	pSystemParam->alpha.seriousThreshold = threshold;
}
//----------------------------------------------------------------------------
void DeSystemParam::setBetaLowAlarmThreshold(int low)
{
	pSystemParam->beta.lowAlarmThreshold = low;
}
//----------------------------------------------------------------------------
void DeSystemParam::setBetaHighAlarmThreshold(int high)
{
	pSystemParam->beta.highAlarmThreshold = high;
}
//----------------------------------------------------------------------------
void DeSystemParam::setBetaAlramCoefficient(int coefficient)	
{
	pSystemParam->beta.alramCoefficient = coefficient;
}
//----------------------------------------------------------------------------
void DeSystemParam::setBetaSeriousAlramCoefficient(int coefficient)
{
	pSystemParam->beta.seriousAlramCoefficient = coefficient;
}
//----------------------------------------------------------------------------
void DeSystemParam::setBetaThreshold(int threshold)
{
	pSystemParam->beta.threshold = threshold;
}
//----------------------------------------------------------------------------
void DeSystemParam::setBetaSeriousThreshold(int threshold)
{
	pSystemParam->beta.seriousThreshold = threshold;
}
//----------------------------------------------------------------------------
int DeSystemParam::getThresholdType()
{
	return pSystemParam->thresholdType;
}
//----------------------------------------------------------------------------
int DeSystemParam::getLanguage()
{
	return pSystemParam->language;
}
//----------------------------------------------------------------------------
QString DeSystemParam::getIp()
{
	QString ip = QString("%1.%2.%3.%4")
		.arg(pSystemParam->ip[0])
		.arg(pSystemParam->ip[1])
		.arg(pSystemParam->ip[2])
		.arg(pSystemParam->ip[3]);
	return ip;
}
//----------------------------------------------------------------------------
int DeSystemParam::getMeasurementTime()
{
	return pSystemParam->measurementTime;
}
//----------------------------------------------------------------------------
int DeSystemParam::getCheckTime()
{
	return pSystemParam->checkTime;
}
//----------------------------------------------------------------------------
int DeSystemParam::getcheckFactor()
{
	return pSystemParam->checkFactor;
}
//----------------------------------------------------------------------------
int DeSystemParam::getRadiationCheckFactor()
{
	return pSystemParam->radiationCheckFactor;
}
//----------------------------------------------------------------------------
float DeSystemParam::getPersonnelFactor()
{
	return pSystemParam->personnelFactor;
}
//----------------------------------------------------------------------------
int DeSystemParam::getAlarmResetTime()
{
	return pSystemParam->alarmResetTime;
}
//----------------------------------------------------------------------------
int DeSystemParam::getAlarmTime()
{
	return pSystemParam->alarmTime;
}
//----------------------------------------------------------------------------
int DeSystemParam::getAlphaLowAlarmThreshold()
{
	return pSystemParam->alpha.lowAlarmThreshold;
}
//----------------------------------------------------------------------------
int DeSystemParam::getAlphaHighAlarmThreshold()
{
	return pSystemParam->alpha.highAlarmThreshold;
}
//----------------------------------------------------------------------------
int DeSystemParam::getAlphaAlramCoefficient()
{
	return pSystemParam->alpha.alramCoefficient;
}
//----------------------------------------------------------------------------
int DeSystemParam::getAlphaSeriousAlramCoefficient()
{
	return pSystemParam->alpha.seriousAlramCoefficient;
}
//----------------------------------------------------------------------------
int DeSystemParam::getAlphaThreshold()
{
	return pSystemParam->alpha.threshold;
}
//----------------------------------------------------------------------------
int DeSystemParam::getAlphaSeriousThreshold()
{
	return pSystemParam->alpha.seriousThreshold;
}
//----------------------------------------------------------------------------
int DeSystemParam::getBetaLowAlarmThreshold()	
{
	return pSystemParam->beta.lowAlarmThreshold;
}
//----------------------------------------------------------------------------
int DeSystemParam::getBetaHighAlarmThreshold()	
{
	return pSystemParam->beta.highAlarmThreshold;
}
//----------------------------------------------------------------------------
int DeSystemParam::getBetaAlramCoefficient()
{
	return pSystemParam->beta.alramCoefficient;
}
//----------------------------------------------------------------------------
int DeSystemParam::getBetaSeriousAlramCoefficient()	
{
	return pSystemParam->beta.seriousAlramCoefficient;
}
//----------------------------------------------------------------------------
int DeSystemParam::getBetaThreshold()
{
	return pSystemParam->beta.threshold;
}
//----------------------------------------------------------------------------
int DeSystemParam::getBetaSeriousThreshold()
{
	return pSystemParam->beta.seriousThreshold;
}	
//----------------------------------------------------------------------------
