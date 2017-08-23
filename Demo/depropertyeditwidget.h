#ifndef DEPROPERTYEDITWIDGET_H
#define DEPROPERTYEDITWIDGET_H

#include <QDialog>
#include "ui_depropertyeditwidget.h"

class DeSystemConfigWidget;
class DePropertyEditWidget : public QDialog
{
	Q_OBJECT

public:
	DePropertyEditWidget(QWidget *parent = 0);
	~DePropertyEditWidget();

	void setSystemConfigWidget(DeSystemConfigWidget *widget);
	void setHeadTitle(const QString &title);
	void setContentText(const QString &text);

public Q_SLOTS:
	void on_btnOk_clicked();
	void on_btnCancel_clicked();

protected:
	bool eventFilter(QObject *obj, QEvent *event);

private:
	Ui::DePropertyEditWidget ui;
	DeSystemConfigWidget *m_systemConfigWidget;
};

#endif // DEPROPERTYEDITWIDGET_H
