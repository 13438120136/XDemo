#ifndef DESYSTEMPARAM_H
#define DESYSTEMPARAM_H

#include <QOBject>
#include <qbytearray.h>
#include "desqldatabase_global.h"

struct SystemParam;
///定义系统参数类
class DESQLDATABASE_EXPORT DeSystemParam
{
public:
	DeSystemParam();
	~DeSystemParam();

	DeSystemParam(const DeSystemParam &other);
	DeSystemParam &	operator=(const DeSystemParam & other);

	void setByteArray(const QByteArray &byteArray);
	QByteArray byteArray() const;

	///阀值类型 1-静态阀值  2-动态阀值
	void setThresholdType(int type);
	///语言选择 1-中文  2-英文
	void setLanguage(int language);
	///设置ip地址
	void setIp(const QString &ip);
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

	///获取字段
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
	///设置所有相关字段的默认值
	void setDefaultValues(SystemParam *value);

private:
	SystemParam *pSystemParam;
};

#endif // DESYSTEMPARAM_H
