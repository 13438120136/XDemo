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

	/* 设置IO通道测试结果状态
	 *
	 * 按照位数: 0 - 人员靠近
	 *			 1 - 脚步压力
	 *			 2 - 右手探测器
	 * 			 3 - 左手红外
	 *			 4 - 右手红外
	 *
	 *  值为:1通过 0不通过
	 */
	void setIOTestReulst(const QBitArray &value);

public Q_SLOTS:
	void slotPhysicalTest(bool);
	void on_ioBtn_clicked();
	void on_channelBtn_clicked();
	void on_xiaolvBtn_clicked();
	void on_funcBtn_clicked();
	void on_logoutBtn_clicked();

	//单击IO通道测试
	void on_ioTestBtn_clicked();

protected:
	virtual bool eventFilter(QObject *obj, QEvent *event);

private:
	Ui::DeSystemTestWidget ui;
	QBitArray m_stateBitArray;
	bool m_isIOTest;
};

#endif // DESYSTEMTESTWIDGET_H
