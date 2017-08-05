#include "dealermtable.h"
#include "desqldatabase.h"
#include <QDateTime>
#include <QVariant>

///当前对象对应的数据库表名称
const QString tableName = "alermTable";

//----------------------------------------------------------------------------
DeAlermTable::DeAlermTable(DeSqlDataBase *db)
	: DeValueObjectInterface(db)
{
	m_alermTime = 0;
	m_polluteChannel = 0;
}
//----------------------------------------------------------------------------
DeAlermTable::~DeAlermTable()
{

}
//----------------------------------------------------------------------------
void DeAlermTable::initTable()
{
	QString sql = QString("CREATE TABLE IF NOT EXISTS %1(   \
						  time INTEGER, 			    	\
						  channel int						\
						  );").arg(tableName);

	execSql(sql);
}
//----------------------------------------------------------------------------
void DeAlermTable::setPolluteChannel(quint32 channel)
{
	m_polluteChannel = channel;
}
//----------------------------------------------------------------------------
QString DeAlermTable::execAddString()
{
	m_alermTime = QDateTime::currentMSecsSinceEpoch();

	QString sql = QString("insert into %1 values('%2', '%3')")
		.arg(tableName).arg(m_alermTime).arg(m_polluteChannel);
	return sql;
}
//----------------------------------------------------------------------------
QString DeAlermTable::execSelectString()
{
	return QString("select * from %1").arg(tableName);
}
//----------------------------------------------------------------------------
QList<DeValueObjectInterface *> DeAlermTable::selectValue(QSqlQuery *sqlQuery)
{
	QList<DeValueObjectInterface *> result;

	while (sqlQuery->next())
	{
		DeAlermTable *table = new DeAlermTable(this->currSqlDataBase());
		table->m_alermTime = sqlQuery->value(0).value<quint64>();
		table->m_polluteChannel = sqlQuery->value(1).toInt();
		result.append(table);
	}

	return result;
}
//----------------------------------------------------------------------------