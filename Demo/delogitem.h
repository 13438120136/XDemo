#ifndef DELOGITEM_H
#define DELOGITEM_H

#include "deloginterface.h"

///写文件的日志记录
class DeLogItem : public DeLogInterface
{
public:
	DeLogItem();
	~DeLogItem();

	///执行写日志的动作
	virtual void writeLog();
};

#endif // DELOGITEM_H
