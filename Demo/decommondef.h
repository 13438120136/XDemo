#ifndef DECOMMONDEF_H
#define DECOMMONDEF_H

#include "common_def.h"

enum COMM_WITH_TYPE
{
    TYPE_DEVICE_STATUS = 1,   //DeviceStatus
	TYPE_DEVICESELFCHECK,     //�����Լ�����
	TYPE_CHECKING,            //���ؼ����
	TYPE_PLEASELEAVE,         ///���뿪�������
	TYPE_READY,				  ///׼������
	TYPE_FLIPPALM, 			  ///�뷴ת����
	TYPE_PALMCHECKING,		  ///���ļ��
	TYPE_DORSUMCHECKING,	  ///�ֱ����
	TYPE_PALMCONTAMINATED,	  ///������Ⱦ
	TYPE_DORSUMCONTAMINATED,  ///�ֱ���Ⱦ
	TYPE_PALMNOCONTAMINATED,  ///����δ��Ⱦ
	TYPE_DORSUMNOCONTAMINATED,///�ֱ�δ��Ⱦ
	TYPE_KEYMEASURING,		  ///�ؼ���λ����
	TYPE_KEYCONTAMINATED,     ///�ص㲿λ��Ⱦ
	TYPE_KEYNOCONTAMINATED,	  ///�ص㲿λδ��Ⱦ
	TYPE_POSITIONERROR,	      ///λ�ô��� 
    //todo_1 -- Add enum type here ...
    //...

    //end todo_1
};

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

///alpha��beta��ֵ ͨ���Ƿ���Ⱦ״̬
struct AlphaAndBeta
{
	int abValue[4][2];    ///alpha��beta��ֵ
	int channelContaminatedStatus[4];  ///0-δ��Ⱦ ����-��Ⱦ
};

struct KeyAlphaAndBeta
{
	int alpha;
	int beta;
	int contaminatedStatus; ///0-δ��Ⱦ ����-��Ⱦ
};

#endif
