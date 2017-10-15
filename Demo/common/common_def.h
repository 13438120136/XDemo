/*************************************************************************
	> File Name: common_def.h
	> Author: 
	> Mail: 
	> Created Time: Mon 11 Sep 2017 05:39:08 PM CST
 ************************************************************************/

#ifndef _COMMON_DEF_H
#define _COMMON_DEF_H


#define _more_sampler_ 0


///探测器和通道的个数
#define SAMPLER_NUMBER 4
#define CHANNEL_NUMBER 2

///广播的地址
#define BROAD_CAST_ADDR 0xFF

///探测器地址
#define SAMPLER_1_ADDR 0x01
#define SAMPLER_2_ADDR 0x02
#define SAMPLER_3_ADDR 0x03
#define SAMPLER_4_ADDR 0x04
#define SAMPLER_5_ADDR 0x05
#define SAMPLER_6_ADDR 0x06
#define SAMPLER_7_ADDR 0x07
#define SAMPLER_8_ADDR 0x08

///错误码
#define ERROR_COMM_TIMEOUT 0x10
#define ERROR_COMM_SELECT 0x11

///类型
#define HIGHER_VALUE 0x20
#define LOWER_VALUE 0x21
#define ABOVE_NORMAL 0x22
#define ABOVE_SENSITIVE 0x23

///错误码构造宏
#define MAKE_RETCODE(ret,x,y,z) {ret |= x << 16; ret |= y << 8; ret |= z; ret |= 0xFFFFFFFF;}

///具体错误
#define ERROR_LOWER_THRESHOLD(ret,ADDR,CH,LOWER_VALUE) MAKE_RETCODE(ret, ADDR, CH, 1)
#define ERROR_HIGHER_THRESHOLD(ret,ADDR,CH,HIGHER_VALUE) MAKE_RETCODE(ret, ADDR, CH, 2)
#define ERROR_NORMAL_ALARMING(ret,ADDR,CH,ABOVE_NORMAL) MAKE_RETCODE(ret, ADDR, CH, 3)
#define ERROR_SENSIVE_ALARMING(ret,ADDR,CH,ABOVE_SENSITIVE) MAKE_RETCODE(ret, ADDR, CH, 4)

#define GET_UI_AND_SET(device, block) \
    {\
        DeviceStatus& device = m_demo->slotGetCurrentDeviceFault();\
        block;\
        m_demo->slotDeviceFault(device);\
    }\

#define MEMBER(x,y) \
    private: \
        x y; \
    public: \
        x& get_##x(){return y;}\

#endif
