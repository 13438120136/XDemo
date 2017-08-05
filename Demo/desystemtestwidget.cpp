#include "desystemtestwidget.h"
#include "dechanneltestmodel.h"
#include "detestinformodel.h"

//----------------------------------------------------------------------------
DeSystemTestWidget::DeSystemTestWidget(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	this->setWindowFlags(Qt::ToolTip);

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
void DeSystemTestWidget::on_okBtn_clicked()
{
	accept();
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