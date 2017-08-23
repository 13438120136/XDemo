#include "dedevicetable.h"
#include "desqldatabase.h"
#include <qvariant.h>

///当前对象对应的数据库表名称
const QString tableName = "deviceSettingTable";

//----------------------------------------------------------------------------
DeDeviceTable::DeDeviceTable(DeSqlDataBase *db)
	: DeValueObjectInterface(db)
{
	initTable();
	///如果表格为空 就放入默认值
	if (isEmptyInTable())
		insertDataToDB(DeSystemParam());
}
//----------------------------------------------------------------------------
DeDeviceTable::~DeDeviceTable()
{

}
//----------------------------------------------------------------------------
void DeDeviceTable::initTable()
{
	QString sql = QString("CREATE TABLE IF NOT EXISTS %1(   \
						  deviceData blob);").arg(tableName);

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
	Q_UNUSED(sqlQuery)

	QList<DeValueObjectInterface *> result;
	return result;
}
//----------------------------------------------------------------------------
bool DeDeviceTable::insertDataToDB(DeSystemParam &data)
{
	DeSqlDataBase *db = currSqlDataBase();
	QSqlQuery sqlQuery(db->dataBase());
	QString sql = QString("insert into %1 values (?)").arg(tableName);
	sqlQuery.prepare(sql);
	sqlQuery.bindValue(0, data.byteArray());
	return sqlQuery.exec();
}
//----------------------------------------------------------------------------
bool DeDeviceTable::updateDataToDB(DeSystemParam &data)
{
	DeSqlDataBase *db = currSqlDataBase();
	QSqlQuery sqlQuery(db->dataBase());
	QString sql = QString("update %1 set deviceData= (?)").arg(tableName);
	sqlQuery.prepare(sql);
	sqlQuery.bindValue(0, data.byteArray());
	return sqlQuery.exec();
}
//----------------------------------------------------------------------------
DeSystemParam DeDeviceTable::selectDB()
{
	DeSqlDataBase *db = currSqlDataBase();
	QSqlQuery sqlQuery(db->dataBase());
	QString sql = QString("select * from %1").arg(tableName);
	sqlQuery.exec(sql);

	sqlQuery.next();

	DeSystemParam param;
	param.setByteArray(sqlQuery.value(0).toByteArray());
	return param;
}
//----------------------------------------------------------------------------
bool DeDeviceTable::isEmptyInTable()
{
	DeSqlDataBase *db = currSqlDataBase();
	QSqlQuery sqlQuery(db->dataBase());
	QString sql = QString("select count(*) from %1").arg(tableName);
	sqlQuery.exec(sql);

	sqlQuery.next();

	int resultCount = sqlQuery.value(0).toInt();
	return !(resultCount >= 1);
}
//----------------------------------------------------------------------------