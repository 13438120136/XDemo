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

	///向当前数据库中添加一个条记录
	bool insertDataToDB();
	/* 
	 * 从数据库中查询记录
	 * 注意: 查询结果由内部分配控件 一定要在使用之后释放
	 */
	QList<DeValueObjectInterface *> selectDataFromDB();	
	///执行具体的Sql语句
	bool execSql(const QString &sql);

protected:
	///组装添加数据字符串
	virtual QString execAddString() = 0;
	///组装查询数据字符串
	virtual QString execSelectString() = 0;
	///查询数据
	virtual QList<DeValueObjectInterface *> selectValue(QSqlQuery *sqlQuery) = 0;
	///获取对应的数据库对象
	DeSqlDataBase *currSqlDataBase();

private:
	DeSqlDataBase *m_db;
};

#endif // DEVALUEOBJECTINTERFACE_H
