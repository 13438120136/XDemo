#include "devirtualkeyboradwidget.h"
#include <qpushbutton.h>
#include "demo.h"

Q_DECLARE_METATYPE(Demo *)
DeVirtualKeyboradWidget::DeVirtualKeyboradWidget(QWidget *parent)
	: QWidget(parent)
	,m_lineEdit(NULL)
{
	Demo *demo = qApp->property("_mainWin").value<Demo *>();
	demo->execTranslator();

	ui.setupUi(this);
	initAllKeyEvent();
}

DeVirtualKeyboradWidget::~DeVirtualKeyboradWidget()
{

}

void DeVirtualKeyboradWidget::initAllKeyEvent()
{
	m_signalMapper = new QSignalMapper(this);

	QList<QAbstractButton *> listButtons = ui.charButtonGroup->buttons();
	int nCount = listButtons.size();
	for (int i = 0; i < nCount; i++)
	{
		QPushButton *button = (QPushButton *)listButtons[i];
		connect(button, SIGNAL(clicked()), m_signalMapper, SLOT(map()));
		m_signalMapper->setMapping(button, button);
	}

	QList<QAbstractButton *> numlistButtons = ui.numButtonGroup->buttons();
	int numCount = numlistButtons.size();
	for (int i = 0; i < numCount; i++)
	{
		QPushButton *button = (QPushButton *)numlistButtons[i];
		connect(button, SIGNAL(clicked()), m_signalMapper, SLOT(map()));
		m_signalMapper->setMapping(button, button);
	}

	connect(m_signalMapper, SIGNAL(mapped(QWidget *)),
             this, SLOT(virtualKeyPressEvent(QWidget *)));
}

void DeVirtualKeyboradWidget::virtualKeyPressEvent(QWidget *button)
{
	if (m_lineEdit == NULL)
		return ;

	QPushButton *pButton = (QPushButton *)button;
	m_lineEdit->insert(pButton->text());
	m_lineEdit->setFocus();
}

void DeVirtualKeyboradWidget::on_spaceBtn_clicked()
{
	if (m_lineEdit == NULL)
		return ;

	m_lineEdit->insert(" ");
	m_lineEdit->setFocus();
}

void DeVirtualKeyboradWidget::on_backBtn_clicked()
{
	if (m_lineEdit == NULL)
		return ;

	m_lineEdit->backspace();
	m_lineEdit->setFocus();
}

void DeVirtualKeyboradWidget::setEditControl(QLineEdit *lineEdit)
{
	m_lineEdit = lineEdit;
}

void DeVirtualKeyboradWidget::on_shiftBtn_clicked()
{
	QList<QAbstractButton *> listButtons = ui.charButtonGroup->buttons();
	int nCount = listButtons.size();
	for (int i = 0; i < nCount; i++)
	{
		QPushButton *button = (QPushButton *)listButtons[i];
		QString text = button->text();
		if (text == text.toUpper())
			button->setText(text.toLower());
		else
			button->setText(text.toUpper());
	}
}

void DeVirtualKeyboradWidget::on_hideBtn_clicked()
{
	hide();
}