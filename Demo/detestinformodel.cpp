#include "detestinformodel.h"

//----------------------------------------------------------------------------
DeTestInforModel::DeTestInforModel(QObject *parent)
	: DeTableModel(parent)
{
	this->setColumnCount(4);
	this->setRowCount(perPageCount());
	QStringList headLabels;
	headLabels << QString::fromLocal8Bit("通道号")
		<< QString::fromLocal8Bit("高压值") 
		<< QString::fromLocal8Bit("阀值") 
		<< QString::fromLocal8Bit("本底值")
		<< QString::fromLocal8Bit("测量值值")
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
	return 0;
}
//----------------------------------------------------------------------------
QVariant DeTestInforModel::dataShow(const QModelIndex &index) const
{
	Q_UNUSED(index)
	return QVariant();	
}
//----------------------------------------------------------------------------