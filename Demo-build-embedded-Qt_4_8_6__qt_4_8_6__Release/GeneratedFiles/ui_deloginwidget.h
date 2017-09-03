/********************************************************************************
** Form generated from reading UI file 'deloginwidget.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELOGINWIDGET_H
#define UI_DELOGINWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>
#include <devirtualkeyboradwidget.h>

QT_BEGIN_NAMESPACE

class Ui_DeLoginWidget
{
public:
    QGridLayout *gridLayout_5;
    QWidget *widget_3;
    QGridLayout *gridLayout_2;
    QWidget *widget_2;
    QGridLayout *gridLayout_7;
    QWidget *widget;
    QGridLayout *gridLayout_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *userLineEdit;
    QGridLayout *gridLayout_6;
    QLabel *label_2;
    QLineEdit *passwdLineEdit;
    DeVirtualKeyboradWidget *keyBoradWidget;

    void setupUi(QWidget *DeLoginWidget)
    {
        if (DeLoginWidget->objectName().isEmpty())
            DeLoginWidget->setObjectName(QString::fromUtf8("DeLoginWidget"));
        DeLoginWidget->resize(640, 480);
        gridLayout_5 = new QGridLayout(DeLoginWidget);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        widget_3 = new QWidget(DeLoginWidget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        gridLayout_2 = new QGridLayout(widget_3);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        widget_2 = new QWidget(widget_3);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setMinimumSize(QSize(300, 140));
        widget_2->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
"border:1px solid gray;\n"
"border-radius:5px;\n"
"min-height:30px;\n"
"font: 16pt \"\346\226\260\345\256\213\344\275\223\";\n"
"}\n"
"\n"
"QLabel\n"
"{\n"
"font: 14pt \"\346\226\260\345\256\213\344\275\223\";\n"
"color:gray;\n"
"}\n"
"\n"
"QGroupBox {\n"
"     border: 1px solid gray;\n"
"     border-radius: 3px;\n"
"     margin-top: 2ex; /* leave space at the top for the title */\n"
"     padding: 10px;\n"
"     font: 12pt \"\346\226\260\345\256\213\344\275\223\";\n"
"color:gray;\n"
" }\n"
"\n"
" QGroupBox::title {\n"
"     subcontrol-origin: margin;\n"
"     subcontrol-position: top center; /* position at the top center */\n"
"     padding: 0 10px;\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #FFOECE, stop: 1 #FFFFFF);\n"
" }\n"
"\n"
"QPushButton {\n"
"    \n"
"	font: bold 16pt \"\346\226\260\345\256\213\344\275\223\";\n"
"	background-color: rgb(244, 244, 244);\n"
"    border: 0px solid #8f8f91;\n"
"    border-rad"
                        "ius: 5px;\n"
"    min-width: 100px;\n"
"    min-height: 38px;\n"
" }\n"
"\n"
" QPushButton:pressed {\n"
"	background-color: rgb(255, 255, 255);\n"
" }\n"
"\n"
"QPushButton::focus\n"
"{\n"
"    color: rgb(254, 255, 253);\n"
"    background-color: rgb(66, 189, 170);\n"
"}\n"
"\n"
"QPushButton::!focus\n"
"{    \n"
"	color: rgb(0, 0, 0);\n"
"    background-color: rgb(255, 255, 255);\n"
"}\n"
"\n"
""));
        gridLayout_7 = new QGridLayout(widget_2);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setContentsMargins(-1, 0, -1, 0);
        widget = new QWidget(widget_2);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setStyleSheet(QString::fromUtf8("max-width:280px;\n"
"max-height:180px;"));
        gridLayout_4 = new QGridLayout(widget);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setVerticalSpacing(10);
        horizontalSpacer = new QSpacerItem(17, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer, 1, 0, 1, 1);

        okBtn = new QPushButton(widget);
        okBtn->setObjectName(QString::fromUtf8("okBtn"));
        okBtn->setMaximumSize(QSize(280, 180));
        okBtn->setFocusPolicy(Qt::StrongFocus);

        gridLayout_4->addWidget(okBtn, 1, 1, 1, 1);

        cancelBtn = new QPushButton(widget);
        cancelBtn->setObjectName(QString::fromUtf8("cancelBtn"));
        cancelBtn->setMaximumSize(QSize(280, 180));

        gridLayout_4->addWidget(cancelBtn, 1, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(28, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_2, 1, 3, 1, 1);

        groupBox = new QGroupBox(widget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMaximumSize(QSize(302, 220));
        groupBox->setStyleSheet(QString::fromUtf8(""));
        gridLayout_3 = new QGridLayout(groupBox);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(3, 3, 3, 3);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(0, 0));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        userLineEdit = new QLineEdit(groupBox);
        userLineEdit->setObjectName(QString::fromUtf8("userLineEdit"));
        userLineEdit->setMaxLength(32);

        gridLayout->addWidget(userLineEdit, 0, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout, 0, 0, 1, 1);

        gridLayout_6 = new QGridLayout();
        gridLayout_6->setSpacing(6);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setHorizontalSpacing(6);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(0, 0));

        gridLayout_6->addWidget(label_2, 0, 0, 1, 1);

        passwdLineEdit = new QLineEdit(groupBox);
        passwdLineEdit->setObjectName(QString::fromUtf8("passwdLineEdit"));
        passwdLineEdit->setMaxLength(32);
        passwdLineEdit->setEchoMode(QLineEdit::Password);

        gridLayout_6->addWidget(passwdLineEdit, 0, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout_6, 1, 0, 1, 1);


        gridLayout_4->addWidget(groupBox, 0, 0, 1, 4);


        gridLayout_7->addWidget(widget, 0, 0, 1, 1);


        gridLayout_2->addWidget(widget_2, 0, 0, 1, 1);

        keyBoradWidget = new DeVirtualKeyboradWidget(widget_3);
        keyBoradWidget->setObjectName(QString::fromUtf8("keyBoradWidget"));

        gridLayout_2->addWidget(keyBoradWidget, 1, 0, 1, 1);


        gridLayout_5->addWidget(widget_3, 0, 0, 1, 1);


        retranslateUi(DeLoginWidget);

        QMetaObject::connectSlotsByName(DeLoginWidget);
    } // setupUi

    void retranslateUi(QWidget *DeLoginWidget)
    {
        DeLoginWidget->setWindowTitle(QApplication::translate("DeLoginWidget", "DeLoginWidget", 0, QApplication::UnicodeUTF8));
        okBtn->setText(QApplication::translate("DeLoginWidget", "\347\231\273\345\275\225", 0, QApplication::UnicodeUTF8));
        cancelBtn->setText(QApplication::translate("DeLoginWidget", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("DeLoginWidget", "\347\231\273\345\275\225", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("DeLoginWidget", "\347\224\250\346\210\267\345\220\215", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("DeLoginWidget", "\345\257\206   \347\240\201", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DeLoginWidget: public Ui_DeLoginWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELOGINWIDGET_H
