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

///ȫ����־��
class DeLogger
{
public:
	DeLogger();
	~DeLogger();

	///��ȡ��־����
	static DeLogger *instance();
	///д��־
	void writeLogger(DeLogInterface *);
	///�˳�
	void quit();
	///ִ�о����д��־����
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
