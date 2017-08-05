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

	///返回当前表格对象
	QTableView *tableView();
	///设置模型对象
	void setModel(DeTableModel *model);
	///设置翻页信息
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
