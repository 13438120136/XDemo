#ifndef DELOGGER_H
#define DELOGGER_H

#include "deloginterface.h"
#include <qlist.h>
#include <QThread>
#include <QSemaphore>
#include <QMutex>

class LogThread : public QThread
{
protected:
	virtual void run();
};

///全局日志类
class DeLogger
{
public:
	DeLogger();
	~DeLogger();

	///获取日志对象
	static DeLogger *instance();
	///写日志
	void writeLogger(DeLogInterface *);
	///退出
	void quit();
	///执行具体的写日志操作
	bool execute();

private:
	static DeLogger m_logger;
	QList<DeLogInterface *> m_logItemList; 
	LogThread m_thread;
	QSemaphore m_semaphore;
	QMutex m_mutex;
	bool m_isExit;
};

#endif // DELOGGER_H
