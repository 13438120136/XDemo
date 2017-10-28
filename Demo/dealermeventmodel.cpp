#include "dealermeventmodel.h"
#include <QDateTime>

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
void DeAlermEventModel::setData(const QList<DeAlermTable> &data)
{
	m_data = data;
}
//----------------------------------------------------------------------------
int DeAlermEventModel::perPageCount()
{
	return  10;
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

	QList<DeAlermTable> tmpData = m_data.mid(indexData());	
	if (row + 1 > tmpData.size())
		return QVariant();

	switch(column)
	{
	case 0:
		return (indexData() + row);
	case 1:
		return QDateTime::fromMSecsSinceEpoch(tmpData[row].getAlermTime()).toString("hh:mm:ss");
	case 2:
		return tmpData[row].getChannel();
	default:
		return QVariant();
	}	
}
//----------------------------------------------------------------------------
Qt::ItemFlags DeAlermEventModel::flags(const QModelIndex &index) const
{
	Q_UNUSED(index)
	return Qt::ItemIsSelectable | Qt::ItemIsEnabled;
}
//----------------------------------------------------------------------------
QList<DeAlermTable> &DeAlermEventModel::getData()
{
	return m_data;
}
//----------------------------------------------------------------------------