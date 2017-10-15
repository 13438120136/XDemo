#ifndef DETECTORTABLE_H
#define DETECTORTABLE_H

#include <devalueobjectinterface.h>
#include <QString>
#include "desqldatabase_global.h"

///̽�����������ݿ��Ӧ���¼
class DESQLDATABASE_EXPORT DetectorTable : public DeValueObjectInterface
{
public:
	DetectorTable(DeSqlDataBase *db);
	~DetectorTable();

	///����ͨ����
	void setChannelNumber(int number);
	///���ü���ʱ��
	void setCountingTime(int time);
	///���ø�ѹ���
	void setDeviation(int deviation);
	///����굱�����ֵ1
	void setTheshold1(int value);
	///����굱�����ֵ2
	void setTheshold2(int value);
	///����굱�����ֵ3
	void setTheshold3(int value);

	int getChannelNumber();
	int getCountingTime();
	int getDeviation();
	int getTheshold1();
	int getTheshold2();
	int getTheshold3();

	///ͨ��ͨ����ȡ��Ӧ̽��������
	QList<DeValueObjectInterface *> selectDataFromChannelNumber(int number);

private:
	int m_index;
	int m_time;
	int m_deviation;
	int m_theshold1;
	int m_theshold2;
	int m_theshold3;
};

#endif // DETECTORTABLE_H
