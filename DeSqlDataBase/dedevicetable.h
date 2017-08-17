#ifndef DEDEVICETABLE_H
#define DEDEVICETABLE_H

#include <QString>
#include "desqldatabase_global.h"
#include "devalueobjectinterface.h"

///设备设置信息值对象
class DESQLDATABASE_EXPORT DeDeviceTable : public DeValueObjectInterface
{
public:
	DeDeviceTable(DeSqlDataBase *db);
	~DeDeviceTable();

	void initTable();
	bool insertDataToDB();

protected:
	///组装添加数据字符串
	virtual QString execAddString();
	///组装查询数据字符串
	virtual QString execSelectString();
	///查询数据
	virtual QList<DeValueObjectInterface *> selectValue(QSqlQuery *sqlQuery);
	
};

#endif // DEDEVICETABLE_H
