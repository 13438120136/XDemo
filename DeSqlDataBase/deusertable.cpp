#include "deusertable.h"
#include "desqldatabase.h"
#include <QCryptographicHash>
#include <QVariant>

///当前对象对应的数据库表名称
const QString tableName = "userTable";

//----------------------------------------------------------------------------
DeUserTable::DeUserTable(DeSqlDataBase *db)
	: DeValueObjectInterface(db)
{
	initTable();
}
//----------------------------------------------------------------------------
DeUserTable::~DeUserTable()
{

}
//----------------------------------------------------------------------------
void DeUserTable::initTable()
{
	QString sql = QString("CREATE TABLE IF NOT EXISTS %1(   \
						  name VARCHAR(32), 			    \
						  passwd VARCHAR(64), 			    \
						  permissionName VARCHAR(32), 	    \
						  permission int 				    \
						  );").arg(tableName);

	execSql(sql);
}
//----------------------------------------------------------------------------
bool DeUserTable::delUser(const QString &userName)
{
	QString sql = QString("delete from %1 where name = '%2'").arg(tableName).arg(userName);
	return execSql(sql);
}
//----------------------------------------------------------------------------
QString DeUserTable::execAddString()
{
	QString sql = QString("insert into %1 values('%2', '%3', '%4', %5)")
		.arg(tableName).arg(m_user).arg(md5sum(m_passwd)).arg(m_userClassfy).arg(m_permission);
	return sql;
}
//----------------------------------------------------------------------------
QString DeUserTable::execSelectString()
{
	return QString("select * from %1").arg(tableName);
}
//----------------------------------------------------------------------------
QList<DeValueObjectInterface *> DeUserTable::selectValue(QSqlQuery *sqlQuery)
{
	QList<DeValueObjectInterface *> result;

	while (sqlQuery->next())
	{
		DeUserTable *table = new DeUserTable(this->currSqlDataBase());
		table->m_user = sqlQuery->value(0).toString();
		table->m_userClassfy = sqlQuery->value(2).toString();
		table->m_permission = sqlQuery->value(3).toInt();

		result.append(table);
	}

	return result;
}
//----------------------------------------------------------------------------
bool DeUserTable::isExist()
{
	QString sql = QString("select count(*) from %1 where name = '%2'")
		.arg(tableName).arg(m_user);

	if (!execSql(sql))
		return true;

	QSqlQuery *sqlQuery = this->currSqlDataBase()->getSqlQuery();
	if (sqlQuery->isValid())
		return true;

	if (!sqlQuery->next())
		return true;

	int count = sqlQuery->value(0).toInt();

	return (count > 0);
}
//----------------------------------------------------------------------------
bool DeUserTable::isValid()
{
	QString sql = QString("select passwd from %1 where name = '%2'")
		.arg(tableName).arg(m_user);

	if (!execSql(sql))
		return false;

	QSqlQuery *sqlQuery = this->currSqlDataBase()->getSqlQuery();
	if (sqlQuery->isValid())
		return false;

	if (!sqlQuery->next())
		return false;

	QString passwd = sqlQuery->value(0).toString();

	if (md5sum(m_passwd) != passwd)
		return false;

	return true;
}
//----------------------------------------------------------------------------
QString DeUserTable::md5sum(const QString &passwd)
{
	QCryptographicHash hash(QCryptographicHash::Md5);
	QByteArray byteArray;
	byteArray.append(passwd);
	hash.addData(byteArray);
	byteArray = hash.result().toHex();

	return byteArray.data();
}
//----------------------------------------------------------------------------
void DeUserTable::setUserName(const QString &userName)
{
	this->m_user = userName;
}
//----------------------------------------------------------------------------
void DeUserTable::setUserPasswd(const QString &userPasswd)
{
	this->m_passwd = userPasswd;
}
//----------------------------------------------------------------------------
void DeUserTable::setUserPermissionName(const QString &permissionName)
{
	this->m_userClassfy = permissionName;
}
//----------------------------------------------------------------------------
void DeUserTable::setUserPermission(DeUserTable::UserPermission permission)
{
	this->m_permission = (int)permission;
}
//----------------------------------------------------------------------------
QString DeUserTable::getUerName()
{
	return m_user;
}
//----------------------------------------------------------------------------
QString DeUserTable::getUserPermissionName()
{
	return m_userClassfy;
}
//----------------------------------------------------------------------------
int DeUserTable::getUserPermission()
{
	return this->m_permission;
}
//----------------------------------------------------------------------------