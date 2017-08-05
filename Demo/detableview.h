#ifndef DETABLEVIEW_H
#define DETABLEVIEW_H

#include <QWidget>
#include "ui_detableview.h"
#include "detablemodel.h"

class DeTableView : public QWidget
{
	Q_OBJECT

public:
	DeTableView(QWidget *parent = 0);
	~DeTableView();

	///���ص�ǰ������
	QTableView *tableView();
	///����ģ�Ͷ���
	void setModel(DeTableModel *model);
	///���÷�ҳ��Ϣ
	void setPageMessage(const QString &msg);

public Q_SLOTS:
	void on_firstBtn_clicked();
	void on_prevBtn_clicked();
	void on_nextBtn_clicked();
	void on_lastBtn_clicked();

private:
	Ui::DeTableView ui;
	DeTableModel *m_model;
};

#endif // DETABLEVIEW_H
