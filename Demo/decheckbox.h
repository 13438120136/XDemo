#ifndef DECHECKBOX_H
#define DECHECKBOX_H

#include <QWidget>
#include "ui_decheckbox.h"

class DeCheckBox : public QWidget
{
	Q_OBJECT

public:
	DeCheckBox(QWidget *parent = 0);
	~DeCheckBox();
	void setInitValue(const QString &text, bool checked);
	void setText(const QString &text);
	void setChecked(bool check);
	QString text();
	bool checked();

	void setReadOnly();

Q_SIGNALS:
	void signalCheckedChanged(bool checked);

protected:
	bool eventFilter(QObject *obj, QEvent *event);

private:
	Ui::DeCheckBox ui;
	bool m_isEnabled;
	bool m_isReadOnly;
};

#endif // DECHECKBOX_H
