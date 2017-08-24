#include <QtGui/QApplication>
#include "deloginwidget.h"
#include "destatemachine.h"
#include "deusertable.h"
#include "desqldatabase.h"
#include <QTranslator>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	///º”‘ÿ”Ô—‘∞¸
	QTranslator translator;
	translator.load(":/Demo/demo_en.qm");
	a.installTranslator(&translator);

	Demo demo;
	demo.setFixedSize(640, 480);
	demo.show();

	DeStateMachine stateMachine;
	stateMachine.start();
	return a.exec();
}
