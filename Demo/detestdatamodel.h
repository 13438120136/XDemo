#ifndef DETESTDATAMODEL_H
#define DETESTDATAMODEL_H

#include <detablemodel.h>

struct TestData
{
	int channel;				   ///通道
	int value;					   ///本底值
	int testValue;				   ///测量值
	int thresholdValue;			   ///阀值
	int pollutionStatus;		   ///污染状态

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
	///当前表格中每一页要显示的行数 默认只显示一行
	virtual int perPageCount();
	///根据数据模型显示内容
	virtual QVariant dataShow(const QModelIndex &index) const;
	///要显示数据的总大小
	virtual int dataSize();

private:
	QList<TestData> m_testData;
};

#endif // DETESTDATAMODEL_H
