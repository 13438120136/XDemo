#include "devalueobjectinterface.h"
#include "desqldatabase.h"

//----------------------------------------------------------------------------
DeValueObjectInterface::DeValueObjectInterface(DeSqlDataBase *db)
	: m_db(db)
{

}
//----------------------------------------------------------------------------
DeValueObjectInterface::~DeValueObjectInterface()
{

}
//----------------------------------------------------------------------------
bool DeValueObjectInterface::insertDataToDB()
{
	if (m_db == NULL)
		return false;

	QString sql = execAddString();
	return m_db->execSql(sql);
}
//----------------------------------------------------------------------------
QList<DeValueObjectInterface *> DeValueObjectInterface::selectDataFromDB()
{
	QSqlQuery *query = m_db->getSqlQuery();
	if (m_db == NULL || query == NULL)
		return QList<DeValueObjectInterface *>();

	QString sql = execSelectString();
	m_db->execSql(sql);

	return selectValue(query);
}
//----------------------------------------------------------------------------
bool DeValueObjectInterface::execSql(const QString &sql)
{
	if (m_db == NULL)
		return false;

	return m_db->execSql(sql);
}
//----------------------------------------------------------------------------
DeSqlDataBase *DeValueObjectInterface::currSqlDataBase()
{
	return m_db;
}
//----------------------------------------------------------------------------