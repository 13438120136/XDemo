#ifndef DEUSERLISTMODEL_H
#define DEUSERLISTMODEL_H

#include <detablemodel.h>
#include <deusertable.h>

///�û��б�����ģ��
class DeUserListModel : public DeTableModel
{
	Q_OBJECT

public:
	DeUserListModel(QObject *parent);
	~DeUserListModel();

	void setData(const QList<DeUserTable> &data);
	QList<DeUserTable> &data();

protected:
	///��ǰ�����ÿһҳҪ��ʾ������ Ĭ��ֻ��ʾһ��
	virtual int perPageCount();
	///��������ģ����ʾ����
	virtual QVariant dataShow(const QModelIndex &index) const;
	///Ҫ��ʾ���ݵ��ܴ�С
	virtual int dataSize();
	Qt::ItemFlags flags(const QModelIndex &index) const;

private:
	QList<DeUserTable> m_userData;
};

#endif // DEUSERLISTMODEL_H
