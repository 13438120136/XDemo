#include "detectortable.h"

///当前对象对应的数据库表名称
const QString tableName = "detectorTable";

//----------------------------------------------------------------------------
DetectorTable::DetectorTable(DeSqlDataBase *db)
	: DeValueObjectInterface(db)
{
	m_index = 0;
	m_time = 0;
	m_deviation = 0;
	m_theshold1 = 0;
	m_theshold2 = 0;
	m_theshold3 = 0;
}
//----------------------------------------------------------------------------
DetectorTable::~DetectorTable()
{

}
//----------------------------------------------------------------------------
void DetectorTable::setChannelNumber(int number)
{
	m_index = number;
}
//----------------------------------------------------------------------------
void DetectorTable::setCountingTime(int time)
{
	m_time = time;
}
//----------------------------------------------------------------------------
void DetectorTable::setDeviation(int deviation)
{
	m_deviation = deviation;
}
//----------------------------------------------------------------------------
void DetectorTable::setTheshold1(int value)
{
	m_theshold1 = value;
}
//----------------------------------------------------------------------------
void DetectorTable::setTheshold2(int value)
{
	m_theshold2 = value;
}
//----------------------------------------------------------------------------
void DetectorTable::setTheshold3(int value)
{
	m_theshold3 = value;
}
//----------------------------------------------------------------------------
int DetectorTable::getChannelNumber()
{
	return m_index;
}
//----------------------------------------------------------------------------
int DetectorTable::getCountingTime()
{
	return m_time;
}
//----------------------------------------------------------------------------
int DetectorTable::getDeviation()
{
	return m_deviation;
}
//----------------------------------------------------------------------------
int DetectorTable::getTheshold1()
{
	return m_theshold1;
}
//----------------------------------------------------------------------------
int DetectorTable::getTheshold2()
{
	return m_theshold2;
}
//----------------------------------------------------------------------------
int DetectorTable::getTheshold3()
{
	return m_theshold3;
}
//----------------------------------------------------------------------------
QList<DeValueObjectInterface *> DetectorTable::selectDataFromChannelNumber(int number)
{
	QList<DeValueObjectInterface *> result;
	return result;
}
//----------------------------------------------------------------------------