#ifndef DELOGDATABASE_H
#define DELOGDATABASE_H

#include <deloginterface.h>

///写数据库表日志
class DeLogDataBase : public DeLogInterface
{
public:
	DeLogDataBase();
	~DeLogDataBase();
	virtual void writeLog();
};

#endif // DELOGDATABASE_H
