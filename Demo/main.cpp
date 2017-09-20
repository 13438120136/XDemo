#include <QtGui/QApplication>
#include <QTranslator>
#include <QTextCodec>
#include "destatemachine.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("gb2312"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("gb2312"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("gb2312"));

	///º”‘ÿ”Ô—‘∞¸
	QTranslator translator;
    translator.load(":/Demo/demo_zh.qm");
	a.installTranslator(&translator);

	Demo demo;
	demo.setTranlator(&translator);
	demo.setFixedSize(640, 480);
	demo.show();

	//DeStateMachine stateMachine;
	//stateMachine.start();
	return a.exec();
}
