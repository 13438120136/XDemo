#include "dedetectormodel.h"

//----------------------------------------------------------------------------
DeDetectorModel::DeDetectorModel(QObject *parent)
	: DeTableModel(parent)
{
	this->setColumnCount(8);
	this->setRowCount(perPageCount());
	QStringList headLabels;
	headLabels << QString::fromLocal8Bit("ͨ��")
		<< QString::fromLocal8Bit("��ѹֵ") 
		<< QString::fromLocal8Bit("��ֵ1") 
		<< QString::fromLocal8Bit("��ֵ2") 
		<< QString::fromLocal8Bit("��ֵ3") 
		<< QString::fromLocal8Bit("����ʱ��") 
		<< QString::fromLocal8Bit("��ѹ���") 
		<< QString::fromLocal8Bit("״̬") ;
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