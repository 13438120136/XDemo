#include "dedetectormodel.h"

//----------------------------------------------------------------------------
DeDetectorModel::DeDetectorModel(QObject *parent)
	: DeTableModel(parent)
{
	this->setColumnCount(8);
	this->setRowCount(perPageCount());
	QStringList headLabels;
	headLabels << QString::fromLocal8Bit("通道")
		<< QString::fromLocal8Bit("高压值") 
		<< QString::fromLocal8Bit("阀值1") 
		<< QString::fromLocal8Bit("阀值2") 
		<< QString::fromLocal8Bit("阀值3") 
		<< QString::fromLocal8Bit("计数时间") 
		<< QString::fromLocal8Bit("高压误差") 
		<< QString::fromLocal8Bit("状态") ;
	this->setHorizontalHeaderLabels(headLabels);
}
//----------------------------------------------------------------------------
DeDetectorModel::~DeDetectorModel()
{
}
//----------------------------------------------------------------------------
int DeDetectorModel::perPageCount()
{
	return 4;
}
//----------------------------------------------------------------------------
int DeDetectorModel::dataSize()
{
	return 0;
}
//----------------------------------------------------------------------------
QVariant DeDetectorModel::dataShow(const QModelIndex &index) const
{
	return QVariant();
}