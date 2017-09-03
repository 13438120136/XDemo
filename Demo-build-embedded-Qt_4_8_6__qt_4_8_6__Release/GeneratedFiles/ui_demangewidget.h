/********************************************************************************
** Form generated from reading UI file 'demangewidget.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEMANGEWIDGET_H
#define UI_DEMANGEWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTabWidget>
#include <QtGui/QWidget>
#include <detableview.h>

QT_BEGIN_NAMESPACE

class Ui_DeMangeWidget
{
public:
    QGridLayout *gridLayout_4;
    QWidget *widget_3;
    QGridLayout *gridLayout_2;
    QPushButton *funcBtn;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *userBtn;
    QPushButton *radioBtn;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *logoutBtn;
    QFrame *line;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout;
    QPushButton *delUserBtn;
    QPushButton *addUserBtn;
    QSpacerItem *horizontalSpacer;
    QPushButton *changeUserBtn;
    DeTableView *widget;
    QWidget *tab_2;
    QGridLayout *gridLayout_6;
    QGridLayout *gridLayout_5;
    QPushButton *delRadioactivityBtn;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *addRadioactivityBtn;
    QPushButton *modifyRadioactivityBtn;
    DeTableView *widget_2;

    void setupUi(QWidget *DeMangeWidget)
    {
        if (DeMangeWidget->objectName().isEmpty())
            DeMangeWidget->setObjectName(QString::fromUtf8("DeMangeWidget"));
        DeMangeWidget->resize(640, 480);
        DeMangeWidget->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    \n"
"	font: 16pt \"\346\226\260\345\256\213\344\275\223\";\n"
"	background-color: rgb(244, 244, 244);\n"
"     border: 1px solid #8f8f91;\n"
"     border-radius: 6px;\n"
"     min-width: 100px;\n"
"     min-height: 30px;\n"
" }\n"
"\n"
"QTabWidget::pane\n"
"{   \n"
"	background-color: rgb(255, 255, 255);\n"
"    border: 0px;\n"
"}\n"
"\n"
" QPushButton:pressed {\n"
"	background-color: rgb(255, 255, 255);\n"
" }\n"
"\n"
"QTabWidget::tab-bar {\n"
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
" "
                        "    padding-bottom:6px;\n"
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
"\n"
" QTabBar::tab:!selected {\n"
"     margin-top: 2px; /* make non-selected tabs look smaller */\n"
" }"));
        gridLayout_4 = new QGridLayout(DeMangeWidget);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setHorizontalSpacing(0);
        gridLayout_4->setVerticalSpacing(2);
        gridLayout_4->setContentsMargins(9, 0, 9, 0);
        widget_3 = new QWidget(DeMangeWidget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setStyleSheet(QString::fromUtf8("QPushButton\n"
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
        gridLayout_2 = new QGridLayout(widget_3);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        funcBtn = new QPushButton(widget_3);
        funcBtn->setObjectName(QString::fromUtf8("funcBtn"));

        gridLayout_2->addWidget(funcBtn, 0, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(108, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 0, 1, 1, 1);

        userBtn = new QPushButton(widget_3);
        userBtn->setObjectName(QString::fromUtf8("userBtn"));

        gridLayout_2->addWidget(userBtn, 0, 2, 1, 1);

        radioBtn = new QPushButton(widget_3);
        radioBtn->setObjectName(QString::fromUtf8("radioBtn"));

        gridLayout_2->addWidget(radioBtn, 0, 3, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(108, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 0, 4, 1, 1);

        logoutBtn = new QPushButton(widget_3);
        logoutBtn->setObjectName(QString::fromUtf8("logoutBtn"));

        gridLayout_2->addWidget(logoutBtn, 0, 5, 1, 1);


        gridLayout_4->addWidget(widget_3, 0, 0, 1, 1);

        line = new QFrame(DeMangeWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_4->addWidget(line, 1, 0, 1, 1);

        tabWidget = new QTabWidget(DeMangeWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout_3 = new QGridLayout(tab);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        delUserBtn = new QPushButton(tab);
        delUserBtn->setObjectName(QString::fromUtf8("delUserBtn"));
        delUserBtn->setMinimumSize(QSize(102, 32));

        gridLayout->addWidget(delUserBtn, 0, 3, 1, 1);

        addUserBtn = new QPushButton(tab);
        addUserBtn->setObjectName(QString::fromUtf8("addUserBtn"));
        addUserBtn->setMinimumSize(QSize(102, 32));

        gridLayout->addWidget(addUserBtn, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 0, 1, 1);

        changeUserBtn = new QPushButton(tab);
        changeUserBtn->setObjectName(QString::fromUtf8("changeUserBtn"));
        changeUserBtn->setMinimumSize(QSize(102, 32));

        gridLayout->addWidget(changeUserBtn, 0, 2, 1, 1);


        gridLayout_3->addLayout(gridLayout, 0, 0, 1, 1);

        widget = new DeTableView(tab);
        widget->setObjectName(QString::fromUtf8("widget"));

        gridLayout_3->addWidget(widget, 1, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        gridLayout_6 = new QGridLayout(tab_2);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setSpacing(6);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        delRadioactivityBtn = new QPushButton(tab_2);
        delRadioactivityBtn->setObjectName(QString::fromUtf8("delRadioactivityBtn"));
        delRadioactivityBtn->setMinimumSize(QSize(102, 32));

        gridLayout_5->addWidget(delRadioactivityBtn, 0, 3, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_4, 0, 0, 1, 1);

        addRadioactivityBtn = new QPushButton(tab_2);
        addRadioactivityBtn->setObjectName(QString::fromUtf8("addRadioactivityBtn"));
        addRadioactivityBtn->setMinimumSize(QSize(102, 32));

        gridLayout_5->addWidget(addRadioactivityBtn, 0, 1, 1, 1);

        modifyRadioactivityBtn = new QPushButton(tab_2);
        modifyRadioactivityBtn->setObjectName(QString::fromUtf8("modifyRadioactivityBtn"));
        modifyRadioactivityBtn->setMinimumSize(QSize(102, 32));

        gridLayout_5->addWidget(modifyRadioactivityBtn, 0, 2, 1, 1);


        gridLayout_6->addLayout(gridLayout_5, 0, 0, 1, 1);

        widget_2 = new DeTableView(tab_2);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));

        gridLayout_6->addWidget(widget_2, 1, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());

        gridLayout_4->addWidget(tabWidget, 2, 0, 1, 1);


        retranslateUi(DeMangeWidget);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(DeMangeWidget);
    } // setupUi

    void retranslateUi(QWidget *DeMangeWidget)
    {
        DeMangeWidget->setWindowTitle(QApplication::translate("DeMangeWidget", "DeUserWidget", 0, QApplication::UnicodeUTF8));
        funcBtn->setText(QApplication::translate("DeMangeWidget", "\345\212\237\350\203\275\351\200\211\346\213\251", 0, QApplication::UnicodeUTF8));
        userBtn->setText(QApplication::translate("DeMangeWidget", "\347\224\250\346\210\267\347\256\241\347\220\206", 0, QApplication::UnicodeUTF8));
        radioBtn->setText(QApplication::translate("DeMangeWidget", "\346\224\276\345\260\204\346\272\220\347\256\241\347\220\206", 0, QApplication::UnicodeUTF8));
        logoutBtn->setText(QApplication::translate("DeMangeWidget", "\346\263\250\351\224\200", 0, QApplication::UnicodeUTF8));
        delUserBtn->setText(QApplication::translate("DeMangeWidget", "\345\210\240\351\231\244\347\224\250\346\210\267", 0, QApplication::UnicodeUTF8));
        addUserBtn->setText(QApplication::translate("DeMangeWidget", "\346\267\273\345\212\240\347\224\250\346\210\267", 0, QApplication::UnicodeUTF8));
        changeUserBtn->setText(QApplication::translate("DeMangeWidget", "\344\277\256\346\224\271\347\224\250\346\210\267", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("DeMangeWidget", "\347\224\250\346\210\267\347\256\241\347\220\206", 0, QApplication::UnicodeUTF8));
        delRadioactivityBtn->setText(QApplication::translate("DeMangeWidget", "\345\210\240\351\231\244\350\256\260\345\275\225", 0, QApplication::UnicodeUTF8));
        addRadioactivityBtn->setText(QApplication::translate("DeMangeWidget", "\346\267\273\345\212\240\350\256\260\345\275\225", 0, QApplication::UnicodeUTF8));
        modifyRadioactivityBtn->setText(QApplication::translate("DeMangeWidget", "\344\277\256\346\224\271\350\256\260\345\275\225", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("DeMangeWidget", "\346\224\276\345\260\204\346\272\220\347\256\241\347\220\206", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DeMangeWidget: public Ui_DeMangeWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEMANGEWIDGET_H
