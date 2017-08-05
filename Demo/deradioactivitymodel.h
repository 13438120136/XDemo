#ifndef DERADIOACTIVITYMODEL_H
#define DERADIOACTIVITYMODEL_H

#include <detablemodel.h>
#include "deradioactivesourcetable.h"

///�����Թ�������ģ��
class DeRadioactivityModel : public DeTableModel
{
	Q_OBJECT

public:
	DeRadioactivityModel(QObject *parent = 0);
	~DeRadioactivityModel();

	void setData(const QList<DeRadioactiveSourceTable> &data);
	QList<DeRadioactiveSourceTable> &data();

protected:
	///��ǰ�����ÿһҳҪ��ʾ������ Ĭ��ֻ��ʾһ��
	virtual int perPageCount();
	///��������ģ����ʾ����
	virtual QVariant dataShow(const QModelIndex &index) const;
	///Ҫ��ʾ���ݵ��ܴ�С
	virtual int dataSize();

private:
	QList<DeRadioactiveSourceTable> m_data;
};

#endif // DERADIOACTIVITYMODEL_H
