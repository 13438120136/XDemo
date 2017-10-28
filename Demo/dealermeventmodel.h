#ifndef DEALERMEVENTMODEL_H
#define DEALERMEVENTMODEL_H

#include <detablemodel.h>
#include <dealermtable.h>

///报警事件数据模型
class DeAlermEventModel : public DeTableModel
{
	Q_OBJECT

public:
	DeAlermEventModel(QObject *parent);
	~DeAlermEventModel();

	void setData(const QList<DeAlermTable> &data);
	QList<DeAlermTable> &getData();

protected:
	///当前表格中每一页要显示的行数 默认只显示一行
	virtual int perPageCount();
	///根据数据模型显示内容
	virtual QVariant dataShow(const QModelIndex &index) const;
	///要显示数据的总大小
	virtual int dataSize();
	Qt::ItemFlags flags(const QModelIndex &index) const;

private:
	QList<DeAlermTable> m_data;
};

#endif // DEALERMEVENTMODEL_H
