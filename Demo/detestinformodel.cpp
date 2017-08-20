#include "detestinformodel.h"

//----------------------------------------------------------------------------
DeTestInforModel::DeTestInforModel(QObject *parent)
	: DeTableModel(parent)
{
	this->setColumnCount(4);
	this->setRowCount(perPageCount());
	QStringList headLabels;
	headLabels << QString::fromLocal8Bit("ͨ����")
		<< QString::fromLocal8Bit("��ѹֵ") 
		<< QString::fromLocal8Bit("��ֵ") 
		<< QString::fromLocal8Bit("����ֵ")
		<< QString::fromLocal8Bit("����ֵֵ")
		<< QString::fromLocal8Bit("Ч��");
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