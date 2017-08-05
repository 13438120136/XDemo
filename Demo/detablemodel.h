#ifndef DETABLEMODEL_H
#define DETABLEMODEL_H

#include <QStandardItemModel>

class DeTableModel : public QStandardItemModel
{
	Q_OBJECT

public:
	DeTableModel(QObject *parent);
	~DeTableModel();

	///切换到第一页数据
	void tableToFirst();
	///切换到最后一页数据
	void tableToLast();
	///切换到上一页数据
	void tableToPrev();
	///切换到下一页数据
	void tableToNext();
	///翻页字符串信息
	QString pageMessage();
	///初始化页面行数
	void initColumnCount();

protected:
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
	Qt::ItemFlags flags(const QModelIndex &index) const;
	///当前表格中每一页要显示的行数 默认只显示一行
	virtual int perPageCount();
	///根据数据模型显示内容
	virtual QVariant dataShow(const QModelIndex &index) const;
	///要显示数据的总大小
	virtual int dataSize();
	///当前索引
	int indexData() const;

private:
	int m_index;
};

#endif // DETABLEMODEL_H
