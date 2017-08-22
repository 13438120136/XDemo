#include "detestdatamodel.h"

//----------------------------------------------------------------------------
DeTestDataModel::DeTestDataModel(QObject *parent)
	: DeTableModel(parent)
{
	this->setColumnCount(5);
	this->setRowCount(perPageCount());
	QStringList headLabels;
	headLabels << QString::fromLocal8Bit("通道号")
		<< QString::fromLocal8Bit("本底值") 
		<< QString::fromLocal8Bit("测量值") 
		<< QString::fromLocal8Bit("阀值") 
		<< QString::fromLocal8Bit("污染状态") ;
	this->setHorizontalHeaderLabels(headLabels);
}
//----------------------------------------------------------------------------
DeTestDataModel::~DeTestDataModel()
{

}
//----------------------------------------------------------------------------
void DeTestDataModel::setData(const QList<TestData> &data)
{
	m_testData = data;
}
//----------------------------------------------------------------------------
int DeTestDataModel::perPageCount()
{
	return 3;
}
//----------------------------------------------------------------------------
int DeTestDataModel::dataSize()
{
	return m_testData.size();
}
//----------------------------------------------------------------------------
QVariant DeTestDataModel::dataShow(const QModelIndex &index) const
{
	int row = index.row();
	int column = index.column();

	QList<TestData> tmpData = m_testData.mid(indexData());	
	if (row + 1 > tmpData.size())
		return QVariant();

	switch(column)
	{
	case 0:
		return tmpData[row].channel;
	case 1:
		return tmpData[row].value;
	case 2:
		return tmpData[row].testValue;
	case 3:
		return tmpData[row].thresholdValue;
	case 4:
		return tmpData[row].pollutionStatus;
	default:
		return QVariant();
	}	
}
//----------------------------------------------------------------------------