#ifndef DECOMMONDEF_H
#define DECOMMONDEF_H

#include "common_def.h"

enum COMM_WITH_TYPE
{
    TYPE_DEVICE_STATUS = 1,   //DeviceStatus
	TYPE_PALMCHECKING,		  ///手心检测
	TYPE_DORSUMCHECKING,	  ///手背检测
	TYPE_PALMCONTAMINATED,	  ///手心污染
	TYPE_DORSUMCONTAMINATED,  ///手背污染
	TYPE_PALMNOCONTAMINATED,  ///手心未污染
	TYPE_DORSUMNOCONTAMINATED,///手背未污染
	TYPE_KEYMEASURING,		  ///关键部位测量
	TYPE_KEYCONTAMINATED,     ///重点部位污染
	TYPE_KEYNOCONTAMINATED,	  ///重点部位未污染
	TYPE_POSITIONERROR,	      ///位置错误 
    //todo_1 -- Add enum type here ...
    //...

    //end todo_1
};

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

struct AlphaAndBeta
{
	int alpha[4];
	int beta[4];
};

struct KeyAlphaAndBeta
{
	int alpha;
	int beta;
};

#endif
