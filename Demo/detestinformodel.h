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
	///��ǰ�����ÿһҳҪ��ʾ������ Ĭ��ֻ��ʾһ��
	virtual int perPageCount();
	///��������ģ����ʾ����
	virtual QVariant dataShow(const QModelIndex &index) const;
	///Ҫ��ʾ���ݵ��ܴ�С
	virtual int dataSize();

private:
	QList<EffectTestData> m_data;
};

#endif // DETESTINFORMODEL_H
