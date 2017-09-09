#ifndef DEALERMEVENTMODEL_H
#define DEALERMEVENTMODEL_H

#include <detablemodel.h>

struct AlermEventData
{
	int orderNumber;		///���
	int channel;			///��Ⱦͨ��
	quint64 time;			///��Ⱦʱ��

	AlermEventData(int orderNumber, int channel, quint64 time)
	{
		this->orderNumber = orderNumber;
		this->channel = channel;
		this->time = time;
	}
};

///�����¼�����ģ��
class DeAlermEventModel : public DeTableModel
{
	Q_OBJECT

public:
	DeAlermEventModel(QObject *parent);
	~DeAlermEventModel();

	void setData(const QList<AlermEventData> &data);

protected:
	///��ǰ�����ÿһҳҪ��ʾ������ Ĭ��ֻ��ʾһ��
	virtual int perPageCount();
	///��������ģ����ʾ����
	virtual QVariant dataShow(const QModelIndex &index) const;
	///Ҫ��ʾ���ݵ��ܴ�С
	virtual int dataSize();
	Qt::ItemFlags flags(const QModelIndex &index) const;

private:
	QList<AlermEventData> m_data;
};

#endif // DEALERMEVENTMODEL_H
