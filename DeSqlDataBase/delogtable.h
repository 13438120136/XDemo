#ifndef DELOGTABLE_H
#define DELOGTABLE_H

#include <QString>
#include "desqldatabase_global.h"
#include "devalueobjectinterface.h"

///保存日志信息
class DESQLDATABASE_EXPORT DeLogTable : public DeValueObjectInterface
{
public:
	DeLogTable(DeSqlDataBase *db);
	~DeLogTable();

	void initTable();

protected:
	///组装添加数据字符串
	virtual QString execAddString();
	///组装查询数据字符串
	virtual QString execSelectString();
	///查询数据
	virtual QList<DeValueObjectInterface *> selectValue(QSqlQuery *sqlQuery);	
};

#endif // DELOGTABLE_H
