#include "detableview.h"

//----------------------------------------------------------------------------
DeTableView::DeTableView(QWidget *parent)
	: QWidget(parent)
	,m_model(NULL)
{
	ui.setupUi(this);
	ui.tableView->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
	ui.tableView->verticalHeader()->setDefaultSectionSize(30);
}
//----------------------------------------------------------------------------
DeTableView::~DeTableView()
{

}
//----------------------------------------------------------------------------
void DeTableView::setModel(DeTableModel *model)
{
	m_model = model;
	m_model->initColumnCount();
	setPageMessage(m_model->pageMessage());
	ui.tableView->setModel(m_model);
	ui.tableView->update();
}
//----------------------------------------------------------------------------
QTableView *DeTableView::tableView()
{
	return ui.tableView;
}
//----------------------------------------------------------------------------
void DeTableView::on_firstBtn_clicked()
{
	m_model->tableToFirst();
	setPageMessage(m_model->pageMessage());
}
//----------------------------------------------------------------------------
void DeTableView::on_prevBtn_clicked()
{
	m_model->tableToPrev();
	setPageMessage(m_model->pageMessage());
}
//----------------------------------------------------------------------------
void DeTableView::on_nextBtn_clicked()
{
	m_model->tableToNext();
	setPageMessage(m_model->pageMessage());
}
//----------------------------------------------------------------------------
void DeTableView::on_lastBtn_clicked()
{
	m_model->tableToLast();
	setPageMessage(m_model->pageMessage());
}
//----------------------------------------------------------------------------
void DeTableView::setPageMessage(const QString &msg)
{
	ui.label->setText(msg);
}
//----------------------------------------------------------------------------
void DeTableView::hideMenu()
{
	ui.widget->hide();
}
//----------------------------------------------------------------------------
void DeTableView::hideFirstAndLastBtn()
{
	ui.firstBtn->hide();
	ui.lastBtn->hide();
}
//----------------------------------------------------------------------------