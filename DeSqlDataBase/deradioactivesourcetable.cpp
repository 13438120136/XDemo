#include "deradioactivesourcetable.h"
#include "desqldatabase.h"
#include <qvariant.h>

const QString tableName = "radioactiveSourceTable";

//----------------------------------------------------------------------------
DeRadioactiveSourceTable::DeRadioactiveSourceTable(DeSqlDataBase *db)
	: DeValueObjectInterface(db)
{
	initTable();
}
//----------------------------------------------------------------------------
DeRadioactiveSourceTable::~DeRadioactiveSourceTable()
{

}
//----------------------------------------------------------------------------
void DeRadioactiveSourceTable::initTable()
{
	QString sql = QString("CREATE TABLE IF NOT EXISTS %1(   \
						  id INT, 			    \
						  date INTEGER, 		\
						  original INT,		    \
						  type INT				\
						  );").arg(tableName);

	execSql(sql);
}
//----------------------------------------------------------------------------
QString DeRadioactiveSourceTable::execAddString()
{
	QString sql = QString("insert into %1 values(%2, %3, %4, %5)")
		.arg(tableName).arg(m_identifier).arg(m_dateOfProduct).arg(m_originalValue).arg(m_type);
	return sql;
}
//----------------------------------------------------------------------------
QString DeRadioactiveSourceTable::execSelectString()
{
	return QString("select * from %1").arg(tableName);
}
//----------------------------------------------------------------------------
QList<DeValueObjectInterface *> DeRadioactiveSourceTable::selectValue(QSqlQuery *sqlQuery)
{
	QList<DeValueObjectInterface *> result;

	QSqlQuery sqlQueryObj(*sqlQuery);
	while (sqlQueryObj.next())
	{
		DeRadioactiveSourceTable *table = new DeRadioactiveSourceTable(this->currSqlDataBase());
		table->m_identifier = sqlQueryObj.value(0).toInt();
		table->m_dateOfProduct = sqlQueryObj.value(1).value<quint64>();
		table->m_originalValue = sqlQueryObj.value(2).toInt();
		table->m_type = sqlQueryObj.value(3).toInt();

		result.append(table);
	}

	return result;
}
//----------------------------------------------------------------------------
void DeRadioactiveSourceTable::setID(int id)
{
	m_identifier = id;
}
//----------------------------------------------------------------------------
int DeRadioactiveSourceTable::getID()
{
	return m_identifier;
}
//----------------------------------------------------------------------------
void DeRadioactiveSourceTable::setDateProduct(quint64 date)
{
	m_dateOfProduct = date;
}
//----------------------------------------------------------------------------
quint64 DeRadioactiveSourceTable::getDateProduct()
{
	return m_dateOfProduct;
}
//----------------------------------------------------------------------------
void DeRadioactiveSourceTable::setOriginalValue(int originalValue)
{
	m_originalValue = originalValue;
}
//----------------------------------------------------------------------------
int DeRadioactiveSourceTable::getOriginalValue()
{
	return m_originalValue;
}
//----------------------------------------------------------------------------
void DeRadioactiveSourceTable::setType(int type)
{
	m_type = type;
}
//----------------------------------------------------------------------------
int DeRadioactiveSourceTable::getType()
{
	return m_type;
}
//----------------------------------------------------------------------------