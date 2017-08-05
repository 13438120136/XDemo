#ifndef DERADIOACTIVESOURCETABLE_H
#define DERADIOACTIVESOURCETABLE_H

#include <QString>
#include "desqldatabase_global.h"
#include <devalueobjectinterface.h>

///每一项放射源管理对象条目值对象
class DESQLDATABASE_EXPORT DeRadioactiveSourceTable : public DeValueObjectInterface
{
public:
	DeRadioactiveSourceTable(DeSqlDataBase *db);
	~DeRadioactiveSourceTable();

	///初始化表结构
	void initTable();

	///设置编号
	void setID(int id);
	///获取编号
	int getID();
	///设置生产日期
	void setDateProduct(quint64 date);
	///生产日期
	quint64 getDateProduct();
	///设置原始活度
	void setOriginalValue(int originalValue);
	///获取原始活度
	int getOriginalValue();

protected:
	QString execAddString();
	QString execSelectString();
	QList<DeValueObjectInterface *> selectValue(QSqlQuery *sqlQuery);

private:
	int m_identifier;				///编号
	quint64 m_dateOfProduct;		///生产日期
	int m_originalValue;			///原始活度
};

#endif // DERADIOACTIVESOURCETABLE_H
