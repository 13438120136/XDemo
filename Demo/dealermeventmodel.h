#ifndef DEALERMEVENTMODEL_H
#define DEALERMEVENTMODEL_H

#include <detablemodel.h>

struct AlermEventData
{
	int orderNumber;		///序号
	int channel;			///污染通道
	quint64 time;			///污染时间

	AlermEventData(int orderNumber, int channel, quint64 time)
	{
		this->orderNumber = orderNumber;
		this->channel = channel;
		this->time = time;
	}
};

///报警事件数据模型
class DeAlermEventModel : public DeTableModel
{
	Q_OBJECT

public:
	DeAlermEventModel(QObject *parent);
	~DeAlermEventModel();

	void setData(const QList<AlermEventData> &data);

protected:
	///当前表格中每一页要显示的行数 默认只显示一行
	virtual int perPageCount();
	///根据数据模型显示内容
	virtual QVariant dataShow(const QModelIndex &index) const;
	///要显示数据的总大小
	virtual int dataSize();

private:
	QList<AlermEventData> m_data;
};

#endif // DEALERMEVENTMODEL_H
