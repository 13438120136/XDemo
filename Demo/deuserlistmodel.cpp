#include "deuserlistmodel.h"

//----------------------------------------------------------------------------
DeUserListModel::DeUserListModel(QObject *parent)
	: DeTableModel(parent)
{
	this->setColumnCount(2);
	this->setRowCount(perPageCount());
	QStringList headLabels;
	headLabels << QString::fromLocal8Bit("用户名")
		<< QString::fromLocal8Bit("权限");
	this->setHorizontalHeaderLabels(headLabels);
}
//----------------------------------------------------------------------------
DeUserListModel::~DeUserListModel()
{

}
//----------------------------------------------------------------------------
void DeUserListModel::setData(const QList<DeUserTable> &data)
{
	m_userData = data;
}
//----------------------------------------------------------------------------
QList<DeUserTable> &DeUserListModel::data()
{
	return m_userData;
}
//----------------------------------------------------------------------------
int DeUserListModel::perPageCount()
{
	return 7;
}
//----------------------------------------------------------------------------
int DeUserListModel::dataSize()
{
	return m_userData.size();
}
//----------------------------------------------------------------------------
QVariant DeUserListModel::dataShow(const QModelIndex &index) const
{
	int row = index.row();
	int column = index.column();

	QList<DeUserTable> tmpData = m_userData.mid(indexData());	
	if (row + 1 > tmpData.size())
		return QVariant();

	switch(column)
	{
	case 0:
		return tmpData[row].getUerName();
	case 1:
		return tmpData[row].getUserPermissionName();
	default:
		return QVariant();
	}	
}
//----------------------------------------------------------------------------
Qt::ItemFlags DeUserListModel::flags(const QModelIndex &index) const
{
	Q_UNUSED(index)
	return Qt::ItemIsSelectable | Qt::ItemIsEnabled;
}
//----------------------------------------------------------------------------