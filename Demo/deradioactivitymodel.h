#ifndef DERADIOACTIVITYMODEL_H
#define DERADIOACTIVITYMODEL_H

#include <detablemodel.h>
#include "deradioactivesourcetable.h"

///放射性管理数据模型
class DeRadioactivityModel : public DeTableModel
{
	Q_OBJECT

public:
	DeRadioactivityModel(QObject *parent = 0);
	~DeRadioactivityModel();

	void setData(const QList<DeRadioactiveSourceTable> &data);
	QList<DeRadioactiveSourceTable> &data();

protected:
	///当前表格中每一页要显示的行数 默认只显示一行
	virtual int perPageCount();
	///根据数据模型显示内容
	virtual QVariant dataShow(const QModelIndex &index) const;
	///要显示数据的总大小
	virtual int dataSize();

private:
	QList<DeRadioactiveSourceTable> m_data;
};

#endif // DERADIOACTIVITYMODEL_H
