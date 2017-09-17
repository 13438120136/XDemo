#include "deradioactivitymodel.h"
#include <QDateTime>

//----------------------------------------------------------------------------
DeRadioactivityModel::DeRadioactivityModel(QObject *parent)
	: DeTableModel(parent)
{
	this->setColumnCount(5);
	this->setRowCount(perPageCount());
	QStringList headLabels;
	headLabels << QString::fromLocal8Bit("编号")
		<< QString::fromLocal8Bit("放射源类型") 
		<< QString::fromLocal8Bit("生产日期") 
		<< QString::fromLocal8Bit("原始活度") 
		<< QString::fromLocal8Bit("当前活度") ;
	this->setHorizontalHeaderLabels(headLabels);
}
//----------------------------------------------------------------------------
DeRadioactivityModel::~DeRadioactivityModel()
{

}
//----------------------------------------------------------------------------
void DeRadioactivityModel::setData(const QList<DeRadioactiveSourceTable> &data)
{
	m_data = data;
}
//----------------------------------------------------------------------------
QList<DeRadioactiveSourceTable> &DeRadioactivityModel::data()
{
	return m_data;
}
//----------------------------------------------------------------------------
int DeRadioactivityModel::perPageCount()
{
	return 5;
}
//----------------------------------------------------------------------------
int DeRadioactivityModel::dataSize()
{
	return m_data.size();
}
//----------------------------------------------------------------------------
QVariant DeRadioactivityModel::dataShow(const QModelIndex &index) const
{
	int row = index.row();
	int column = index.column();

	QList<DeRadioactiveSourceTable> tmpData = m_data.mid(indexData());	
	if (row + 1 > tmpData.size())
		return QVariant();

	switch(column)
	{
	case 0:
		return tmpData[row].getID();
	case 1:
		return "";
	case 2:
		{
			quint64 time = tmpData[row].getDateProduct();
			return QDateTime::fromMSecsSinceEpoch(time).toString("yyyy-MM-dd");
		}
	case 3:
		return tmpData[row].getOriginalValue();
	case 4:
		return "";
	default:
		return QVariant();
	}
}
//----------------------------------------------------------------------------
Qt::ItemFlags DeRadioactivityModel::flags(const QModelIndex &index) const
{
	Q_UNUSED(index)
	return Qt::ItemIsSelectable | Qt::ItemIsEnabled;
}
//----------------------------------------------------------------------------