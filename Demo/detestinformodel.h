#ifndef DETESTINFORMODEL_H
#define DETESTINFORMODEL_H

#include <detablemodel.h>
#include <QList>

struct EffectTestData
{
	int channel;		
	int highPressure;	
	int thresholdValue;	
	int bValue;		
	int testValue;	
	int efficiency;	
};

class DeTestInforModel : public DeTableModel
{
	Q_OBJECT

public:
	DeTestInforModel(QObject *parent = 0);
	~DeTestInforModel();
 
	QList<EffectTestData> &data();

protected:
	///当前表格中每一页要显示的行数 默认只显示一行
	virtual int perPageCount();
	///根据数据模型显示内容
	virtual QVariant dataShow(const QModelIndex &index) const;
	///要显示数据的总大小
	virtual int dataSize();

private:
	QList<EffectTestData> m_data;
};

#endif // DETESTINFORMODEL_H
