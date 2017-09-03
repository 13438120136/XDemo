/********************************************************************************
** Form generated from reading UI file 'desystemtestwidget.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DESYSTEMTESTWIDGET_H
#define UI_DESYSTEMTESTWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTabWidget>
#include <QtGui/QWidget>
#include <detableview.h>

QT_BEGIN_NAMESPACE

class Ui_DeSystemTestWidget
{
public:
    QGridLayout *gridLayout_24;
    QWidget *widget_2;
    QGridLayout *gridLayout_18;
    QPushButton *funcBtn;
    QPushButton *ioBtn;
    QPushButton *channelBtn;
    QPushButton *xiaolvBtn;
    QPushButton *logoutBtn;
    QFrame *line;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_8;
    QWidget *widget_3;
    QGridLayout *gridLayout;
    QLabel *label_15;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_6;
    QSpacerItem *horizontalSpacer_2;
    QGridLayout *gridLayout_4;
    QLabel *label_5;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer_4;
    QGridLayout *gridLayout_7;
    QLabel *label_7;
    QLabel *label_8;
    QSpacerItem *horizontalSpacer_3;
    QGridLayout *gridLayout_6;
    QGridLayout *gridLayout_5;
    QLabel *label_9;
    QLabel *label_10;
    QGridLayout *gridLayout_3;
    QLabel *label_3;
    QLabel *label_4;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QLabel *label_2;
    QWidget *tab_2;
    QGridLayout *gridLayout_21;
    QGridLayout *gridLayout_12;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_10;
    QRadioButton *physicalTest;
    QRadioButton *electricTest;
    QFrame *line_2;
    QGroupBox *groupBox_9;
    QGridLayout *gridLayout_22;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_4;
    QFrame *line_3;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_9;
    QLabel *label_13;
    QLabel *label_12;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_4;
    QLabel *label_14;
    QLabel *label_11;
    QGridLayout *gridLayout_20;
    QWidget *widget;
    QGridLayout *gridLayout_19;
    QLabel *label_16;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pushButton_2;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_11;
    DeTableView *widget_4;
    QWidget *tab_3;
    QGridLayout *gridLayout_26;
    QGridLayout *gridLayout_17;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_13;
    QRadioButton *radioButton_4;
    QRadioButton *radioButton_3;
    QFrame *line_4;
    QGroupBox *groupBox_6;
    QGridLayout *gridLayout_14;
    QCheckBox *checkBox;
    QCheckBox *checkBox_5;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_6;
    QFrame *line_5;
    QGroupBox *groupBox_7;
    QGridLayout *gridLayout_15;
    QLabel *label_18;
    QLineEdit *lineEdit_5;
    QProgressBar *progressBar;
    QGridLayout *gridLayout_25;
    QWidget *widget_6;
    QGridLayout *gridLayout_23;
    QLabel *label_17;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *pushButton_3;
    QGroupBox *groupBox_8;
    QGridLayout *gridLayout_16;
    DeTableView *widget_5;

    void setupUi(QDialog *DeSystemTestWidget)
    {
        if (DeSystemTestWidget->objectName().isEmpty())
            DeSystemTestWidget->setObjectName(QString::fromUtf8("DeSystemTestWidget"));
        DeSystemTestWidget->resize(615, 518);
        DeSystemTestWidget->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"font: 12pt \"\351\273\221\344\275\223\";\n"
"min-width:10px;\n"
"}\n"
"\n"
"QTabWidget::pane\n"
"{   \n"
"	background-color: rgb(255, 255, 255);\n"
"    border: 0px;\n"
"}\n"
"\n"
"QLineEdit\n"
"{\n"
"border:1px solid gray;\n"
"border-radius:5px;\n"
"min-height:30px;\n"
"font: 16pt \"\351\273\221\344\275\223\";\n"
"}\n"
"\n"
"QCheckBox\n"
"{\n"
"font: 14pt \"\351\273\221\344\275\223\";\n"
"}\n"
"\n"
"QRadioButton\n"
"{\n"
"font: 14pt \"\351\273\221\344\275\223\";\n"
"}\n"
"\n"
"QGroupBox \n"
"{\n"
"     border: 1px solid gray;\n"
"}\n"
"\n"
"QGroupBox::title \n"
"{\n"
"     subcontrol-origin: margin;\n"
"     subcontrol-position: top center; /* position at the top center */\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #FFOECE, stop: 1 #FFFFFF);\n"
" }\n"
"\n"
"QPushButton {\n"
"    \n"
"	font: 16pt \"\351\273\221\344\275\223\";\n"
"	background-color: rgb(244, 244, 244);\n"
"    border: 1px solid #8f8f91;\n"
"    borde"
                        "r-radius: 6px;\n"
