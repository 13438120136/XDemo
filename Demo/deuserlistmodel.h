#ifndef DEUSERLISTMODEL_H
#define DEUSERLISTMODEL_H

#include <detablemodel.h>
#include <deusertable.h>

///用户列表数据模型
class DeUserListModel : public DeTableModel
{
	Q_OBJECT

public:
	DeUserListModel(QObject *parent);
	~DeUserListModel();

	void setData(const QList<DeUserTable> &data);
	QList<DeUserTable> &data();

protected:
	///当前表格中每一页要显示的行数 默认只显示一行
	virtual int perPageCount();
	///根据数据模型显示内容
	virtual QVariant dataShow(const QModelIndex &index) const;
	///要显示数据的总大小
	virtual int dataSize();
	Qt::ItemFlags flags(const QModelIndex &index) const;

private:
	QList<DeUserTable> m_userData;
};

#endif // DEUSERLISTMODEL_H
