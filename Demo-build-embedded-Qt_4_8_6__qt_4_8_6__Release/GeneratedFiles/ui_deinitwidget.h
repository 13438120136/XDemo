/********************************************************************************
** Form generated from reading UI file 'deinitwidget.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEINITWIDGET_H
#define UI_DEINITWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DeInitWidget
{
public:
    QGridLayout *gridLayout_12;
    QWidget *mainWidget;
    QGridLayout *gridLayout_18;
    QWidget *widget_7;
    QGridLayout *gridLayout_16;
    QGridLayout *gridLayout_15;
    QPushButton *exitBtn;
    QLabel *label;
    QPushButton *loginBtn;
    QFrame *line;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_6;
    QWidget *widget_6;
    QGridLayout *gridLayout_13;
    QWidget *widget;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QLabel *label_6;
    QLabel *label_3;
    QLabel *label_7;
    QLabel *label_10;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget_2;
    QGridLayout *gridLayout_9;
    QGridLayout *gridLayout_10;
    QLabel *label_23;
    QLabel *label_24;
    QLabel *label_25;
    QLabel *label_26;
    QLabel *label_27;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_4;
    QLabel *msgLabel;
    QSpacerItem *verticalSpacer_3;
    QWidget *widget_8;
    QGridLayout *gridLayout_17;
    QGridLayout *gridLayout_14;
    QSpacerItem *verticalSpacer;
    QGridLayout *gridLayout_8;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QWidget *widget_5;
    QGridLayout *gridLayout_6;
    QWidget *widget_3;
    QGridLayout *gridLayout;
    QGridLayout *gridLayout_3;
    QLabel *label_4;
    QLabel *label_8;
    QLabel *label_5;
    QLabel *label_9;
    QLabel *label_11;
    QWidget *widget_4;
    QGridLayout *gridLayout_5;
    QLabel *label_16;
    QGridLayout *gridLayout_7;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QGridLayout *gridLayout_11;
    QSpacerItem *verticalSpacer_2;
    QLabel *timeLabel;

    void setupUi(QWidget *DeInitWidget)
    {
        if (DeInitWidget->objectName().isEmpty())
            DeInitWidget->setObjectName(QString::fromUtf8("DeInitWidget"));
        DeInitWidget->resize(746, 545);
        DeInitWidget->setAutoFillBackground(true);
        DeInitWidget->setStyleSheet(QString::fromUtf8(""));
        gridLayout_12 = new QGridLayout(DeInitWidget);
        gridLayout_12->setSpacing(0);
        gridLayout_12->setContentsMargins(0, 0, 0, 0);
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        mainWidget = new QWidget(DeInitWidget);
        mainWidget->setObjectName(QString::fromUtf8("mainWidget"));
        mainWidget->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"   border: 0px solid gray;\n"
"   color: gray;      \n"
"   font: bold 12pt \"\351\273\221\344\275\223\";\n"
"   min-height:30px;\n"
"   min-width:100px;\n"
"   outline:none;\n"
"}\n"
"\n"
"QLabel\n"
"{\n"
"   color: gray;\n"
"   font: bold 14pt \"\351\273\221\344\275\223\";\n"
"}"));
        gridLayout_18 = new QGridLayout(mainWidget);
        gridLayout_18->setSpacing(6);
        gridLayout_18->setContentsMargins(11, 11, 11, 11);
        gridLayout_18->setObjectName(QString::fromUtf8("gridLayout_18"));
        widget_7 = new QWidget(mainWidget);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        widget_7->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{   \n"
"   background-color: rgb(255, 255, 255, 0);\n"
"   border:0px solid red;\n"
"   border-radius:0px;\n"
"   font:bold 14px;\n"
"}\n"
"\n"
"QPushButton:focus\n"
"{\n"
"   border-left-width:0px;\n"
"   border-right-width:0px;\n"
"   border-top-width:0px;\n"
"   border-bottom-width:2px;   \n"
"   border-bottom-color:  rgb(66, 189, 170);\n"
"   color:  rgb(66, 189, 170);\n"
"}"));
        gridLayout_16 = new QGridLayout(widget_7);
        gridLayout_16->setSpacing(0);
        gridLayout_16->setContentsMargins(0, 0, 0, 0);
        gridLayout_16->setObjectName(QString::fromUtf8("gridLayout_16"));
        gridLayout_15 = new QGridLayout();
        gridLayout_15->setSpacing(0);
        gridLayout_15->setObjectName(QString::fromUtf8("gridLayout_15"));
        gridLayout_15->setContentsMargins(3, 0, 3, 0);
        exitBtn = new QPushButton(widget_7);
        exitBtn->setObjectName(QString::fromUtf8("exitBtn"));

        gridLayout_15->addWidget(exitBtn, 0, 0, 1, 1);

        label = new QLabel(widget_7);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout_15->addWidget(label, 0, 2, 1, 1);

        loginBtn = new QPushButton(widget_7);
        loginBtn->setObjectName(QString::fromUtf8("loginBtn"));

        gridLayout_15->addWidget(loginBtn, 0, 4, 1, 1);

        line = new QFrame(widget_7);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_15->addWidget(line, 1, 0, 1, 5);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_15->addItem(horizontalSpacer_5, 0, 1, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_15->addItem(horizontalSpacer_6, 0, 3, 1, 1);


        gridLayout_16->addLayout(gridLayout_15, 0, 0, 1, 1);


        gridLayout_18->addWidget(widget_7, 0, 0, 1, 1);

        widget_6 = new QWidget(mainWidget);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        widget_6->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"   color: gray;\n"
"   font: 10pt \"\351\273\221\344\275\223\";\n"
"}"));
        gridLayout_13 = new QGridLayout(widget_6);
        gridLayout_13->setSpacing(6);
        gridLayout_13->setContentsMargins(11, 11, 11, 11);
        gridLayout_13->setObjectName(QString::fromUtf8("gridLayout_13"));
        widget = new QWidget(widget_6);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout_4 = new QGridLayout(widget);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMaximumSize(QSize(20, 20));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(10);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        label_2->setFont(font);

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

        label_6 = new QLabel(widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMaximumSize(QSize(20, 20));

        gridLayout_2->addWidget(label_6, 0, 1, 1, 1);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMaximumSize(QSize(20, 20));

        gridLayout_2->addWidget(label_3, 1, 0, 1, 1);

        label_7 = new QLabel(widget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setMaximumSize(QSize(20, 20));

        gridLayout_2->addWidget(label_7, 1, 1, 1, 1);


        gridLayout_4->addLayout(gridLayout_2, 1, 1, 1, 1);

        label_10 = new QLabel(widget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setMinimumSize(QSize(100, 100));
        label_10->setMaximumSize(QSize(16777215, 16777215));
        label_10->setFont(font);
        label_10->setStyleSheet(QString::fromUtf8("image: url(:/Demo/Resources/leftHand.jpg);"));
        label_10->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_10, 0, 0, 1, 3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer, 1, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_2, 1, 0, 1, 1);


        gridLayout_13->addWidget(widget, 1, 0, 1, 1);

        widget_2 = new QWidget(widget_6);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        gridLayout_9 = new QGridLayout(widget_2);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        gridLayout_10 = new QGridLayout();
        gridLayout_10->setSpacing(6);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        label_23 = new QLabel(widget_2);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setMaximumSize(QSize(20, 20));
        label_23->setFont(font);

        gridLayout_10->addWidget(label_23, 0, 0, 1, 1);

        label_24 = new QLabel(widget_2);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setMaximumSize(QSize(20, 20));

        gridLayout_10->addWidget(label_24, 0, 1, 1, 1);

        label_25 = new QLabel(widget_2);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setMaximumSize(QSize(20, 20));

        gridLayout_10->addWidget(label_25, 1, 0, 1, 1);

        label_26 = new QLabel(widget_2);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setMaximumSize(QSize(20, 20));

        gridLayout_10->addWidget(label_26, 1, 1, 1, 1);


        gridLayout_9->addLayout(gridLayout_10, 1, 1, 1, 1);

        label_27 = new QLabel(widget_2);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setMinimumSize(QSize(100, 100));
        label_27->setMaximumSize(QSize(16777215, 16777215));
        label_27->setFont(font);
        label_27->setStyleSheet(QString::fromUtf8("image: url(:/Demo/Resources/rightHand.jpg);"));
        label_27->setAlignment(Qt::AlignCenter);

        gridLayout_9->addWidget(label_27, 0, 0, 1, 3);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_9->addItem(horizontalSpacer_3, 1, 2, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_9->addItem(horizontalSpacer_4, 1, 0, 1, 1);


        gridLayout_13->addWidget(widget_2, 1, 2, 1, 1);

        msgLabel = new QLabel(widget_6);
        msgLabel->setObjectName(QString::fromUtf8("msgLabel"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\226\260\345\256\213\344\275\223"));
        font1.setPointSize(24);
        font1.setBold(true);
        font1.setItalic(false);
        font1.setWeight(75);
        msgLabel->setFont(font1);
        msgLabel->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: bold 24pt \"\346\226\260\345\256\213\344\275\223\" ;"));
        msgLabel->setAlignment(Qt::AlignCenter);

        gridLayout_13->addWidget(msgLabel, 1, 1, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_13->addItem(verticalSpacer_3, 0, 1, 1, 1);


        gridLayout_18->addWidget(widget_6, 1, 0, 1, 1);

        widget_8 = new QWidget(mainWidget);
        widget_8->setObjectName(QString::fromUtf8("widget_8"));
        widget_8->setStyleSheet(QString::fromUtf8("QPushButton::focus\n"
"{	\n"
"	color:rgb(64, 242, 255);\n"
"}\n"
"\n"
"QPushButton\n"
"{\n"
"    font: 10pt \"\351\273\221\344\275\223\";\n"
"    min-width:40px;\n"
"}\n"
"\n"
"QLabel\n"
"{\n"
"   color: gray;\n"
"   font: 10pt \"\351\273\221\344\275\223\";\n"
"}"));
        gridLayout_17 = new QGridLayout(widget_8);
        gridLayout_17->setSpacing(6);
        gridLayout_17->setContentsMargins(11, 11, 11, 11);
        gridLayout_17->setObjectName(QString::fromUtf8("gridLayout_17"));
        gridLayout_14 = new QGridLayout();
        gridLayout_14->setSpacing(6);
        gridLayout_14->setObjectName(QString::fromUtf8("gridLayout_14"));
        verticalSpacer = new QSpacerItem(20, 128, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_14->addItem(verticalSpacer, 0, 0, 1, 1);

        gridLayout_8 = new QGridLayout();
        gridLayout_8->setSpacing(0);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        pushButton = new QPushButton(widget_8);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setStyleSheet(QString::fromUtf8(""));

        gridLayout_8->addWidget(pushButton, 0, 0, 1, 1);

        pushButton_2 = new QPushButton(widget_8);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setAutoDefault(false);
        pushButton_2->setDefault(false);
        pushButton_2->setFlat(false);

        gridLayout_8->addWidget(pushButton_2, 0, 1, 1, 1);


        gridLayout_14->addLayout(gridLayout_8, 1, 0, 1, 1);


        gridLayout_17->addLayout(gridLayout_14, 0, 0, 1, 1);

        widget_5 = new QWidget(widget_8);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        gridLayout_6 = new QGridLayout(widget_5);
        gridLayout_6->setSpacing(0);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        widget_3 = new QWidget(widget_5);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        gridLayout = new QGridLayout(widget_3);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(0);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setSizeConstraint(QLayout::SetMinimumSize);
        label_4 = new QLabel(widget_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMaximumSize(QSize(20, 20));
        label_4->setFont(font);

        gridLayout_3->addWidget(label_4, 0, 0, 1, 1);

        label_8 = new QLabel(widget_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setMaximumSize(QSize(20, 20));

        gridLayout_3->addWidget(label_8, 0, 1, 1, 1);

        label_5 = new QLabel(widget_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMaximumSize(QSize(20, 20));

        gridLayout_3->addWidget(label_5, 1, 0, 1, 1);

        label_9 = new QLabel(widget_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setMaximumSize(QSize(20, 20));

        gridLayout_3->addWidget(label_9, 1, 1, 1, 1);


        gridLayout->addLayout(gridLayout_3, 0, 1, 1, 1);

        label_11 = new QLabel(widget_3);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setMinimumSize(QSize(100, 100));
        label_11->setMaximumSize(QSize(16777215, 16777215));
        label_11->setFont(font);
        label_11->setStyleSheet(QString::fromUtf8("image: url(:/Demo/Resources/lFoot.png);"));
        label_11->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_11, 0, 2, 1, 1);


        gridLayout_6->addWidget(widget_3, 0, 0, 1, 1);

        widget_4 = new QWidget(widget_5);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        gridLayout_5 = new QGridLayout(widget_4);
        gridLayout_5->setSpacing(0);
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        label_16 = new QLabel(widget_4);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setMinimumSize(QSize(100, 100));
        label_16->setMaximumSize(QSize(16777215, 16777215));
        label_16->setFont(font);
        label_16->setStyleSheet(QString::fromUtf8("image: url(:/Demo/Resources/rFoot.png);"));
        label_16->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_16, 0, 0, 1, 1);

        gridLayout_7 = new QGridLayout();
        gridLayout_7->setSpacing(0);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setSizeConstraint(QLayout::SetMinimumSize);
        label_12 = new QLabel(widget_4);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setMaximumSize(QSize(20, 20));
        label_12->setFont(font);

        gridLayout_7->addWidget(label_12, 0, 0, 1, 1);

        label_13 = new QLabel(widget_4);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setMaximumSize(QSize(20, 20));

        gridLayout_7->addWidget(label_13, 0, 1, 1, 1);

        label_14 = new QLabel(widget_4);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setMaximumSize(QSize(20, 20));

        gridLayout_7->addWidget(label_14, 1, 0, 1, 1);

        label_15 = new QLabel(widget_4);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setMaximumSize(QSize(20, 20));

        gridLayout_7->addWidget(label_15, 1, 1, 1, 1);


        gridLayout_5->addLayout(gridLayout_7, 0, 1, 1, 1);


        gridLayout_6->addWidget(widget_4, 0, 1, 1, 1);


        gridLayout_17->addWidget(widget_5, 0, 1, 1, 1);

        gridLayout_11 = new QGridLayout();
        gridLayout_11->setSpacing(6);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        verticalSpacer_2 = new QSpacerItem(118, 118, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_11->addItem(verticalSpacer_2, 0, 0, 1, 1);

        timeLabel = new QLabel(widget_8);
        timeLabel->setObjectName(QString::fromUtf8("timeLabel"));
        timeLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_11->addWidget(timeLabel, 1, 0, 1, 1);


        gridLayout_17->addLayout(gridLayout_11, 0, 2, 1, 1);


        gridLayout_18->addWidget(widget_8, 2, 0, 1, 1);


        gridLayout_12->addWidget(mainWidget, 0, 0, 1, 1);


        retranslateUi(DeInitWidget);

        QMetaObject::connectSlotsByName(DeInitWidget);
    } // setupUi

    void retranslateUi(QWidget *DeInitWidget)
    {
        DeInitWidget->setWindowTitle(QApplication::translate("DeInitWidget", "DeInitWidget", 0, QApplication::UnicodeUTF8));
        exitBtn->setText(QApplication::translate("DeInitWidget", "\351\200\200\345\207\272\347\250\213\345\272\217", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("DeInitWidget", "\346\211\213\350\266\263\346\261\241\346\237\223\346\265\213\351\207\217\344\273\252", 0, QApplication::UnicodeUTF8));
        loginBtn->setText(QApplication::translate("DeInitWidget", "\347\231\273\345\275\225", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("DeInitWidget", "\316\261", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("DeInitWidget", "0", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("DeInitWidget", "\316\262", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("DeInitWidget", "0", 0, QApplication::UnicodeUTF8));
        label_10->setText(QString());
        label_23->setText(QApplication::translate("DeInitWidget", "\316\261", 0, QApplication::UnicodeUTF8));
        label_24->setText(QApplication::translate("DeInitWidget", "0", 0, QApplication::UnicodeUTF8));
        label_25->setText(QApplication::translate("DeInitWidget", "\316\262", 0, QApplication::UnicodeUTF8));
        label_26->setText(QApplication::translate("DeInitWidget", "0", 0, QApplication::UnicodeUTF8));
        label_27->setText(QString());
        msgLabel->setText(QApplication::translate("DeInitWidget", "TextLabel", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("DeInitWidget", "\344\270\255\346\226\207", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("DeInitWidget", "English", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("DeInitWidget", "\316\261", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("DeInitWidget", "0", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("DeInitWidget", "\316\262", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("DeInitWidget", "0", 0, QApplication::UnicodeUTF8));
        label_11->setText(QString());
        label_16->setText(QString());
        label_12->setText(QApplication::translate("DeInitWidget", "\316\261", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("DeInitWidget", "0", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("DeInitWidget", "\316\262", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("DeInitWidget", "0", 0, QApplication::UnicodeUTF8));
        timeLabel->setText(QApplication::translate("DeInitWidget", "TextLabel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DeInitWidget: public Ui_DeInitWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEINITWIDGET_H
