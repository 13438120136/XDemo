#ifndef DEDETECTORMODEL_H
#define DEDETECTORMODEL_H

#include <detablemodel.h>

///̽�������ģ��
class DeDetectorModel : public DeTableModel
{
	Q_OBJECT

public:
	DeDetectorModel(QObject *parent);
	~DeDetectorModel();

protected:
	///��ǰ�����ÿһҳҪ��ʾ������ Ĭ��ֻ��ʾһ��
	virtual int perPageCount();
	///��������ģ����ʾ����
	virtual QVariant dataShow(const QModelIndex &index) const;
	///Ҫ��ʾ���ݵ��ܴ�С
	virtual int dataSize();

private:
	
};

#endif // DEDETECTORMODEL_H
