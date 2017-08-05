#include "dedevicetable.h"

///当前对象对应的数据库表名称
const QString tableName = "deviceSettingTable";

//----------------------------------------------------------------------------
DeDeviceTable::DeDeviceTable(DeSqlDataBase *db)
	: DeValueObjectInterface(db)
{

}
//----------------------------------------------------------------------------
DeDeviceTable::~DeDeviceTable()
{

}
//----------------------------------------------------------------------------