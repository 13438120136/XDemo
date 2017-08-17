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
	void setPolluteChannel(quint32 channel);

protected:
	QString execAddString();
	QString execSelectString();
	QList<DeValueObjectInterface *> selectValue(QSqlQuery *sqlQuery);

private:
	quint64 m_alermTime;			///�����¼�
	quint32 m_polluteChannel;		///��Ⱦͨ��
};

#endif // DEALERMTABLE_H
