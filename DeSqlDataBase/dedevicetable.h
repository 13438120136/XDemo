#ifndef DEDEVICETABLE_H
#define DEDEVICETABLE_H

#include <QString>
#include "desqldatabase_global.h"
#include <devalueobjectinterface.h>

///设备设置信息值对象
class DESQLDATABASE_EXPORT DeDeviceTable : public DeValueObjectInterface
{
public:
	DeDeviceTable(DeSqlDataBase *db);
	~DeDeviceTable();

private:
	
};

#endif // DEDEVICETABLE_H
