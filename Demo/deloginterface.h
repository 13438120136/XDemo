#ifndef DELOGINTERFACE_H
#define DELOGINTERFACE_H

/*
 * ��־��¼�ӿ���
 */
class DeLogInterface
{
public:
	DeLogInterface();
	~DeLogInterface();

	virtual void writeLog() = 0;
};

#endif // DELOGINTERFACE_H
