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

	///打开数据库
	bool openDataBase();
	///关闭数据库
	void closeDataBase();
	///执行具体sql语句
	bool execSql(const QString &sql);
	///获取当前QSqlQuery对象
	QSqlQuery *getSqlQuery();
	QSqlDatabase &dataBase();

private:
	QSqlDatabase m_sqlDataBase;
	///具体执行对象
	QSqlQuery *m_sqlQuery;
};

#endif // DESQLDATABASE_H
