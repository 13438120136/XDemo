#ifndef DECOMMONDEF_H
#define DECOMMONDEF_H

///设备自检发生故障结构体表示
struct DeviceStatus
{
	/*
	 * 0: 未知
	 * 1: 打开
	 * 2: 关闭
	 */
	int ultrasonic;

	///所有布尔型都表示true为正常 false异常
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
