#include "detectortable.h"
#include "desqldatabase.h"
#include <QVariant>

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

	initTable();
}
//----------------------------------------------------------------------------
DetectorTable::~DetectorTable()
{

}
//----------------------------------------------------------------------------
void DetectorTable::initTable()
{
	QString sql = QString("CREATE TABLE IF NOT EXISTS %1(  			\
						  channel INTEGER, 			    			\
						  time INTEGER,								\
						  deviation int,							\
						  theshold1 int,							\
						  theshold2 int,							\
						  theshold3 int								\
						  );").arg(tableName);

	execSql(sql);
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
	DeSqlDataBase *db = currSqlDataBase();
	QSqlQuery sqlQuery(db->dataBase());

	QString sql = QString("select * from %1 where channel=%2")
		.arg(tableName).arg(number);

	sqlQuery.exec(sql);

	QList<DeValueObjectInterface *> result;
	while (sqlQuery.next())
	{
		DetectorTable *table = new DetectorTable(this->currSqlDataBase());

		table->m_index = sqlQuery.value(0).toInt();
		table->m_time = sqlQuery.value(1).toInt();
		table->m_deviation = sqlQuery.value(2).toInt();
		table->m_theshold1 = sqlQuery.value(3).toInt();
		table->m_theshold2 = sqlQuery.value(4).toInt();
		table->m_theshold3 = sqlQuery.value(5).toInt();
		result.append(table);
	}
	
	return result;
}
//----------------------------------------------------------------------------
QString DetectorTable::execAddString()
{
	QString sql = QString("insert into %1 values(%2, %3, %4, %5, %6)")
		.arg(tableName).arg(m_index).arg(m_time).arg(m_deviation)
		.arg(m_theshold1).arg(m_theshold2).arg(m_theshold3);
	return sql;
}
//----------------------------------------------------------------------------
QString DetectorTable::execSelectString()
{
	return QString();
}
//----------------------------------------------------------------------------
QList<DeValueObjectInterface *> DetectorTable::selectValue(QSqlQuery *sqlQuery)
{
	Q_UNUSED(sqlQuery)

	QList<DeValueObjectInterface *> result;
	return result;
}
//----------------------------------------------------------------------------