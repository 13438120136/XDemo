#include "decombobox.h"

//----------------------------------------------------------------------------
DeComboBox::DeComboBox(QWidget *parent)
	: QWidget(parent)
	,m_index(0)
{
	ui.setupUi(this);
}
//----------------------------------------------------------------------------
DeComboBox::~DeComboBox()
{

}
//----------------------------------------------------------------------------
void DeComboBox::on_addBtn_clicked()
{
	int nCount = m_index + 1;

	if (nCount > m_data.count() - 1)
		return ;

	ui.lineEdit->setText(m_data[nCount]);
	m_index++;
}
//----------------------------------------------------------------------------
void DeComboBox::on_subBtn_clicked()
{
	int nCount = m_index - 1;

	if (nCount < 0)
		return ;

	ui.lineEdit->setText(m_data[nCount]);
	m_index--;
}
//----------------------------------------------------------------------------
void DeComboBox::addItem(const QString &item)
{
	m_data.append(item);
	ui.lineEdit->setText(m_data.first());
}
//----------------------------------------------------------------------------
int DeComboBox::currentIndex()
{
	return m_index;
}
//----------------------------------------------------------------------------
void DeComboBox::setCurrentIndex(int index)
{
	int max = m_data.count();
	if (index < 0 || index >= max)
		return ;

	m_index = index;
	ui.lineEdit->setText(m_data[m_index]);
}
//----------------------------------------------------------------------------