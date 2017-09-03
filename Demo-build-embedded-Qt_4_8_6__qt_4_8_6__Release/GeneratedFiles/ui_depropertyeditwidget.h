/********************************************************************************
** Form generated from reading UI file 'depropertyeditwidget.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEPROPERTYEDITWIDGET_H
#define UI_DEPROPERTYEDITWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>
#include <devirtualkeyboradwidget.h>

QT_BEGIN_NAMESPACE

class Ui_DePropertyEditWidget
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnOk;
    QPushButton *btnCancel;
    DeVirtualKeyboradWidget *virtualBoradWidget;
    QWidget *widget;
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QLineEdit *lineEdit;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *DePropertyEditWidget)
    {
        if (DePropertyEditWidget->objectName().isEmpty())
            DePropertyEditWidget->setObjectName(QString::fromUtf8("DePropertyEditWidget"));
        DePropertyEditWidget->resize(628, 442);
        DePropertyEditWidget->setStyleSheet(QString::fromUtf8("QLineEdit\n"
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
"min-width:60px;\n"
"}\n"
"\n"
"QGroupBox {\n"
"     border: 1px solid gray;\n"
"     border-radius: 3px;\n"
"     margin-top: 2ex; /* leave space at the top for the title */\n"
"     padding: 10px;\n"
"     margin:10px;\n"
"     font: 12pt \"\346\226\260\345\256\213\344\275\223\";\n"
" }\n"
"\n"
" QGroupBox::title {     \n"
"     subcontrol-origin: margin;\n"
"     subcontrol-position: top center; /* position at the top center */\n"
"     padding: 0 10px;\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #FFOECE, stop: 1 #FFFFFF);\n"
" }\n"
"\n"
"QPushButton {\n"
"    \n"
"	font: 16pt \"\346\226\260\345\256\213\344\275\223\";\n"
"	background-color: rgb(244, 244, 244);\n"
"    border: 1px solid #8f8f91;\n"
"    "
                        "border-radius: 6px;\n"
"    min-width: 100px;\n"
"    min-height: 38px;\n"
" }\n"
"\n"
" QPushButton:pressed {\n"
"	background-color: rgb(255, 255, 255);\n"
" }\n"
""));
        gridLayout = new QGridLayout(DePropertyEditWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer = new QSpacerItem(391, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 0, 1, 1);

        btnOk = new QPushButton(DePropertyEditWidget);
        btnOk->setObjectName(QString::fromUtf8("btnOk"));

        gridLayout->addWidget(btnOk, 2, 1, 1, 1);

        btnCancel = new QPushButton(DePropertyEditWidget);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        gridLayout->addWidget(btnCancel, 2, 2, 1, 1);

        virtualBoradWidget = new DeVirtualKeyboradWidget(DePropertyEditWidget);
        virtualBoradWidget->setObjectName(QString::fromUtf8("virtualBoradWidget"));

        gridLayout->addWidget(virtualBoradWidget, 1, 0, 1, 3);

        widget = new QWidget(DePropertyEditWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout_3 = new QGridLayout(widget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        groupBox = new QGroupBox(widget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setStyleSheet(QString::fromUtf8("max-width:280px;\n"
"max-height:100px;"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setMaxLength(32);

        gridLayout_2->addWidget(lineEdit, 1, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 2, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 0, 0, 1, 1);


        gridLayout_3->addWidget(groupBox, 0, 0, 1, 1);


        gridLayout->addWidget(widget, 0, 0, 1, 3);


        retranslateUi(DePropertyEditWidget);

        QMetaObject::connectSlotsByName(DePropertyEditWidget);
    } // setupUi

    void retranslateUi(QWidget *DePropertyEditWidget)
    {
        DePropertyEditWidget->setWindowTitle(QApplication::translate("DePropertyEditWidget", "DePropertyEditWidget", 0, QApplication::UnicodeUTF8));
        btnOk->setText(QApplication::translate("DePropertyEditWidget", "\344\277\235\345\255\230", 0, QApplication::UnicodeUTF8));
        btnCancel->setText(QApplication::translate("DePropertyEditWidget", "\351\200\200\345\207\272", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("DePropertyEditWidget", "GroupBox", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DePropertyEditWidget: public Ui_DePropertyEditWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEPROPERTYEDITWIDGET_H
