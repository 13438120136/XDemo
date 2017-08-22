#include <QtGui/QApplication>
#include "deloginwidget.h"
#include "destatemachine.h"
#include "deusertable.h"
#include "desqldatabase.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Demo demo;
	demo.setFixedSize(640, 480);
	demo.show();

	DeStateMachine stateMachine;
	stateMachine.start();
	return a.exec();
}
