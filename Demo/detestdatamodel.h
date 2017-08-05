#ifndef DETESTDATAMODEL_H
#define DETESTDATAMODEL_H

#include <detablemodel.h>

struct TestData
{
	int channel;				   ///ͨ��
	int value;					   ///����ֵ
	int testValue;				   ///����ֵ
	int thresholdValue;			   ///��ֵ
	int pollutionStatus;		   ///��Ⱦ״̬

	TestData(int channel, int value, int testValue, int thresholdValue, int pollutionStatus)
	{
		this->channel = channel;
		this->value = value;
		this->testValue = testValue;
		this->thresholdValue = thresholdValue;
		this->pollutionStatus = pollutionStatus;
	}
};

class DeTestDataModel : public DeTableModel
{
	Q_OBJECT

public:
	DeTestDataModel(QObject *parent);
	~DeTestDataModel();

	void setData(const QList<TestData> &data);

protected:
	///��ǰ�����ÿһҳҪ��ʾ������ Ĭ��ֻ��ʾһ��
	virtual int perPageCount();
	///��������ģ����ʾ����
	virtual QVariant dataShow(const QModelIndex &index) const;
	///Ҫ��ʾ���ݵ��ܴ�С
	virtual int dataSize();

private:
	QList<TestData> m_testData;
};

#endif // DETESTDATAMODEL_H
