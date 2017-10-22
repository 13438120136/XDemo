#include "delogowidget.h"

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
	m_movie = new QMovie(":/Demo/Resources/xitongceshi-jinxingzhong.gif");
	ui.label_4->setMovie(m_movie);
	m_movie->setScaledSize(QSize(40, 40));
	m_movie->setSpeed(200);
	m_movie->start();
}
//----------------------------------------------------------------------------
void DelogoWidget::hideEvent(QHideEvent *)
{
	m_movie->stop();
}
//----------------------------------------------------------------------------