"    min-width: 100px;\n"
"    min-height: 30px;\n"
" }\n"
"\n"
" QPushButton:pressed {\n"
"	background-color: rgb(255, 255, 255);\n"
" }\n"
"\n"
" QTabWidget::tab-bar {\n"
"     alignment: center;\n"
" }\n"
"\n"
"\n"
" QTabBar::tab {\n"
"     background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                 stop: 0 #E1E1E1, stop: 0.4 #DDDDDD,\n"
"                                 stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3);\n"
"     border: 1px solid #C4C4C3;\n"
"     border-bottom-color: #C2C7CB; /* same as the pane color */\n"
"     border-top-left-radius:  3px;\n"
"     border-top-right-radius: 3px;    \n"
"     padding-left: 20px;\n"
"     padding-right: 20px;\n"
"     padding-top: 10px;\n"
"     padding-bottom:6px;\n"
" }\n"
"\n"
" QTabBar::tab:selected, QTabBar::tab:hover {\n"
"     background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                 stop: 0 #fafafa, stop: 0.4 #f4f4f4,\n"
"                                 stop: 0.5 #e7e7e7, s"
                        "top: 1.0 #fafafa);\n"
" }\n"
"\n"
" QTabBar::tab:selected {\n"
"     border-color: #9B9B9B;\n"
"     border-bottom-color: #C2C7CB; /* same as pane color */\n"
" }\n"
"\n"
" QTabBar::tab:!selected {\n"
"     margin-top: 2px; /* make non-selected tabs look smaller */\n"
" }\n"
"\n"
"QProgressBar {\n"
"    border: 1px solid grey;\n"
"    border-radius: 2px;\n"
"    text-align: center;\n"
"    min-height:26px;\n"
"}\n"
"\n"
"QProgressBar::chunk {\n"
"	background-color: rgb(5, 135, 234);\n"
"}"));
        gridLayout_24 = new QGridLayout(DeSystemTestWidget);
        gridLayout_24->setSpacing(0);
        gridLayout_24->setContentsMargins(0, 0, 0, 0);
        gridLayout_24->setObjectName(QString::fromUtf8("gridLayout_24"));
        widget_2 = new QWidget(DeSystemTestWidget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{   \n"
"   background-color: rgb(255, 255, 255, 0);\n"
"   border:0px solid red;\n"
"   border-radius:0px;\n"
"   font:bold 16px;\n"
"   min-width: 100px;\n"
"   min-height: 35px;\n"
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
"}\n"
"\n"
".QWidget\n"
"{\n"
"background-color: rgb(250, 250, 250);\n"
"}"));
        gridLayout_18 = new QGridLayout(widget_2);
        gridLayout_18->setSpacing(0);
        gridLayout_18->setContentsMargins(11, 11, 11, 11);
        gridLayout_18->setObjectName(QString::fromUtf8("gridLayout_18"));
        gridLayout_18->setContentsMargins(-1, 0, -1, 0);
        funcBtn = new QPushButton(widget_2);
        funcBtn->setObjectName(QString::fromUtf8("funcBtn"));

        gridLayout_18->addWidget(funcBtn, 0, 0, 1, 1);

        ioBtn = new QPushButton(widget_2);
        ioBtn->setObjectName(QString::fromUtf8("ioBtn"));

        gridLayout_18->addWidget(ioBtn, 0, 1, 1, 1);

        channelBtn = new QPushButton(widget_2);
        channelBtn->setObjectName(QString::fromUtf8("channelBtn"));

        gridLayout_18->addWidget(channelBtn, 0, 2, 1, 1);

        xiaolvBtn = new QPushButton(widget_2);
        xiaolvBtn->setObjectName(QString::fromUtf8("xiaolvBtn"));

        gridLayout_18->addWidget(xiaolvBtn, 0, 3, 1, 1);

        logoutBtn = new QPushButton(widget_2);
        logoutBtn->setObjectName(QString::fromUtf8("logoutBtn"));

        gridLayout_18->addWidget(logoutBtn, 0, 4, 1, 1);


        gridLayout_24->addWidget(widget_2, 0, 0, 1, 1);

        line = new QFrame(DeSystemTestWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_24->addWidget(line, 1, 0, 1, 1);

        tabWidget = new QTabWidget(DeSystemTestWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setStyleSheet(QString::fromUtf8(""));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout_8 = new QGridLayout(tab);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        widget_3 = new QWidget(tab);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"    font:bold 16px;\n"
"    color: rgb(254, 255, 253);\n"
"    background-color: rgb(66, 189, 170);\n"
"}\n"
"\n"
".QWidget\n"
"{\n"
"max-height:50px;\n"
"background-color: rgb(255, 255, 255);\n"
"}"));
        gridLayout = new QGridLayout(widget_3);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(20, 0, 20, 0);
        label_15 = new QLabel(widget_3);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout->addWidget(label_15, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(469, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 1, 1, 1);

        pushButton_6 = new QPushButton(widget_3);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));

        gridLayout->addWidget(pushButton_6, 0, 2, 1, 1);


        gridLayout_8->addWidget(widget_3, 0, 0, 1, 5);

        horizontalSpacer_2 = new QSpacerItem(127, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_8->addItem(horizontalSpacer_2, 2, 0, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label_5 = new QLabel(tab);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(10, 0));
        label_5->setStyleSheet(QString::fromUtf8("border-image: url(:/Demo/Resources/key.jpg);"));

        gridLayout_4->addWidget(label_5, 0, 0, 1, 1);

        label_6 = new QLabel(tab);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMaximumSize(QSize(16777215, 16777215));
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_6, 1, 0, 1, 1);


        gridLayout_8->addLayout(gridLayout_4, 2, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(127, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_8->addItem(horizontalSpacer_4, 2, 2, 1, 1);

        gridLayout_7 = new QGridLayout();
        gridLayout_7->setSpacing(6);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        label_7 = new QLabel(tab);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setMinimumSize(QSize(10, 0));
        label_7->setStyleSheet(QString::fromUtf8("border-image: url(:/Demo/Resources/key.jpg);"));

        gridLayout_7->addWidget(label_7, 0, 0, 1, 1);

        label_8 = new QLabel(tab);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setMaximumSize(QSize(16777215, 16777215));
        label_8->setAlignment(Qt::AlignCenter);

        gridLayout_7->addWidget(label_8, 1, 0, 1, 1);


        gridLayout_8->addLayout(gridLayout_7, 2, 3, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(127, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_8->addItem(horizontalSpacer_3, 2, 4, 1, 1);

        gridLayout_6 = new QGridLayout();
        gridLayout_6->setSpacing(0);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setSpacing(6);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        label_9 = new QLabel(tab);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setMinimumSize(QSize(10, 0));
        label_9->setStyleSheet(QString::fromUtf8("border-image: url(:/Demo/Resources/key.jpg);"));

        gridLayout_5->addWidget(label_9, 0, 0, 1, 1);

        label_10 = new QLabel(tab);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setMaximumSize(QSize(16777215, 16777215));
        label_10->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_10, 1, 0, 1, 1);


        gridLayout_6->addLayout(gridLayout_5, 0, 2, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_3 = new QLabel(tab);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(10, 0));
        label_3->setStyleSheet(QString::fromUtf8("border-image: url(:/Demo/Resources/key.jpg);"));

        gridLayout_3->addWidget(label_3, 0, 0, 1, 1);

        label_4 = new QLabel(tab);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMaximumSize(QSize(16777215, 16777215));
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_4, 1, 0, 1, 1);


        gridLayout_6->addLayout(gridLayout_3, 0, 1, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label = new QLabel(tab);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(10, 0));
        label->setStyleSheet(QString::fromUtf8("border-image: url(:/Demo/Resources/key.jpg);\n"
""));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(tab);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMaximumSize(QSize(16777215, 16777215));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);


        gridLayout_6->addLayout(gridLayout_2, 0, 0, 1, 1);

        gridLayout_6->setColumnStretch(0, 1);
        gridLayout_6->setColumnStretch(1, 1);
        gridLayout_6->setColumnStretch(2, 1);

        gridLayout_8->addLayout(gridLayout_6, 1, 0, 1, 5);

        gridLayout_8->setColumnStretch(0, 1);
        gridLayout_8->setColumnStretch(1, 2);
        gridLayout_8->setColumnStretch(2, 1);
        gridLayout_8->setColumnStretch(3, 2);
        gridLayout_8->setColumnStretch(4, 1);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tab_2->setStyleSheet(QString::fromUtf8("QGroupBox\n"
"{\n"
"   border:none;\n"
"}"));
        gridLayout_21 = new QGridLayout(tab_2);
        gridLayout_21->setSpacing(0);
        gridLayout_21->setContentsMargins(0, 0, 0, 0);
        gridLayout_21->setObjectName(QString::fromUtf8("gridLayout_21"));
        gridLayout_12 = new QGridLayout();
        gridLayout_12->setSpacing(6);
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        groupBox_3 = new QGroupBox(tab_2);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setMaximumSize(QSize(16777215, 16777215));
        gridLayout_10 = new QGridLayout(groupBox_3);
        gridLayout_10->setSpacing(6);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        physicalTest = new QRadioButton(groupBox_3);
        physicalTest->setObjectName(QString::fromUtf8("physicalTest"));
        physicalTest->setChecked(true);

        gridLayout_10->addWidget(physicalTest, 0, 0, 1, 2);

        electricTest = new QRadioButton(groupBox_3);
        electricTest->setObjectName(QString::fromUtf8("electricTest"));

        gridLayout_10->addWidget(electricTest, 1, 0, 1, 2);


        gridLayout_12->addWidget(groupBox_3, 0, 0, 1, 1);

        line_2 = new QFrame(tab_2);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout_12->addWidget(line_2, 1, 0, 1, 1);

        groupBox_9 = new QGroupBox(tab_2);
        groupBox_9->setObjectName(QString::fromUtf8("groupBox_9"));
        gridLayout_22 = new QGridLayout(groupBox_9);
        gridLayout_22->setSpacing(6);
        gridLayout_22->setContentsMargins(11, 11, 11, 11);
        gridLayout_22->setObjectName(QString::fromUtf8("gridLayout_22"));
        checkBox_3 = new QCheckBox(groupBox_9);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));

        gridLayout_22->addWidget(checkBox_3, 0, 0, 1, 1);

        checkBox_4 = new QCheckBox(groupBox_9);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));

        gridLayout_22->addWidget(checkBox_4, 1, 0, 1, 1);


        gridLayout_12->addWidget(groupBox_9, 2, 0, 1, 1);

        line_3 = new QFrame(tab_2);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout_12->addWidget(line_3, 3, 0, 1, 1);

        groupBox_2 = new QGroupBox(tab_2);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_9 = new QGridLayout(groupBox_2);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        label_13 = new QLabel(groupBox_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_9->addWidget(label_13, 5, 0, 1, 1);

        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_9->addWidget(label_12, 3, 0, 1, 1);

        lineEdit_3 = new QLineEdit(groupBox_2);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        gridLayout_9->addWidget(lineEdit_3, 6, 0, 1, 1);

        lineEdit_2 = new QLineEdit(groupBox_2);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        gridLayout_9->addWidget(lineEdit_2, 4, 0, 1, 1);

        lineEdit = new QLineEdit(groupBox_2);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout_9->addWidget(lineEdit, 2, 0, 1, 1);

        lineEdit_4 = new QLineEdit(groupBox_2);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));

        gridLayout_9->addWidget(lineEdit_4, 8, 0, 1, 1);

        label_14 = new QLabel(groupBox_2);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_9->addWidget(label_14, 7, 0, 1, 1);

        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setMinimumSize(QSize(10, 0));

        gridLayout_9->addWidget(label_11, 1, 0, 1, 1);


        gridLayout_12->addWidget(groupBox_2, 4, 0, 1, 1);


        gridLayout_21->addLayout(gridLayout_12, 0, 0, 1, 1);

        gridLayout_20 = new QGridLayout();
        gridLayout_20->setSpacing(6);
        gridLayout_20->setObjectName(QString::fromUtf8("gridLayout_20"));
        widget = new QWidget(tab_2);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"    font:bold 16px;\n"
