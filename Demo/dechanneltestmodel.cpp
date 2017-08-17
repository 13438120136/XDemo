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
	return 0;
}
//----------------------------------------------------------------------------
QVariant DeChannelTestModel::dataShow(const QModelIndex &index) const
{
	Q_UNUSED(index)
	return QVariant();	
}
//----------------------------------------------------------------------------