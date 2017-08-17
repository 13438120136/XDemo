#include "delogtable.h"
#include "desqldatabase.h"

///当前对象对应的数据库表名称
const QString tableName = "logTable";

//----------------------------------------------------------------------------
DeLogTable::DeLogTable(DeSqlDataBase *db)
	: DeValueObjectInterface(db)
{
	initTable();
}
//----------------------------------------------------------------------------
DeLogTable::~DeLogTable()
{

}
//----------------------------------------------------------------------------
void DeLogTable::initTable()
{
	QString sql = QString("CREATE TABLE IF NOT EXISTS %1(   \
						  deviceData blog);").arg(tableName);

	execSql(sql);
}
//----------------------------------------------------------------------------
QString DeLogTable::execAddString()
{
	return "";
}
//----------------------------------------------------------------------------
QString DeLogTable::execSelectString()
{
	return QString("select * from %1").arg(tableName);
}
//----------------------------------------------------------------------------
QList<DeValueObjectInterface *> DeLogTable::selectValue(QSqlQuery *sqlQuery)
{
	QList<DeValueObjectInterface *> result;

	while (sqlQuery->next())
	{
	}

	return result;
}
//----------------------------------------------------------------------------