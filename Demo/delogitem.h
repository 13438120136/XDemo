#ifndef DELOGITEM_H
#define DELOGITEM_H

#include "deloginterface.h"

///д�ļ�����־��¼
class DeLogItem : public DeLogInterface
{
public:
	DeLogItem();
	~DeLogItem();

	///ִ��д��־�Ķ���
	virtual void writeLog();
};

#endif // DELOGITEM_H
