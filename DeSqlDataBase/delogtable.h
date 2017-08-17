#ifndef DELOGTABLE_H
#define DELOGTABLE_H

#include <QString>
#include "desqldatabase_global.h"
#include "devalueobjectinterface.h"

///������־��Ϣ
class DESQLDATABASE_EXPORT DeLogTable : public DeValueObjectInterface
{
public:
	DeLogTable(DeSqlDataBase *db);
	~DeLogTable();

	void initTable();

protected:
	///��װ��������ַ���
	virtual QString execAddString();
	///��װ��ѯ�����ַ���
	virtual QString execSelectString();
	///��ѯ����
	virtual QList<DeValueObjectInterface *> selectValue(QSqlQuery *sqlQuery);	
};

#endif // DELOGTABLE_H
