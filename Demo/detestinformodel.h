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
	///��ǰ�����ÿһҳҪ��ʾ������ Ĭ��ֻ��ʾһ��
	virtual int perPageCount();
	///��������ģ����ʾ����
	virtual QVariant dataShow(const QModelIndex &index) const;
	///Ҫ��ʾ���ݵ��ܴ�С
	virtual int dataSize();
	
};

#endif // DETESTINFORMODEL_H
