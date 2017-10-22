#include "detestinformodel.h"

//----------------------------------------------------------------------------
DeTestInforModel::DeTestInforModel(QObject *parent)
	: DeTableModel(parent)
{
	this->setColumnCount(6);
	this->setRowCount(perPageCount());
	QStringList headLabels;
	headLabels << QString::fromLocal8Bit("通道号")
		<< QString::fromLocal8Bit("高压值") 
		<< QString::fromLocal8Bit("阀值") 
		<< QString::fromLocal8Bit("本底值")
		<< QString::fromLocal8Bit("测量值")
		<< QString::fromLocal8Bit("效率");
	this->setHorizontalHeaderLabels(headLabels);
}
//----------------------------------------------------------------------------
DeTestInforModel::~DeTestInforModel()
{

}
//----------------------------------------------------------------------------
int DeTestInforModel::perPageCount()
{
	return 5;
}
//----------------------------------------------------------------------------
int DeTestInforModel::dataSize()
{
	return m_data.size();
}
//----------------------------------------------------------------------------
QVariant DeTestInforModel::dataShow(const QModelIndex &index) const
{
	int row = index.row();
	int column = index.column();

	QList<EffectTestData> tmpData = m_data.mid(indexData());	
	if (row + 1 > tmpData.size())
		return QVariant();

	switch(column)
	{
	case 0:
		return tmpData[row].channel;
	case 1:
		return tmpData[row].highPressure;
	case 2:
		return tmpData[row].thresholdValue;
	case 3:
		return tmpData[row].bValue;
	case 4:
		return tmpData[row].testValue;
	case 5:
		return tmpData[row].efficiency;
	default:
		return QVariant();
	}

	return QVariant();	
}
//----------------------------------------------------------------------------
QList<EffectTestData> &DeTestInforModel::data()
{
	return m_data;
}
//----------------------------------------------------------------------------