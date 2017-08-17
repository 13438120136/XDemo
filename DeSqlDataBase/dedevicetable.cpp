#include "dedevicetable.h"
#include "desqldatabase.h"

///当前对象对应的数据库表名称
const QString tableName = "deviceSettingTable";

//----------------------------------------------------------------------------
DeDeviceTable::DeDeviceTable(DeSqlDataBase *db)
	: DeValueObjectInterface(db)
{
	initTable();
}
//----------------------------------------------------------------------------
DeDeviceTable::~DeDeviceTable()
{

}
//----------------------------------------------------------------------------
void DeDeviceTable::initTable()
{
	QString sql = QString("CREATE TABLE IF NOT EXISTS %1(   \
						  deviceData blog);").arg(tableName);

	execSql(sql);
}
//----------------------------------------------------------------------------
QString DeDeviceTable::execAddString()
{
	return "";
}
//----------------------------------------------------------------------------
QString DeDeviceTable::execSelectString()
{
	return QString("select * from %1").arg(tableName);
}
//----------------------------------------------------------------------------
QList<DeValueObjectInterface *> DeDeviceTable::selectValue(QSqlQuery *sqlQuery)
{
	QList<DeValueObjectInterface *> result;

	while (sqlQuery->next())
	{
	}

	return result;
}
//----------------------------------------------------------------------------
bool DeDeviceTable::insertDataToDB()
{
	DeSqlDataBase *db = currSqlDataBase();
	QSqlQuery sqlQuery(db->dataBase());
	QString sql = QString("insert into %1 values (?)").arg(tableName);
	sqlQuery.prepare(sql);
	return sqlQuery.exec();
}
//----------------------------------------------------------------------------