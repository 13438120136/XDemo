#ifndef DERADIOACTIVESOURCETABLE_H
#define DERADIOACTIVESOURCETABLE_H

#include <QString>
#include "desqldatabase_global.h"
#include "devalueobjectinterface.h"

///ÿһ�����Դ���������Ŀֵ����
class DESQLDATABASE_EXPORT DeRadioactiveSourceTable : public DeValueObjectInterface
{
public:
	DeRadioactiveSourceTable(DeSqlDataBase *db);
	~DeRadioactiveSourceTable();

	///��ʼ����ṹ
	void initTable();

	///���ñ��
	void setID(int id);
	///��ȡ���
	int getID();
	///������������
	void setDateProduct(quint64 date);
	///��������
	quint64 getDateProduct();
	///����ԭʼ���
	void setOriginalValue(int originalValue);
	///��ȡԭʼ���
	int getOriginalValue();
	///�������� 1-alpha 2-beta
	void setType(int type);
	///��ȡ����
	int getType();

protected:
	QString execAddString();
	QString execSelectString();
	QList<DeValueObjectInterface *> selectValue(QSqlQuery *sqlQuery);

private:
	int m_identifier;				///���
	quint64 m_dateOfProduct;		///��������
	int m_originalValue;			///ԭʼ���
	int m_type;						///��ǰ����
};

#endif // DERADIOACTIVESOURCETABLE_H
