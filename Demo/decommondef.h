#ifndef DECOMMONDEF_H
#define DECOMMONDEF_H

///�豸�Լ췢�����Ͻṹ���ʾ
struct DeviceStatus
{
	/*
	 * 0: δ֪
	 * 1: ��
	 * 2: �ر�
	 */
	int ultrasonic;

	///���в����Ͷ���ʾtrueΪ���� false�쳣
	bool ioLeft;
	bool ioRight;
	bool preLeft;
	bool preRight;

	bool can_1;
	bool can_2;
	bool can_3;
	bool can_4;
};

#endif