"    color: rgb(254, 255, 253);\n"
"    background-color: rgb(66, 189, 170);\n"
"}\n"
"\n"
".QWidget\n"
"{\n"
"max-height:50px;\n"
"background-color: rgb(255, 255, 255);\n"
"}"));
        gridLayout_19 = new QGridLayout(widget);
        gridLayout_19->setSpacing(6);
        gridLayout_19->setContentsMargins(11, 11, 11, 11);
        gridLayout_19->setObjectName(QString::fromUtf8("gridLayout_19"));
        label_16 = new QLabel(widget);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        gridLayout_19->addWidget(label_16, 0, 0, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(167, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_19->addItem(horizontalSpacer_5, 0, 1, 1, 1);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout_19->addWidget(pushButton_2, 0, 2, 1, 1);


        gridLayout_20->addWidget(widget, 0, 0, 1, 1);

        groupBox_4 = new QGroupBox(tab_2);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setStyleSheet(QString::fromUtf8(""));
        gridLayout_11 = new QGridLayout(groupBox_4);
        gridLayout_11->setSpacing(6);
        gridLayout_11->setContentsMargins(11, 11, 11, 11);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        widget_4 = new DeTableView(groupBox_4);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));

        gridLayout_11->addWidget(widget_4, 1, 0, 1, 1);


        gridLayout_20->addWidget(groupBox_4, 1, 0, 1, 1);


        gridLayout_21->addLayout(gridLayout_20, 0, 1, 1, 1);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        tab_3->setStyleSheet(QString::fromUtf8("QGroupBox\n"
"{\n"
"   border:none;\n"
"}"));
        gridLayout_26 = new QGridLayout(tab_3);
        gridLayout_26->setSpacing(6);
        gridLayout_26->setContentsMargins(11, 11, 11, 11);
        gridLayout_26->setObjectName(QString::fromUtf8("gridLayout_26"));
        gridLayout_17 = new QGridLayout();
        gridLayout_17->setSpacing(0);
        gridLayout_17->setObjectName(QString::fromUtf8("gridLayout_17"));
        groupBox_5 = new QGroupBox(tab_3);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        gridLayout_13 = new QGridLayout(groupBox_5);
        gridLayout_13->setSpacing(6);
        gridLayout_13->setContentsMargins(11, 11, 11, 11);
        gridLayout_13->setObjectName(QString::fromUtf8("gridLayout_13"));
        radioButton_4 = new QRadioButton(groupBox_5);
        radioButton_4->setObjectName(QString::fromUtf8("radioButton_4"));

        gridLayout_13->addWidget(radioButton_4, 0, 0, 1, 1);

        radioButton_3 = new QRadioButton(groupBox_5);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));

        gridLayout_13->addWidget(radioButton_3, 1, 0, 1, 1);


        gridLayout_17->addWidget(groupBox_5, 0, 0, 1, 1);

        line_4 = new QFrame(tab_3);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        gridLayout_17->addWidget(line_4, 1, 0, 1, 1);

        groupBox_6 = new QGroupBox(tab_3);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        gridLayout_14 = new QGridLayout(groupBox_6);
        gridLayout_14->setSpacing(6);
        gridLayout_14->setContentsMargins(11, 11, 11, 11);
        gridLayout_14->setObjectName(QString::fromUtf8("gridLayout_14"));
        checkBox = new QCheckBox(groupBox_6);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        gridLayout_14->addWidget(checkBox, 0, 0, 1, 1);

        checkBox_5 = new QCheckBox(groupBox_6);
        checkBox_5->setObjectName(QString::fromUtf8("checkBox_5"));

        gridLayout_14->addWidget(checkBox_5, 1, 1, 1, 1);

        checkBox_2 = new QCheckBox(groupBox_6);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));

        gridLayout_14->addWidget(checkBox_2, 1, 0, 1, 1);

        checkBox_6 = new QCheckBox(groupBox_6);
        checkBox_6->setObjectName(QString::fromUtf8("checkBox_6"));

        gridLayout_14->addWidget(checkBox_6, 0, 1, 1, 1);


        gridLayout_17->addWidget(groupBox_6, 2, 0, 1, 1);

        line_5 = new QFrame(tab_3);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        gridLayout_17->addWidget(line_5, 3, 0, 1, 1);

        groupBox_7 = new QGroupBox(tab_3);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        gridLayout_15 = new QGridLayout(groupBox_7);
        gridLayout_15->setSpacing(6);
        gridLayout_15->setContentsMargins(11, 11, 11, 11);
        gridLayout_15->setObjectName(QString::fromUtf8("gridLayout_15"));
        label_18 = new QLabel(groupBox_7);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        gridLayout_15->addWidget(label_18, 0, 0, 1, 1);

        lineEdit_5 = new QLineEdit(groupBox_7);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));

        gridLayout_15->addWidget(lineEdit_5, 1, 0, 1, 1);


        gridLayout_17->addWidget(groupBox_7, 4, 0, 1, 1);

        progressBar = new QProgressBar(tab_3);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(24);

        gridLayout_17->addWidget(progressBar, 5, 0, 1, 1);


        gridLayout_26->addLayout(gridLayout_17, 0, 0, 1, 1);

        gridLayout_25 = new QGridLayout();
        gridLayout_25->setSpacing(6);
        gridLayout_25->setObjectName(QString::fromUtf8("gridLayout_25"));
        widget_6 = new QWidget(tab_3);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        widget_6->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"    font:bold 16px;\n"
