#ifndef DECHANNELTESTMODEL_H
#define DECHANNELTESTMODEL_H

#include <detablemodel.h>

///ͨ�����Եı��ģ��
class DeChannelTestModel : public DeTableModel
{
	Q_OBJECT

public:
	DeChannelTestModel(QObject *parent = 0);
	~DeChannelTestModel();

protected:
	///��ǰ�����ÿһҳҪ��ʾ������ Ĭ��ֻ��ʾһ��
	virtual int perPageCount();
	///��������ģ����ʾ����
	virtual QVariant dataShow(const QModelIndex &index) const;
	///Ҫ��ʾ���ݵ��ܴ�С
	virtual int dataSize();
	
};

#endif // DECHANNELTESTMODEL_H
