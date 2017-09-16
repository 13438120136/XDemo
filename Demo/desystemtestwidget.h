#ifndef DESYSTEMTESTWIDGET_H
#define DESYSTEMTESTWIDGET_H

#include <QDialog>
#include "ui_desystemtestwidget.h"
#include <QBitArray>

class DeSystemTestWidget : public QDialog
{
	Q_OBJECT

public:
	DeSystemTestWidget(QWidget *parent = 0);
	~DeSystemTestWidget();

	/* ����IOͨ�����Խ��״̬
	 *
	 * ����λ��: 0 - ��Ա����
	 *			 1 - �Ų�ѹ��
	 *			 2 - ����̽����
	 * 			 3 - ���ֺ���
	 *			 4 - ���ֺ���
	 *
	 *  ֵΪ:1ͨ�� 0��ͨ��
	 */
	void setIOTestReulst(const QBitArray &value);

public Q_SLOTS:
	void slotPhysicalTest(bool);
	void on_ioBtn_clicked();
	void on_channelBtn_clicked();
	void on_xiaolvBtn_clicked();
	void on_funcBtn_clicked();
	void on_logoutBtn_clicked();

	//����IOͨ������
	void on_ioTestBtn_clicked();

protected:
	virtual bool eventFilter(QObject *obj, QEvent *event);

private:
	Ui::DeSystemTestWidget ui;
	QBitArray m_stateBitArray;
	bool m_isIOTest;
};

#endif // DESYSTEMTESTWIDGET_H
