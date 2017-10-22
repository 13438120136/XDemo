#ifndef DETECTORTABLE_H
#define DETECTORTABLE_H

#include <QString>
#include "devalueobjectinterface.h"
#include "desqldatabase_global.h"

///探测器参数数据库对应表记录
class DESQLDATABASE_EXPORT DetectorTable : public DeValueObjectInterface
{
public:
	DetectorTable(DeSqlDataBase *db);
	~DetectorTable();

	///初始化表结构
	void initTable();

	///设置通道号
	void setChannelNumber(int number);
	///设置计数时间
	void setCountingTime(int time);
	///设置高压误差
	void setDeviation(int deviation);
	///设置甑别器阔值1
	void setTheshold1(int value);
	///设置甑别器阔值2
	void setTheshold2(int value);
	///设置甑别器阔值3
	void setTheshold3(int value);

	int getChannelNumber();
	int getCountingTime();
	int getDeviation();
	int getTheshold1();
	int getTheshold2();
	int getTheshold3();

	///通过通道获取对应探测器参数
	QList<DeValueObjectInterface *> selectDataFromChannelNumber(int number);

protected:
	QString execAddString();
	QString execSelectString();
	QList<DeValueObjectInterface *> selectValue(QSqlQuery *sqlQuery);

private:
	int m_index;
	int m_time;
	int m_deviation;
	int m_theshold1;
	int m_theshold2;
	int m_theshold3;
};

#endif // DETECTORTABLE_H
