#ifndef DETESTINFORMODEL_H
#define DETESTINFORMODEL_H

#include <detablemodel.h>

class DeTestInforModel : public DeTableModel
{
	Q_OBJECT

public:
	DeTestInforModel(QObject *parent = 0);
	~DeTestInforModel();

protected:
	///当前表格中每一页要显示的行数 默认只显示一行
	virtual int perPageCount();
	///根据数据模型显示内容
	virtual QVariant dataShow(const QModelIndex &index) const;
	///要显示数据的总大小
	virtual int dataSize();
	
};

#endif // DETESTINFORMODEL_H