"    color: rgb(254, 255, 253);\n"
"    background-color: rgb(66, 189, 170);\n"
"}\n"
"\n"
".QWidget\n"
"{\n"
"max-height:50px;\n"
"background-color: rgb(255, 255, 255);\n"
"}"));
        gridLayout_23 = new QGridLayout(widget_6);
        gridLayout_23->setSpacing(6);
        gridLayout_23->setContentsMargins(11, 11, 11, 11);
        gridLayout_23->setObjectName(QString::fromUtf8("gridLayout_23"));
        label_17 = new QLabel(widget_6);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        gridLayout_23->addWidget(label_17, 0, 0, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(167, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_23->addItem(horizontalSpacer_6, 0, 1, 1, 1);

        pushButton_3 = new QPushButton(widget_6);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        gridLayout_23->addWidget(pushButton_3, 0, 2, 1, 1);


        gridLayout_25->addWidget(widget_6, 0, 0, 1, 1);

        groupBox_8 = new QGroupBox(tab_3);
        groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
        groupBox_8->setStyleSheet(QString::fromUtf8("QGroupBox#groupBox_8\n"
"{\n"
"min-width:400px;\n"
"}"));
        gridLayout_16 = new QGridLayout(groupBox_8);
        gridLayout_16->setSpacing(6);
        gridLayout_16->setContentsMargins(11, 11, 11, 11);
        gridLayout_16->setObjectName(QString::fromUtf8("gridLayout_16"));
        widget_5 = new DeTableView(groupBox_8);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));

        gridLayout_16->addWidget(widget_5, 0, 0, 1, 1);


        gridLayout_25->addWidget(groupBox_8, 1, 0, 1, 1);


        gridLayout_26->addLayout(gridLayout_25, 0, 1, 1, 1);

        tabWidget->addTab(tab_3, QString());

        gridLayout_24->addWidget(tabWidget, 2, 0, 1, 1);


        retranslateUi(DeSystemTestWidget);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(DeSystemTestWidget);
    } // setupUi

    void retranslateUi(QDialog *DeSystemTestWidget)
    {
        DeSystemTestWidget->setWindowTitle(QApplication::translate("DeSystemTestWidget", "DeSystemTestWidget", 0, QApplication::UnicodeUTF8));
        funcBtn->setText(QApplication::translate("DeSystemTestWidget", "\345\212\237\350\203\275\351\200\211\346\213\251", 0, QApplication::UnicodeUTF8));
        ioBtn->setText(QApplication::translate("DeSystemTestWidget", "IO\346\265\213\350\257\225", 0, QApplication::UnicodeUTF8));
        channelBtn->setText(QApplication::translate("DeSystemTestWidget", "\351\200\232\351\201\223\346\265\213\350\257\225", 0, QApplication::UnicodeUTF8));
        xiaolvBtn->setText(QApplication::translate("DeSystemTestWidget", "\346\225\210\347\216\207\346\240\207\345\256\232", 0, QApplication::UnicodeUTF8));
        logoutBtn->setText(QApplication::translate("DeSystemTestWidget", "\346\263\250\351\224\200", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("DeSystemTestWidget", "\347\212\266\346\200\201:\346\234\252\346\265\213\350\257\225", 0, QApplication::UnicodeUTF8));
        pushButton_6->setText(QApplication::translate("DeSystemTestWidget", "\345\274\200\345\247\213\346\265\213\350\257\225", 0, QApplication::UnicodeUTF8));
        label_5->setText(QString());
        label_6->setText(QApplication::translate("DeSystemTestWidget", "\345\267\246\346\211\213\345\257\271\345\260\204\345\274\217\347\272\242\345\244\226", 0, QApplication::UnicodeUTF8));
        label_7->setText(QString());
        label_8->setText(QApplication::translate("DeSystemTestWidget", "\345\217\263\346\211\213\345\257\271\345\260\204\345\274\217\347\272\242\345\244\226", 0, QApplication::UnicodeUTF8));
        label_9->setText(QString());
        label_10->setText(QApplication::translate("DeSystemTestWidget", "\345\217\263\346\211\213\346\216\242\346\265\213\345\231\250\346\213\206\345\215\270", 0, QApplication::UnicodeUTF8));
        label_3->setText(QString());
        label_4->setText(QApplication::translate("DeSystemTestWidget", "\350\204\232\346\255\245\345\216\213\345\212\233", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        label_2->setText(QApplication::translate("DeSystemTestWidget", "\344\272\272\345\221\230\346\216\245\350\277\221", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("DeSystemTestWidget", "IO\346\265\213\350\257\225", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QString());
        physicalTest->setText(QApplication::translate("DeSystemTestWidget", "\347\211\251\347\220\206\346\265\213\350\257\225", 0, QApplication::UnicodeUTF8));
        electricTest->setText(QApplication::translate("DeSystemTestWidget", "\347\224\265\346\265\213\350\257\225", 0, QApplication::UnicodeUTF8));
        groupBox_9->setTitle(QString());
        checkBox_3->setText(QApplication::translate("DeSystemTestWidget", "\316\261", 0, QApplication::UnicodeUTF8));
        checkBox_4->setText(QApplication::translate("DeSystemTestWidget", "\316\261+\316\262", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QString());
        label_13->setText(QApplication::translate("DeSystemTestWidget", "\344\277\256\346\255\243\347\263\273\346\225\2601\357\274\232", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("DeSystemTestWidget", "\351\230\200\345\200\274\357\274\232", 0, QApplication::UnicodeUTF8));
        lineEdit_3->setText(QString());
        lineEdit_2->setText(QString());
        lineEdit_4->setText(QString());
        label_14->setText(QApplication::translate("DeSystemTestWidget", "\344\277\256\346\255\243\347\263\273\346\225\2602\357\274\232", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("DeSystemTestWidget", "\351\253\230\345\216\213\345\200\274\357\274\232", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("DeSystemTestWidget", "\346\265\213\350\257\225\347\273\223\346\236\234:", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("DeSystemTestWidget", "\345\274\200\345\247\213\346\265\213\350\257\225", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("DeSystemTestWidget", "\351\200\232\351\201\223\346\265\213\350\257\225", 0, QApplication::UnicodeUTF8));
        groupBox_5->setTitle(QString());
        radioButton_4->setText(QApplication::translate("DeSystemTestWidget", "Bete", 0, QApplication::UnicodeUTF8));
        radioButton_3->setText(QApplication::translate("DeSystemTestWidget", "Alpha", 0, QApplication::UnicodeUTF8));
        groupBox_6->setTitle(QString());
        checkBox->setText(QApplication::translate("DeSystemTestWidget", "1", 0, QApplication::UnicodeUTF8));
        checkBox_5->setText(QApplication::translate("DeSystemTestWidget", "4", 0, QApplication::UnicodeUTF8));
        checkBox_2->setText(QApplication::translate("DeSystemTestWidget", "3", 0, QApplication::UnicodeUTF8));
        checkBox_6->setText(QApplication::translate("DeSystemTestWidget", "2", 0, QApplication::UnicodeUTF8));
        groupBox_7->setTitle(QString());
        label_18->setText(QApplication::translate("DeSystemTestWidget", "\346\265\213\351\207\217\346\254\241\346\225\260\357\274\232", 0, QApplication::UnicodeUTF8));
        lineEdit_5->setText(QApplication::translate("DeSystemTestWidget", "4", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("DeSystemTestWidget", "\346\265\213\350\257\225\347\273\223\346\236\234:", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("DeSystemTestWidget", "\345\274\200\345\247\213\346\265\213\350\257\225", 0, QApplication::UnicodeUTF8));
        groupBox_8->setTitle(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("DeSystemTestWidget", "\346\225\210\347\216\207\346\240\207\345\256\232", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DeSystemTestWidget: public Ui_DeSystemTestWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DESYSTEMTESTWIDGET_H
