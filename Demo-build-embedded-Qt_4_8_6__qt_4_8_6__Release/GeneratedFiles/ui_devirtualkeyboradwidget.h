/********************************************************************************
** Form generated from reading UI file 'devirtualkeyboradwidget.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEVIRTUALKEYBORADWIDGET_H
#define UI_DEVIRTUALKEYBORADWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTabWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DeVirtualKeyboradWidget
{
public:
    QGridLayout *gridLayout_4;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QPushButton *pushButton_13;
    QPushButton *pushButton_14;
    QPushButton *pushButton_29;
    QPushButton *pushButton_30;
    QPushButton *pushButton_31;
    QPushButton *pushButton_32;
    QPushButton *pushButton_33;
    QPushButton *pushButton_34;
    QPushButton *pushButton_35;
    QPushButton *pushButton_36;
    QPushButton *pushButton_37;
    QPushButton *pushButton_38;
    QPushButton *pushButton_39;
    QPushButton *pushButton_40;
    QPushButton *pushButton_10;
    QPushButton *shiftBtn;
    QWidget *tab_2;
    QGridLayout *gridLayout_3;
    QPushButton *pushButton_100;
    QPushButton *pushButton_101;
    QPushButton *pushButton_102;
    QPushButton *pushButton_109;
    QPushButton *pushButton_103;
    QPushButton *pushButton_104;
    QPushButton *pushButton_105;
    QPushButton *pushButton_106;
    QPushButton *pushButton_107;
    QPushButton *pushButton_108;
    QPushButton *pushButton_15;
    QPushButton *spaceBtn;
    QPushButton *backBtn;
    QSpacerItem *verticalSpacer;
    QPushButton *hideBtn;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *horizontalSpacer;
    QButtonGroup *numButtonGroup;
    QButtonGroup *charButtonGroup;

    void setupUi(QWidget *DeVirtualKeyboradWidget)
    {
        if (DeVirtualKeyboradWidget->objectName().isEmpty())
            DeVirtualKeyboradWidget->setObjectName(QString::fromUtf8("DeVirtualKeyboradWidget"));
        DeVirtualKeyboradWidget->resize(498, 180);
        DeVirtualKeyboradWidget->setMaximumSize(QSize(16777215, 220));
        DeVirtualKeyboradWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(155, 160, 255);"));
        gridLayout_4 = new QGridLayout(DeVirtualKeyboradWidget);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(-1, 0, -1, 0);
        verticalSpacer_2 = new QSpacerItem(20, 157, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer_2, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(155, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_2, 1, 0, 1, 1);

        widget = new QWidget(DeVirtualKeyboradWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"background-color: rgb(255, 255, 255);\n"
"border:1px solid gray;\n"
"border-radius:3px;\n"
"min-width:40px;\n"
"min-height:40px;\n"
"font: 20pt \"\345\256\213\344\275\223\";\n"
"}\n"
"\n"
"QPushButton::pressed\n"
"{\n"
"	background-color: rgb(85, 170, 255);\n"
"    border:2px solid gray;\n"
"    border-radius:3px;\n"
"}"));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        tabWidget = new QTabWidget(widget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"background-color: rgb(255, 255, 255);\n"
"border:1px solid gray;\n"
"border-radius:3px;\n"
"min-width:40px;\n"
"min-height:40px;\n"
"font: 20pt \"\345\256\213\344\275\223\";\n"
"}\n"
"\n"
"\n"
"QPushButton::pressed\n"
"{\n"
"	background-color: rgb(85, 170, 255);\n"
"    border:2px solid gray;\n"
"    border-radius:3px;\n"
"}\n"
"\n"
" QTabWidget::pane { /* The tab widget frame */\n"
"     border: 1px solid #C2C7CB;\n"
" }\n"
"\n"
" QTabWidget::tab-bar {\n"
"     left: 15px;\n"
" }\n"
"\n"
" /* Style the tab using the tab sub-control. Note that\n"
"     it reads QTabBar _not_ QTabWidget */\n"
" QTabBar::tab {\n"
"     background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                 stop: 0 #E1E1E1, stop: 0.4 #DDDDDD,\n"
"                                 stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3);\n"
"     border: 1px solid #C4C4C3;\n"
"     border-bottom-color: #C2C7CB; /* same as the pane color */\n"
"     border-bottom-left-radius: 3px;\n"
"     border-bottom-right"
                        "-radius: 3px;\n"
