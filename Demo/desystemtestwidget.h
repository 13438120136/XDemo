#ifndef DESYSTEMTESTWIDGET_H
#define DESYSTEMTESTWIDGET_H

#include "ui_desystemtestwidget.h"
#include "deinputdelegate.h"
#include "demo.h"
#include <QBitArray>
#include <QDialog>

class DeChannelTestModel;
class DeTestInforModel;
class DeSystemTestWidget : public QDialog
{
	Q_OBJECT

	struct EffectParam
	{
		int testCount;				///测量次数
		int highTop;				///高压上限
		int highBottom;				///高压下限
		int highInterval;			///高压步进
		int thresholdTop;			///阈值上限
		int thresholdBottom;		///阈值下限
		int thresholdInterval;		///阈值步进

		EffectParam()
		{
			testCount = 10;
			highTop = 1000;
			highBottom = 800;
			highInterval = 100;
			thresholdTop = 2000;
			thresholdBottom = 1500;
			thresholdInterval = 100;
		}
	};

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

	///初始化界面显示
	void initWidget();

	///显示放置本底源对话框
	void showBValueDialog();

public Q_SLOTS:
	void slotPhysicalTest(bool);
	void on_ioBtn_clicked();
	void on_channelBtn_clicked();
	void on_xiaolvBtn_clicked();
	void on_funcBtn_clicked();
	void on_logoutBtn_clicked();
	void on_effectSaveBtn_clicked();

	//单击IO通道测试
	void on_ioTestBtn_clicked();
	///单击通道测试按钮
	void on_channelTestBtn_clicked();
	void slotChannelValueChanged(int value);
	void setChannelParam(int highValue, int value, int coefficient1, int coefficient2);
	void slotChannelResult(ChannelResultData);
	void slotEffectResult(EffectResultData);
	///效率标定按钮
	void on_xiaolvTestBtn_clicked();
	void slotEffectValueChanged(int value);
	void slotEffectSelectChannel();

private:
	Ui::DeSystemTestWidget ui;
	QBitArray m_stateBitArray;
	bool m_isIOTest;
	DeIntDelegate m_tIntDelegate;

	DeChannelTestModel *m_channelMode;
	DeTestInforModel *m_effectMode;
	EffectParam m_effectParam[4];
};

#endif // DESYSTEMTESTWIDGET_H
