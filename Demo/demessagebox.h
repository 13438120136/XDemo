#ifndef DEMESSAGEBOX_H
#define DEMESSAGEBOX_H

#include <QMessageBox>

class DeMessageBox : public QMessageBox
{
	Q_OBJECT

public:
	DeMessageBox(QWidget *parent = 0);
	~DeMessageBox();

protected:
    void resizeEvent(QResizeEvent *event);
	
};

#endif // DEMESSAGEBOX_H
