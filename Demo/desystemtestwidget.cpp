#include "desystemtestwidget.h"
#include "dechanneltestmodel.h"
#include "detestinformodel.h"
#include "demo.h"
#include "demenuwidget.h"

Q_DECLARE_METATYPE(Demo *)
//----------------------------------------------------------------------------
DeSystemTestWidget::DeSystemTestWidget(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	this->setWindowFlags(Qt::ToolTip);
	ui.tabWidget->findChildren<QTabBar*>().at(0)->hide();

	DeChannelTestModel *model = new DeChannelTestModel(this);
	ui.widget_4->setModel(model);

	DeTestInforModel *inforModel = new DeTestInforModel(this);
	ui.widget_5->setModel(inforModel);

	connect(ui.physicalTest, SIGNAL(toggled(bool)), this, SLOT(slotPhysicalTest(bool)));
}
//----------------------------------------------------------------------------
DeSystemTestWidget::~DeSystemTestWidget()
{
	
}
//----------------------------------------------------------------------------
bool DeSystemTestWidget::eventFilter(QObject *obj, QEvent *event)
 {
	 if (event->type() == QEvent::MouseButtonRelease) 
	 {
         return true;
     }
	 else 
	 {
         // standard event processing
         return QObject::eventFilter(obj, event);
     }
 }
//----------------------------------------------------------------------------
void DeSystemTestWidget::slotPhysicalTest(bool enable)
{
	ui.groupBox_2->setEnabled(enable);
}
//----------------------------------------------------------------------------
void DeSystemTestWidget::on_ioBtn_clicked()
{
	ui.tabWidget->setCurrentIndex(0);
}
//----------------------------------------------------------------------------
void DeSystemTestWidget::on_channelBtn_clicked()
{
	ui.tabWidget->setCurrentIndex(1);
}
//----------------------------------------------------------------------------
void DeSystemTestWidget::on_xiaolvBtn_clicked()
{
	ui.tabWidget->setCurrentIndex(2);
}
//----------------------------------------------------------------------------
void DeSystemTestWidget::on_funcBtn_clicked()
{
	Demo *demo = qApp->property("_mainWin").value<Demo *>();	
	DeMenuWidget widget;
	widget.move(demo->pos());
	widget.resize(demo->width(), demo->height());
	widget.setWindowOpacity(0.9);
	widget.exec();
}
//---------------------------------------------------------------------------
void DeSystemTestWidget::on_logoutBtn_clicked()
{
	Demo *demo = qApp->property("_mainWin").value<Demo *>();
	demo->slotBackMainWidget();
}
//----------------------------------------------------------------------------