#ifndef DESQLDATABASE_H
#define DESQLDATABASE_H

#include "desqldatabase_global.h"
#include <QSqlDatabase>
#include <QSqlQuery>

class DESQLDATABASE_EXPORT DeSqlDataBase
{
public:
	DeSqlDataBase();
	~DeSqlDataBase();

	///�����ݿ�
	bool openDataBase();
	///�ر����ݿ�
	void closeDataBase();
	///ִ�о���sql���
	bool execSql(const QString &sql);
	///��ȡ��ǰQSqlQuery����
	QSqlQuery *getSqlQuery();
	QSqlDatabase &dataBase();

private:
	QSqlDatabase m_sqlDataBase;
	///����ִ�ж���
	QSqlQuery *m_sqlQuery;
};

#endif // DESQLDATABASE_H
