#include "delogger.h"
#include "deloginterface.h"
#include <qeventloop.h>

DeLogger DeLogger::m_logger;

//----------------------------------------------------------------------------
void LogThread::run()
{	
	for (;;)
	{
		DeLogger *logger = DeLogger::instance();
		if (logger->execute())
			break;
	}
}
//----------------------------------------------------------------------------
DeLogger::DeLogger()
{
	m_isExit = false;
	m_thread.start();
}
//----------------------------------------------------------------------------
DeLogger::~DeLogger()
{
	quit();
}
//----------------------------------------------------------------------------
DeLogger *DeLogger::instance()
{
	return &m_logger;
}
//----------------------------------------------------------------------------
void DeLogger::writeLogger(DeLogInterface *obj)
{
	m_semaphore.release();
	m_mutex.lock();
	m_logItemList.append(obj);
	m_mutex.unlock();
}
//----------------------------------------------------------------------------
void DeLogger::quit()
{
	m_isExit = true;
	m_semaphore.release();
	m_thread.wait();
}
//----------------------------------------------------------------------------
bool DeLogger::execute()
{
	m_semaphore.acquire();

	m_mutex.lock();
	int nCount = m_logItemList.count();
	for (int i = 0; i < nCount; i++)
		m_logItemList[i]->writeLog();
	qDeleteAll(m_logItemList);
	m_mutex.unlock();

	return m_isExit;
}
//----------------------------------------------------------------------------