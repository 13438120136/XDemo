#ifndef DEALERMTABLE_H
#define DEALERMTABLE_H

#include <QString>
#include "desqldatabase_global.h"
#include "devalueobjectinterface.h"

///����������Ӧֵ����
class DESQLDATABASE_EXPORT DeAlermTable : public DeValueObjectInterface
{
public:
	DeAlermTable(DeSqlDataBase *db);
	~DeAlermTable();

	///��ʼ����ṹ
	void initTable();
	///������Ⱦͨ��
	void setPolluteChannel(const QList<int> &channel);
	///������Ⱦ����
	void setPolluteData(const QByteArray &byteArray);
	///ʱ��
	quint64 getAlermTime();
	///��ȡͨ��
	QString getChannel();
	///��ȡ����
	QByteArray getData();

	bool insertDataToDataBase();

protected:
	QString execAddString();
	QString execSelectString();
	QList<DeValueObjectInterface *> selectValue(QSqlQuery *sqlQuery);

private:
	quint64 m_alermTime;			///�����¼�
	QString m_polluteChannel;		///��Ⱦͨ��
	QByteArray m_polluteData;		///��Ⱦ����
};

#endif // DEALERMTABLE_H
