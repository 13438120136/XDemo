#include "dechanneltestmodel.h"

//----------------------------------------------------------------------------
DeChannelTestModel::DeChannelTestModel(QObject *parent)
	: DeTableModel(parent)
{
	this->setColumnCount(4);
	this->setRowCount(perPageCount());
	QStringList headLabels;
	headLabels << QString::fromLocal8Bit("ÐòºÅ")
		<< QString::fromLocal8Bit("¦Á+¦Â") 
		<< QString::fromLocal8Bit("¦Á") 
		<< QString::fromLocal8Bit("¦Â") ;
	this->setHorizontalHeaderLabels(headLabels);
}
//----------------------------------------------------------------------------
DeChannelTestModel::~DeChannelTestModel()
{

}
//----------------------------------------------------------------------------
int DeChannelTestModel::perPageCount()
{
	return 5;
}
//----------------------------------------------------------------------------
int DeChannelTestModel::dataSize()
{
	return m_data.size();
}
//----------------------------------------------------------------------------
QVariant DeChannelTestModel::dataShow(const QModelIndex &index) const
{
	int row = index.row();
	int column = index.column();

	QList<ChannelData> tmpData = m_data.mid(indexData());	
	if (row + 1 > tmpData.size())
		return QVariant();

	switch(column)
	{
	case 0:
		return row;
	case 1:
		return tmpData[row].alphaBeta;
	case 2:
		return tmpData[row].alpha;
	case 3:
		return tmpData[row].Beta;
	default:
		return QVariant();
	}

	return QVariant();	
}
//----------------------------------------------------------------------------
QList<ChannelData> &DeChannelTestModel::data()
{
	return m_data;
}
//----------------------------------------------------------------------------