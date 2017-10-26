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
	void setPolluteChannel(const QList<int> &channel);
	///设置污染数据
	void setPolluteData(const QByteArray &byteArray);
	///时间
	quint64 getAlermTime();
	///获取通道
	QString getChannel();
	///获取数据
	QByteArray getData();

	bool insertDataToDataBase();

	/*
	* 根据时间范围从数据库获取数据
	* 注意: 查询结果由内部分配控件 一定要在使用之后释放
	*/
	QList<DeValueObjectInterface *> selectDataFromDBRange(qint64 start, qint64 end);

protected:
	QString execAddString();
	QString execSelectString();
	QList<DeValueObjectInterface *> selectValue(QSqlQuery *sqlQuery);

private:
	quint64 m_alermTime;			///报警事件
	QString m_polluteChannel;		///污染通道
	QByteArray m_polluteData;		///污染数据
};

#endif // DEALERMTABLE_H
