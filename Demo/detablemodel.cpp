#include "detablemodel.h"

//----------------------------------------------------------------------------
DeTableModel::DeTableModel(QObject *parent)
	: QStandardItemModel(parent)
	,m_index(0)
{
}
//----------------------------------------------------------------------------
DeTableModel::~DeTableModel()
{

}
//----------------------------------------------------------------------------
Qt::ItemFlags DeTableModel::flags(const QModelIndex &index) const
{
	Q_UNUSED(index)
	return Qt::ItemIsEnabled;
}
//----------------------------------------------------------------------------
QVariant DeTableModel::data(const QModelIndex &index, int role) const
{
	int row = index.row();

	///显示背景颜色
	if ((role == Qt::BackgroundColorRole)
		&& (row%2 == 0))
	{
		QColor color(209, 209, 209, 30);
		return color;
	}

	if (role == Qt::TextAlignmentRole)
		return Qt::AlignCenter;

	///显示文本内容
	if (role == Qt::DisplayRole)
		return dataShow(index);

	return QStandardItemModel::data(index, role);
}
//----------------------------------------------------------------------------
QVariant DeTableModel::dataShow(const QModelIndex &index) const
{
	Q_UNUSED(index)
	return QVariant();
}
//----------------------------------------------------------------------------
int DeTableModel::perPageCount()
{
	return 1;
}
//----------------------------------------------------------------------------
int DeTableModel::dataSize()
{
	return 0;
}
//----------------------------------------------------------------------------
void DeTableModel::tableToFirst()
{
	m_index = 0;

	if (dataSize() < perPageCount())
		this->setRowCount(dataSize());
	else
		this->setRowCount(perPageCount());

	this->reset();
}
//----------------------------------------------------------------------------
void DeTableModel::tableToLast()
{
	int modCount = dataSize()%perPageCount();
	int nCount = dataSize()/perPageCount();

	if (nCount == 0)
		return ;

	if (modCount == 0)
	{
		m_index = (nCount - 1) * perPageCount();
		this->setRowCount(perPageCount());
	}
	else
	{
		m_index = nCount * perPageCount();
		this->setRowCount(modCount);
	}

	this->reset();
}
//----------------------------------------------------------------------------
void DeTableModel::tableToPrev()
{
	///超出边界返回
	if (m_index == 0)
		return ;

	m_index -= perPageCount();
	this->setRowCount(perPageCount());

	this->reset();
}
//----------------------------------------------------------------------------
void DeTableModel::tableToNext()
{
	///超出边界返回
	if (m_index + perPageCount() >= dataSize())
		return ;

	m_index += perPageCount();

	if ((dataSize() - m_index) < perPageCount())
		this->setRowCount(dataSize() - m_index);
	else
		this->setRowCount(perPageCount());

	this->reset();
}
//----------------------------------------------------------------------------
int DeTableModel::indexData() const
{
	return m_index;
}
//----------------------------------------------------------------------------
QString DeTableModel::pageMessage()
{
	int curr = m_index/perPageCount() + 1;
	int total = (dataSize()%perPageCount() == 0)?(dataSize()/perPageCount()):(dataSize()/perPageCount() + 1);

	///不能为0页 最小也是1
	if (total == 0)
		total = 1;

	return QString::fromLocal8Bit("%1/%2").arg(curr).arg(total);
}
//----------------------------------------------------------------------------
void DeTableModel::initColumnCount()
{
	this->setRowCount(dataSize() < perPageCount()?dataSize():perPageCount());
}
//----------------------------------------------------------------------------