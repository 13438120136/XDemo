#include "delogowidget.h"
#include <QMovie>

//----------------------------------------------------------------------------
DelogoWidget::DelogoWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	playGif();
}
//----------------------------------------------------------------------------
DelogoWidget::~DelogoWidget()
{

}
//----------------------------------------------------------------------------
void DelogoWidget::playGif()
{
	QMovie *movie = new QMovie(":/Demo/Resources/xitongceshi-jinxingzhong.gif");
	ui.label_4->setMovie(movie);
	movie->setScaledSize(QSize(40, 40));
	movie->setSpeed(400);
	movie->start();
}
//----------------------------------------------------------------------------