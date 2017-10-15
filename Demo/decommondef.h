#ifndef DECOMMONDEF_H
#define DECOMMONDEF_H

#include "common_def.h"

enum COMM_WITH_TYPE
{
    TYPE_DEVICE_STATUS = 1,   //DeviceStatus
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
