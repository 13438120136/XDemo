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
		int testCount;				///��������
		int highTop;				///��ѹ����
		int highBottom;				///��ѹ����
		int highInterval;			///��ѹ����
		int thresholdTop;			///��ֵ����
		int thresholdBottom;		///��ֵ����
		int thresholdInterval;		///��ֵ����

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

	///��ʼ��������ʾ
	void initWidget();

	///��ʾ���ñ���Դ�Ի���
	void showBValueDialog();

public Q_SLOTS:
	void slotPhysicalTest(bool);
	void on_ioBtn_clicked();
	void on_channelBtn_clicked();
	void on_xiaolvBtn_clicked();
	void on_funcBtn_clicked();
	void on_logoutBtn_clicked();
	void on_effectSaveBtn_clicked();

	//����IOͨ������
	void on_ioTestBtn_clicked();
	///����ͨ�����԰�ť
	void on_channelTestBtn_clicked();
	void slotChannelValueChanged(int value);
	void setChannelParam(int highValue, int value, int coefficient1, int coefficient2);
	void slotChannelResult(ChannelResultData);
	void slotEffectResult(EffectResultData);
	///Ч�ʱ궨��ť
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
