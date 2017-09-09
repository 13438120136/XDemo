#ifndef DEDETECTORMODEL_H
#define DEDETECTORMODEL_H

#include <detablemodel.h>

///探测器表格模型
class DeDetectorModel : public DeTableModel
{
	Q_OBJECT

public:
	DeDetectorModel(QObject *parent);
	~DeDetectorModel();

protected:
	///当前表格中每一页要显示的行数 默认只显示一行
	virtual int perPageCount();
	///根据数据模型显示内容
	virtual QVariant dataShow(const QModelIndex &index) const;
	///要显示数据的总大小
	virtual int dataSize();

private:
	
};

#endif // DEDETECTORMODEL_H
