#ifndef DEALERMTABLE_H
#define DEALERMTABLE_H

#include <QString>
#include "desqldatabase_global.h"
#include "devalueobjectinterface.h"

///报警条件对应值对象
class DESQLDATABASE_EXPORT DeAlermTable : public DeValueObjectInterface
{
public:
	DeAlermTable(DeSqlDataBase *db);
	~DeAlermTable();

	///初始化表结构
	void initTable();
	///设置污染通道
	void setPolluteChannel(quint32 channel);

protected:
	QString execAddString();
	QString execSelectString();
	QList<DeValueObjectInterface *> selectValue(QSqlQuery *sqlQuery);

private:
	quint64 m_alermTime;			///报警事件
	quint32 m_polluteChannel;		///污染通道
};

#endif // DEALERMTABLE_H
