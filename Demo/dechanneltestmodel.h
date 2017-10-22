#ifndef DECHANNELTESTMODEL_H
#define DECHANNELTESTMODEL_H

#include <detablemodel.h>
#include <QList>

struct ChannelData
{
	int alphaBeta;
	int alpha;
	int Beta;
};

///ͨ�����Եı��ģ��
class DeChannelTestModel : public DeTableModel
{
	Q_OBJECT

public:
	DeChannelTestModel(QObject *parent = 0);
	~DeChannelTestModel();

	QList<ChannelData> &data();

protected:
	///��ǰ�����ÿһҳҪ��ʾ������ Ĭ��ֻ��ʾһ��
	virtual int perPageCount();
	///��������ģ����ʾ����
	virtual QVariant dataShow(const QModelIndex &index) const;
	///Ҫ��ʾ���ݵ��ܴ�С
	virtual int dataSize();
	
private:
	QList<ChannelData> m_data;
};

#endif // DECHANNELTESTMODEL_H