"     min-width: 60px;\n"
"     padding: 8px;\n"
" }\n"
"\n"
" QTabBar::tab:selected, QTabBar::tab:hover {\n"
"     background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                 stop: 0 #fafafa, stop: 0.4 #f4f4f4,\n"
"                                 stop: 0.5 #e7e7e7, stop: 1.0 #fafafa);\n"
" }\n"
"\n"
" QTabBar::tab:selected {\n"
"     border-color: #9B9B9B;\n"
"     border-bottom-color: #C2C7CB; /* same as pane color */\n"
" }\n"
""));
        tabWidget->setTabPosition(QTabWidget::South);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setElideMode(Qt::ElideNone);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout = new QGridLayout(tab);
        gridLayout->setSpacing(3);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(6, 0, 6, 0);
        pushButton = new QPushButton(tab);
        charButtonGroup = new QButtonGroup(DeVirtualKeyboradWidget);
        charButtonGroup->setObjectName(QString::fromUtf8("charButtonGroup"));
        charButtonGroup->setExclusive(true);
        charButtonGroup->addButton(pushButton);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 0, 0, 1, 1);

        pushButton_2 = new QPushButton(tab);
        charButtonGroup->addButton(pushButton_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 0, 1, 1, 1);

        pushButton_3 = new QPushButton(tab);
        charButtonGroup->addButton(pushButton_3);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 0, 2, 1, 1);

        pushButton_4 = new QPushButton(tab);
        charButtonGroup->addButton(pushButton_4);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        gridLayout->addWidget(pushButton_4, 0, 3, 1, 1);

        pushButton_5 = new QPushButton(tab);
        charButtonGroup->addButton(pushButton_5);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        gridLayout->addWidget(pushButton_5, 0, 4, 1, 1);

        pushButton_6 = new QPushButton(tab);
        charButtonGroup->addButton(pushButton_6);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));

        gridLayout->addWidget(pushButton_6, 0, 5, 1, 1);

        pushButton_7 = new QPushButton(tab);
        charButtonGroup->addButton(pushButton_7);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));

        gridLayout->addWidget(pushButton_7, 0, 6, 1, 1);

        pushButton_8 = new QPushButton(tab);
        charButtonGroup->addButton(pushButton_8);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));

        gridLayout->addWidget(pushButton_8, 0, 7, 1, 1);

        pushButton_9 = new QPushButton(tab);
        charButtonGroup->addButton(pushButton_9);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));

        gridLayout->addWidget(pushButton_9, 0, 8, 1, 1);

        pushButton_11 = new QPushButton(tab);
        charButtonGroup->addButton(pushButton_11);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));

        gridLayout->addWidget(pushButton_11, 1, 0, 1, 1);

        pushButton_12 = new QPushButton(tab);
        charButtonGroup->addButton(pushButton_12);
        pushButton_12->setObjectName(QString::fromUtf8("pushButton_12"));

        gridLayout->addWidget(pushButton_12, 1, 1, 1, 1);

        pushButton_13 = new QPushButton(tab);
        charButtonGroup->addButton(pushButton_13);
        pushButton_13->setObjectName(QString::fromUtf8("pushButton_13"));

        gridLayout->addWidget(pushButton_13, 1, 2, 1, 1);

        pushButton_14 = new QPushButton(tab);
        charButtonGroup->addButton(pushButton_14);
        pushButton_14->setObjectName(QString::fromUtf8("pushButton_14"));

        gridLayout->addWidget(pushButton_14, 1, 3, 1, 1);

        pushButton_29 = new QPushButton(tab);
        charButtonGroup->addButton(pushButton_29);
        pushButton_29->setObjectName(QString::fromUtf8("pushButton_29"));

        gridLayout->addWidget(pushButton_29, 1, 4, 1, 1);

        pushButton_30 = new QPushButton(tab);
        charButtonGroup->addButton(pushButton_30);
        pushButton_30->setObjectName(QString::fromUtf8("pushButton_30"));

        gridLayout->addWidget(pushButton_30, 1, 5, 1, 1);

        pushButton_31 = new QPushButton(tab);
        charButtonGroup->addButton(pushButton_31);
        pushButton_31->setObjectName(QString::fromUtf8("pushButton_31"));

        gridLayout->addWidget(pushButton_31, 1, 6, 1, 1);

        pushButton_32 = new QPushButton(tab);
        charButtonGroup->addButton(pushButton_32);
        pushButton_32->setObjectName(QString::fromUtf8("pushButton_32"));

        gridLayout->addWidget(pushButton_32, 1, 7, 1, 1);

        pushButton_33 = new QPushButton(tab);
        charButtonGroup->addButton(pushButton_33);
        pushButton_33->setObjectName(QString::fromUtf8("pushButton_33"));

        gridLayout->addWidget(pushButton_33, 1, 8, 1, 1);

        pushButton_34 = new QPushButton(tab);
        charButtonGroup->addButton(pushButton_34);
        pushButton_34->setObjectName(QString::fromUtf8("pushButton_34"));

        gridLayout->addWidget(pushButton_34, 2, 0, 1, 1);

        pushButton_35 = new QPushButton(tab);
        charButtonGroup->addButton(pushButton_35);
        pushButton_35->setObjectName(QString::fromUtf8("pushButton_35"));

        gridLayout->addWidget(pushButton_35, 2, 1, 1, 1);

        pushButton_36 = new QPushButton(tab);
        charButtonGroup->addButton(pushButton_36);
        pushButton_36->setObjectName(QString::fromUtf8("pushButton_36"));

        gridLayout->addWidget(pushButton_36, 2, 2, 1, 1);

        pushButton_37 = new QPushButton(tab);
        charButtonGroup->addButton(pushButton_37);
        pushButton_37->setObjectName(QString::fromUtf8("pushButton_37"));

        gridLayout->addWidget(pushButton_37, 2, 3, 1, 1);

        pushButton_38 = new QPushButton(tab);
        charButtonGroup->addButton(pushButton_38);
        pushButton_38->setObjectName(QString::fromUtf8("pushButton_38"));

        gridLayout->addWidget(pushButton_38, 2, 4, 1, 1);

        pushButton_39 = new QPushButton(tab);
        charButtonGroup->addButton(pushButton_39);
        pushButton_39->setObjectName(QString::fromUtf8("pushButton_39"));

        gridLayout->addWidget(pushButton_39, 2, 5, 1, 1);

        pushButton_40 = new QPushButton(tab);
        charButtonGroup->addButton(pushButton_40);
        pushButton_40->setObjectName(QString::fromUtf8("pushButton_40"));

        gridLayout->addWidget(pushButton_40, 2, 6, 1, 1);

        pushButton_10 = new QPushButton(tab);
        charButtonGroup->addButton(pushButton_10);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));

        gridLayout->addWidget(pushButton_10, 2, 7, 1, 1);

        shiftBtn = new QPushButton(tab);
        shiftBtn->setObjectName(QString::fromUtf8("shiftBtn"));
        QFont font;
        font.setFamily(QString::fromUtf8("Times New Roman"));
        font.setPointSize(12);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(9);
        shiftBtn->setFont(font);
        shiftBtn->setStyleSheet(QString::fromUtf8("font: 75 12pt \"Times New Roman\";"));

        gridLayout->addWidget(shiftBtn, 2, 8, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        gridLayout_3 = new QGridLayout(tab_2);
        gridLayout_3->setSpacing(3);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(-1, 0, -1, 0);
        pushButton_100 = new QPushButton(tab_2);
        numButtonGroup = new QButtonGroup(DeVirtualKeyboradWidget);
        numButtonGroup->setObjectName(QString::fromUtf8("numButtonGroup"));
        numButtonGroup->addButton(pushButton_100);
        pushButton_100->setObjectName(QString::fromUtf8("pushButton_100"));

        gridLayout_3->addWidget(pushButton_100, 0, 0, 1, 1);

        pushButton_101 = new QPushButton(tab_2);
        numButtonGroup->addButton(pushButton_101);
        pushButton_101->setObjectName(QString::fromUtf8("pushButton_101"));

        gridLayout_3->addWidget(pushButton_101, 0, 1, 1, 1);

        pushButton_102 = new QPushButton(tab_2);
        numButtonGroup->addButton(pushButton_102);
        pushButton_102->setObjectName(QString::fromUtf8("pushButton_102"));

        gridLayout_3->addWidget(pushButton_102, 0, 2, 1, 1);

        pushButton_109 = new QPushButton(tab_2);
        numButtonGroup->addButton(pushButton_109);
        pushButton_109->setObjectName(QString::fromUtf8("pushButton_109"));

        gridLayout_3->addWidget(pushButton_109, 0, 3, 1, 1);

        pushButton_103 = new QPushButton(tab_2);
        numButtonGroup->addButton(pushButton_103);
        pushButton_103->setObjectName(QString::fromUtf8("pushButton_103"));

        gridLayout_3->addWidget(pushButton_103, 1, 0, 1, 1);

        pushButton_104 = new QPushButton(tab_2);
        numButtonGroup->addButton(pushButton_104);
        pushButton_104->setObjectName(QString::fromUtf8("pushButton_104"));

        gridLayout_3->addWidget(pushButton_104, 1, 1, 1, 1);

        pushButton_105 = new QPushButton(tab_2);
        numButtonGroup->addButton(pushButton_105);
        pushButton_105->setObjectName(QString::fromUtf8("pushButton_105"));

        gridLayout_3->addWidget(pushButton_105, 1, 2, 1, 1);

        pushButton_106 = new QPushButton(tab_2);
        numButtonGroup->addButton(pushButton_106);
        pushButton_106->setObjectName(QString::fromUtf8("pushButton_106"));

        gridLayout_3->addWidget(pushButton_106, 2, 0, 1, 1);

        pushButton_107 = new QPushButton(tab_2);
        numButtonGroup->addButton(pushButton_107);
        pushButton_107->setObjectName(QString::fromUtf8("pushButton_107"));

        gridLayout_3->addWidget(pushButton_107, 2, 1, 1, 1);

        pushButton_108 = new QPushButton(tab_2);
        numButtonGroup->addButton(pushButton_108);
        pushButton_108->setObjectName(QString::fromUtf8("pushButton_108"));

        gridLayout_3->addWidget(pushButton_108, 2, 2, 1, 1);

        pushButton_15 = new QPushButton(tab_2);
        numButtonGroup->addButton(pushButton_15);
        pushButton_15->setObjectName(QString::fromUtf8("pushButton_15"));

        gridLayout_3->addWidget(pushButton_15, 1, 3, 1, 1);

        tabWidget->addTab(tab_2, QString());

        gridLayout_2->addWidget(tabWidget, 0, 0, 4, 1);

        spaceBtn = new QPushButton(widget);
        spaceBtn->setObjectName(QString::fromUtf8("spaceBtn"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\226\260\345\256\213\344\275\223"));
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        spaceBtn->setFont(font1);
        spaceBtn->setStyleSheet(QString::fromUtf8("font: 12pt \"\346\226\260\345\256\213\344\275\223\";\n"
""));

        gridLayout_2->addWidget(spaceBtn, 0, 1, 1, 1);

        backBtn = new QPushButton(widget);
        backBtn->setObjectName(QString::fromUtf8("backBtn"));
        backBtn->setFont(font1);
        backBtn->setStyleSheet(QString::fromUtf8("font: 12pt \"\346\226\260\345\256\213\344\275\223\";\n"
""));

        gridLayout_2->addWidget(backBtn, 1, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 3, 1, 1, 1);

        hideBtn = new QPushButton(widget);
        hideBtn->setObjectName(QString::fromUtf8("hideBtn"));
        hideBtn->setStyleSheet(QString::fromUtf8("font: 12pt \"\346\226\260\345\256\213\344\275\223\";\n"
""));

        gridLayout_2->addWidget(hideBtn, 2, 1, 1, 1);


        gridLayout_4->addWidget(widget, 1, 1, 2, 1);

        verticalSpacer_3 = new QSpacerItem(20, 157, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer_3, 3, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(155, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer, 1, 2, 1, 1);


        retranslateUi(DeVirtualKeyboradWidget);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(DeVirtualKeyboradWidget);
    } // setupUi

    void retranslateUi(QWidget *DeVirtualKeyboradWidget)
    {
        DeVirtualKeyboradWidget->setWindowTitle(QApplication::translate("DeVirtualKeyboradWidget", "DeVirtualKeyboradWidget", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("DeVirtualKeyboradWidget", "q", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("DeVirtualKeyboradWidget", "w", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("DeVirtualKeyboradWidget", "e", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("DeVirtualKeyboradWidget", "r", 0, QApplication::UnicodeUTF8));
        pushButton_5->setText(QApplication::translate("DeVirtualKeyboradWidget", "t", 0, QApplication::UnicodeUTF8));
        pushButton_6->setText(QApplication::translate("DeVirtualKeyboradWidget", "y", 0, QApplication::UnicodeUTF8));
        pushButton_7->setText(QApplication::translate("DeVirtualKeyboradWidget", "u", 0, QApplication::UnicodeUTF8));
        pushButton_8->setText(QApplication::translate("DeVirtualKeyboradWidget", "i", 0, QApplication::UnicodeUTF8));
        pushButton_9->setText(QApplication::translate("DeVirtualKeyboradWidget", "o", 0, QApplication::UnicodeUTF8));
        pushButton_11->setText(QApplication::translate("DeVirtualKeyboradWidget", "a", 0, QApplication::UnicodeUTF8));
        pushButton_12->setText(QApplication::translate("DeVirtualKeyboradWidget", "s", 0, QApplication::UnicodeUTF8));
        pushButton_13->setText(QApplication::translate("DeVirtualKeyboradWidget", "d", 0, QApplication::UnicodeUTF8));
        pushButton_14->setText(QApplication::translate("DeVirtualKeyboradWidget", "f", 0, QApplication::UnicodeUTF8));
        pushButton_29->setText(QApplication::translate("DeVirtualKeyboradWidget", "g", 0, QApplication::UnicodeUTF8));
        pushButton_30->setText(QApplication::translate("DeVirtualKeyboradWidget", "h", 0, QApplication::UnicodeUTF8));
        pushButton_31->setText(QApplication::translate("DeVirtualKeyboradWidget", "j", 0, QApplication::UnicodeUTF8));
        pushButton_32->setText(QApplication::translate("DeVirtualKeyboradWidget", "k", 0, QApplication::UnicodeUTF8));
        pushButton_33->setText(QApplication::translate("DeVirtualKeyboradWidget", "l", 0, QApplication::UnicodeUTF8));
        pushButton_34->setText(QApplication::translate("DeVirtualKeyboradWidget", "z", 0, QApplication::UnicodeUTF8));
        pushButton_35->setText(QApplication::translate("DeVirtualKeyboradWidget", "x", 0, QApplication::UnicodeUTF8));
        pushButton_36->setText(QApplication::translate("DeVirtualKeyboradWidget", "c", 0, QApplication::UnicodeUTF8));
        pushButton_37->setText(QApplication::translate("DeVirtualKeyboradWidget", "v", 0, QApplication::UnicodeUTF8));
        pushButton_38->setText(QApplication::translate("DeVirtualKeyboradWidget", "b", 0, QApplication::UnicodeUTF8));
        pushButton_39->setText(QApplication::translate("DeVirtualKeyboradWidget", "n", 0, QApplication::UnicodeUTF8));
        pushButton_40->setText(QApplication::translate("DeVirtualKeyboradWidget", "m", 0, QApplication::UnicodeUTF8));
        pushButton_10->setText(QApplication::translate("DeVirtualKeyboradWidget", "p", 0, QApplication::UnicodeUTF8));
        shiftBtn->setText(QApplication::translate("DeVirtualKeyboradWidget", "\344\270\212\346\241\243", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("DeVirtualKeyboradWidget", "\345\255\227\346\257\215", 0, QApplication::UnicodeUTF8));
        pushButton_100->setText(QApplication::translate("DeVirtualKeyboradWidget", "1", 0, QApplication::UnicodeUTF8));
        pushButton_101->setText(QApplication::translate("DeVirtualKeyboradWidget", "2", 0, QApplication::UnicodeUTF8));
        pushButton_102->setText(QApplication::translate("DeVirtualKeyboradWidget", "3", 0, QApplication::UnicodeUTF8));
        pushButton_109->setText(QApplication::translate("DeVirtualKeyboradWidget", "0", 0, QApplication::UnicodeUTF8));
        pushButton_103->setText(QApplication::translate("DeVirtualKeyboradWidget", "4", 0, QApplication::UnicodeUTF8));
        pushButton_104->setText(QApplication::translate("DeVirtualKeyboradWidget", "5", 0, QApplication::UnicodeUTF8));
        pushButton_105->setText(QApplication::translate("DeVirtualKeyboradWidget", "6", 0, QApplication::UnicodeUTF8));
        pushButton_106->setText(QApplication::translate("DeVirtualKeyboradWidget", "7", 0, QApplication::UnicodeUTF8));
        pushButton_107->setText(QApplication::translate("DeVirtualKeyboradWidget", "8", 0, QApplication::UnicodeUTF8));
        pushButton_108->setText(QApplication::translate("DeVirtualKeyboradWidget", "9", 0, QApplication::UnicodeUTF8));
        pushButton_15->setText(QApplication::translate("DeVirtualKeyboradWidget", ".", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("DeVirtualKeyboradWidget", "\346\225\260\345\255\227", 0, QApplication::UnicodeUTF8));
        spaceBtn->setText(QApplication::translate("DeVirtualKeyboradWidget", "\347\251\272\346\240\274", 0, QApplication::UnicodeUTF8));
        backBtn->setText(QApplication::translate("DeVirtualKeyboradWidget", "\345\233\236\351\200\200", 0, QApplication::UnicodeUTF8));
        hideBtn->setText(QApplication::translate("DeVirtualKeyboradWidget", "\351\232\220\350\227\217", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DeVirtualKeyboradWidget: public Ui_DeVirtualKeyboradWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEVIRTUALKEYBORADWIDGET_H
