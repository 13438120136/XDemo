#include "desqldatabase.h"

//----------------------------------------------------------------------------
DeSqlDataBase::DeSqlDataBase()
	: m_sqlQuery(NULL)
{
	m_sqlDataBase = QSqlDatabase::addDatabase("QSQLITE");
	m_sqlDataBase.setDatabaseName("data.sqlite");
}
//----------------------------------------------------------------------------
DeSqlDataBase::~DeSqlDataBase()
{

}
//----------------------------------------------------------------------------
bool DeSqlDataBase::openDataBase()
{
	///已经打开
	if (m_sqlDataBase.isOpen())
		return true;

	bool bOk = m_sqlDataBase.open();
	m_sqlQuery = new QSqlQuery(m_sqlDataBase);
	return bOk;
}
//----------------------------------------------------------------------------
void DeSqlDataBase::closeDataBase()
{
	if (m_sqlDataBase.isOpen())
		m_sqlDataBase.close();

	if (m_sqlQuery != NULL)
	{
		delete m_sqlQuery;
		m_sqlQuery = NULL;
	}
}
//----------------------------------------------------------------------------
bool DeSqlDataBase::execSql(const QString &sql)
{
	if (!m_sqlDataBase.isOpen())
		return false;

	if (m_sqlQuery == NULL)
		return false;

	return m_sqlQuery->exec(sql);
}
//----------------------------------------------------------------------------
QSqlQuery *DeSqlDataBase::getSqlQuery()
{
	return m_sqlQuery;
}
//----------------------------------------------------------------------------