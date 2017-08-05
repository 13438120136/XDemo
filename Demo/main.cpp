#include <QtGui/QApplication>
#include "deloginwidget.h"
#include "destatemachine.h"
#include <QMetaMethod>
#include "deusertable.h"
#include "desqldatabase.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Demo demo;
	demo.showFullScreen();

	DeStateMachine stateMachine;
	stateMachine.start();
	return a.exec();
}
