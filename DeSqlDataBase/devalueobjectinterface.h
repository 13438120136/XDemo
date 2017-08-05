#ifndef DEVALUEOBJECTINTERFACE_H
#define DEVALUEOBJECTINTERFACE_H

#include <QList>
#include "desqldatabase_global.h"

class DeSqlDataBase;
class QSqlQuery;

class DESQLDATABASE_EXPORT DeValueObjectInterface
{
public:
	DeValueObjectInterface(DeSqlDataBase *db);
	~DeValueObjectInterface();

	///��ǰ���ݿ������һ������¼
	bool insertDataToDB();
	/* 
	 * �����ݿ��в�ѯ��¼
	 * ע��: ��ѯ������ڲ�����ؼ� һ��Ҫ��ʹ��֮���ͷ�
	 */
	QList<DeValueObjectInterface *> selectDataFromDB();	
	///ִ�о����Sql���
	bool execSql(const QString &sql);

protected:
	///��װ��������ַ���
	virtual QString execAddString() = 0;
	///��װ��ѯ�����ַ���
	virtual QString execSelectString() = 0;
	///��ѯ����
	virtual QList<DeValueObjectInterface *> selectValue(QSqlQuery *sqlQuery) = 0;
	///��ȡ��Ӧ�����ݿ����
	DeSqlDataBase *currSqlDataBase();

private:
	DeSqlDataBase *m_db;
};

#endif // DEVALUEOBJECTINTERFACE_H
