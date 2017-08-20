#include "desystemparam.h"
#include <stdio.h>
#include <stdlib.h>
#include <QStringList>

//----------------------------------------------------------------------------
struct systemAlarm
{
	/*低本底报警阀值*/
	int lowAlarmThreshold;

	/*高本底报警阀值*/
	int highAlarmThreshold;

	/*报警系数*/
	int alramCoefficient;

	/*严重报警系数*/
	int seriousAlramCoefficient;

	/*报警阀值*/
	int threshold;

	/*严重报警阀值*/
	int seriousThreshold;
};
//----------------------------------------------------------------------------
///系统参数结构体
struct SystemParam
{
	/*
	 * 阀值类型 1-静态阀值  2-动态阀值
	 */
	int thresholdType;

	/*
	 * 语言选择 1-中文  2-英文
	 */
	int language;

	/*
	 * ip地址
	 */
	quint8 ip[4];

	/*alpha 报警参数*/
	systemAlarm alpha;

	/*Beta 报警参数*/
	systemAlarm beta;

	/*测量时间 默认值为5*/
	int measurementTime;

	/*强制本底检测时间 默认为5*/
	int checkTime;

	/*本底检测平滑因子 默认值为10*/
	int checkFactor;

	/*辐射检测平滑因子 默认为3*/
	int radiationCheckFactor;

	/*人员补偿因子 默认为0.01*/
	float personnelFactor;

	/*仪器报警恢复时间 默认为10s 最大不超过180s*/
	int alarmResetTime;

	/*报警持续时间*/
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