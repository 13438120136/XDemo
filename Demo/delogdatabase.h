#ifndef DELOGDATABASE_H
#define DELOGDATABASE_H

#include <deloginterface.h>

///д���ݿ����־
class DeLogDataBase : public DeLogInterface
{
public:
	DeLogDataBase();
	~DeLogDataBase();
	virtual void writeLog();
};

#endif // DELOGDATABASE_H
