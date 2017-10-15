#ifndef DECOMMONDEF_H
#define DECOMMONDEF_H

#include "common_def.h"

enum COMM_WITH_TYPE
{
    TYPE_DEVICE_STATUS = 1,   //DeviceStatus
	TYPE_DEVICESELFCHECK,     //本地自检测界面
	TYPE_CHECKING,            //本地检测中
	TYPE_PLEASELEAVE,         ///请离开检测区域
	TYPE_READY,				  ///准备就绪
	TYPE_FLIPPALM, 			  ///请反转手掌
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

///alpha和beta的值 通道是否污染状态
struct AlphaAndBeta
{
	int abValue[4][2];    ///alpha和beta的值
	int channelContaminatedStatus[4];  ///0-未污染 否则-污染
};

struct KeyAlphaAndBeta
{
	int alpha;
	int beta;
	int contaminatedStatus; ///0-未污染 否则-污染
};

#endif
