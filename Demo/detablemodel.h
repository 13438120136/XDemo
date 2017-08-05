#ifndef DETABLEMODEL_H
#define DETABLEMODEL_H

#include <QStandardItemModel>

class DeTableModel : public QStandardItemModel
{
	Q_OBJECT

public:
	DeTableModel(QObject *parent);
	~DeTableModel();

	///�л�����һҳ����
	void tableToFirst();
	///�л������һҳ����
	void tableToLast();
	///�л�����һҳ����
	void tableToPrev();
	///�л�����һҳ����
	void tableToNext();
	///��ҳ�ַ�����Ϣ
	QString pageMessage();
	///��ʼ��ҳ������
	void initColumnCount();

protected:
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
	Qt::ItemFlags flags(const QModelIndex &index) const;
	///��ǰ�����ÿһҳҪ��ʾ������ Ĭ��ֻ��ʾһ��
	virtual int perPageCount();
	///��������ģ����ʾ����
	virtual QVariant dataShow(const QModelIndex &index) const;
	///Ҫ��ʾ���ݵ��ܴ�С
	virtual int dataSize();
	///��ǰ����
	int indexData() const;

private:
	int m_index;
};

#endif // DETABLEMODEL_H
