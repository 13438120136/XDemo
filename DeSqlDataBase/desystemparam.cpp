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