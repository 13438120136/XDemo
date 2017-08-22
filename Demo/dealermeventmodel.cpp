#include "dealermeventmodel.h"

//----------------------------------------------------------------------------
DeAlermEventModel::DeAlermEventModel(QObject *parent)
	: DeTableModel(parent)
{
	this->setColumnCount(3);
	this->setRowCount(perPageCount());
	QStringList headLabels;
	headLabels << QString::fromLocal8Bit("序号")
		<< QString::fromLocal8Bit("污染时间") 
		<< QString::fromLocal8Bit("污染通道") ;
	this->setHorizontalHeaderLabels(headLabels);
}
//----------------------------------------------------------------------------
DeAlermEventModel::~DeAlermEventModel()
{

}
//----------------------------------------------------------------------------
void DeAlermEventModel::setData(const QList<AlermEventData> &data)
{
	m_data = data;
}
//----------------------------------------------------------------------------
int DeAlermEventModel::perPageCount()
{
	return 3;
}
//----------------------------------------------------------------------------
int DeAlermEventModel::dataSize()
{
	return m_data.size();
}
//----------------------------------------------------------------------------
QVariant DeAlermEventModel::dataShow(const QModelIndex &index) const
{
	int row = index.row();
	int column = index.column();

	QList<AlermEventData> tmpData = m_data.mid(indexData());	
	if (row + 1 > tmpData.size())
		return QVariant();

	switch(column)
	{
	case 0:
		return tmpData[row].orderNumber;
	case 1:
		return tmpData[row].time;
	case 2:
		return tmpData[row].channel;
	default:
		return QVariant();
	}	
}
//----------------------------------------------------------------------------