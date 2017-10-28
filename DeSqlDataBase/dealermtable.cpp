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

	initTable();
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
						  channel TEXT,						\
						  data BLOB							\
						  );").arg(tableName);

	execSql(sql);
}
//----------------------------------------------------------------------------
void DeAlermTable::setPolluteChannel(const QList<int> &channel)
{
	int nCount = channel.size();
	QString str;
	for (int i = 0; i < nCount; i++)
	{
		str.append(QString::number(channel[i]));
		str.append(",");
	}

	str.remove(str.size() - 1, 1);
	m_polluteChannel = str;
}
//----------------------------------------------------------------------------
QString DeAlermTable::execAddString()
{
	//QString sql = QString("insert into %1 values('%2', '%3', '%4')")
	//	.arg(tableName).arg(m_alermTime).arg(m_polluteChannel).arg(m_polluteData);
	//return sql;
	return "";
}
//----------------------------------------------------------------------------
bool DeAlermTable::insertDataToDataBase()
{
	m_alermTime = QDateTime::currentMSecsSinceEpoch();

	DeSqlDataBase *db = currSqlDataBase();
	QSqlQuery sqlQuery(db->dataBase());
	QString sql = QString("insert into %1 values (?, ?, ?)").arg(tableName);
	sqlQuery.prepare(sql);
	sqlQuery.bindValue(0, m_alermTime);
	sqlQuery.bindValue(1, m_polluteChannel);
	sqlQuery.bindValue(2, m_polluteData);
	return sqlQuery.exec();
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

	QSqlQuery sqlQueryObj(*sqlQuery);
	while (sqlQueryObj.next())
	{
		DeAlermTable *table = new DeAlermTable(this->currSqlDataBase());
		table->m_alermTime = sqlQueryObj.value(0).value<quint64>();
		table->m_polluteChannel = sqlQueryObj.value(1).toString();
		table->m_polluteData = sqlQueryObj.value(2).toByteArray();

		result.append(table);
	}

	return result;
}
//----------------------------------------------------------------------------
void DeAlermTable::setPolluteData(const QByteArray &byteArray)
{
	m_polluteData = byteArray;
}
//----------------------------------------------------------------------------
quint64 DeAlermTable::getAlermTime()
{
	return m_alermTime;
}
//----------------------------------------------------------------------------
QString DeAlermTable::getChannel()
{
	return m_polluteChannel;
}
//----------------------------------------------------------------------------
QByteArray DeAlermTable::getData()
{
	return m_polluteData;
}
//----------------------------------------------------------------------------