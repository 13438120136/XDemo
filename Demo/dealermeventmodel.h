#ifndef DEALERMEVENTMODEL_H
#define DEALERMEVENTMODEL_H

#include <detablemodel.h>
#include <dealermtable.h>

///�����¼�����ģ��
class DeAlermEventModel : public DeTableModel
{
	Q_OBJECT

public:
	DeAlermEventModel(QObject *parent);
	~DeAlermEventModel();

	void setData(const QList<DeAlermTable> &data);
	QList<DeAlermTable> &getData();

protected:
	///��ǰ�����ÿһҳҪ��ʾ������ Ĭ��ֻ��ʾһ��
	virtual int perPageCount();
	///��������ģ����ʾ����
	virtual QVariant dataShow(const QModelIndex &index) const;
	///Ҫ��ʾ���ݵ��ܴ�С
	virtual int dataSize();
	Qt::ItemFlags flags(const QModelIndex &index) const;

private:
	QList<DeAlermTable> m_data;
};

#endif // DEALERMEVENTMODEL_H
