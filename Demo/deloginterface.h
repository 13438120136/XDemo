#ifndef DELOGINTERFACE_H
#define DELOGINTERFACE_H

/*
 * 日志记录接口类
 */
class DeLogInterface
{
public:
	DeLogInterface();
	~DeLogInterface();

	virtual void writeLog() = 0;
};

#endif // DELOGINTERFACE_H
