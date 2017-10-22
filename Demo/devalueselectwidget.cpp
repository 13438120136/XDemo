#include "devalueselectwidget.h"

//----------------------------------------------------------------------------
DeValueSelectWidget::DeValueSelectWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	m_index = 0;

	if (m_valueList.isEmpty())
		ui.label->clear();
	else
		ui.label->setText(QString::number(m_valueList.first()));
}
//----------------------------------------------------------------------------
DeValueSelectWidget::~DeValueSelectWidget()
{

}
//----------------------------------------------------------------------------
void DeValueSelectWidget::on_prevBtn_clicked()
{
	if (m_index == 0)
		return ;

	m_index--;
	ui.label->setText(QString::number(m_valueList[m_index]));

	emit signalValueChanged(m_valueList[m_index]);
}
//----------------------------------------------------------------------------
void DeValueSelectWidget::on_nextBtn_clicked()
{
	if (m_valueList.isEmpty())
		return ;

	if (m_index == (m_valueList.count() - 1))
		return ;

	m_index++;
	ui.label->setText(QString::number(m_valueList[m_index]));

	emit signalValueChanged(m_valueList[m_index]);
}
//----------------------------------------------------------------------------
void DeValueSelectWidget::setValueList(const QList<int> &value)
{
	m_valueList = value;

	if (m_valueList.isEmpty())
		ui.label->clear();
	else
		ui.label->setText(QString::number(m_valueList.first()));
}
//----------------------------------------------------------------------------
int DeValueSelectWidget::getCurrentValue()
{
	return m_valueList[m_index];
}
//----------------------------------------------------------------------------