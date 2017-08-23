#ifndef DEDEVICETABLE_H
#define DEDEVICETABLE_H

#include <QString>
#include "desqldatabase_global.h"
#include "devalueobjectinterface.h"
#include "desystemparam.h"

///�豸������Ϣֵ����
class DESQLDATABASE_EXPORT DeDeviceTable : public DeValueObjectInterface
{
public:
	DeDeviceTable(DeSqlDataBase *db);
	~DeDeviceTable();

	void initTable();
	bool insertDataToDB(DeSystemParam &data);
	bool updateDataToDB(DeSystemParam &data);
	DeSystemParam selectDB();
	///������ݿ���Ƿ�Ϊ��
	bool isEmptyInTable();

protected:
	///��װ��������ַ���
	virtual QString execAddString();
	///��װ��ѯ�����ַ���
	virtual QString execSelectString();
	///��ѯ����
	virtual QList<DeValueObjectInterface *> selectValue(QSqlQuery *sqlQuery);	
};

#endif // DEDEVICETABLE_H
