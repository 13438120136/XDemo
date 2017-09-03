/********************************************************************************
** Form generated from reading UI file 'debottommenuwidget.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEBOTTOMMENUWIDGET_H
#define UI_DEBOTTOMMENUWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DeBottomMenuWidget
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QPushButton *leftBtn;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QPushButton *rightBtn;

    void setupUi(QWidget *DeBottomMenuWidget)
    {
        if (DeBottomMenuWidget->objectName().isEmpty())
            DeBottomMenuWidget->setObjectName(QString::fromUtf8("DeBottomMenuWidget"));
        DeBottomMenuWidget->resize(499, 84);
        DeBottomMenuWidget->setMinimumSize(QSize(0, 0));
        DeBottomMenuWidget->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"background-color: rgb(255, 255, 255, 0.3);\n"
"border:1px solid gray;\n"
"border-radius:3px;\n"
"font: 16pt \"\345\256\213\344\275\223\";\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	background-color: rgb(255, 255, 255);\n"
"    border:2px solid gray;\n"
"    border-radius:3px;\n"
"}\n"
"\n"
""));
        gridLayout_2 = new QGridLayout(DeBottomMenuWidget);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(2);
        gridLayout->setVerticalSpacing(0);
        leftBtn = new QPushButton(DeBottomMenuWidget);
        leftBtn->setObjectName(QString::fromUtf8("leftBtn"));
        leftBtn->setMinimumSize(QSize(0, 0));

        gridLayout->addWidget(leftBtn, 0, 0, 1, 1);

        scrollArea = new QScrollArea(DeBottomMenuWidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setMaximumSize(QSize(16777215, 16777215));
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 465, 80));
        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 0, 1, 1, 1);

        rightBtn = new QPushButton(DeBottomMenuWidget);
        rightBtn->setObjectName(QString::fromUtf8("rightBtn"));
        rightBtn->setMinimumSize(QSize(0, 0));

        gridLayout->addWidget(rightBtn, 0, 2, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(DeBottomMenuWidget);

        QMetaObject::connectSlotsByName(DeBottomMenuWidget);
    } // setupUi

    void retranslateUi(QWidget *DeBottomMenuWidget)
    {
        DeBottomMenuWidget->setWindowTitle(QApplication::translate("DeBottomMenuWidget", "DeBottomMenuWidget", 0, QApplication::UnicodeUTF8));
        leftBtn->setText(QApplication::translate("DeBottomMenuWidget", "<", 0, QApplication::UnicodeUTF8));
        rightBtn->setText(QApplication::translate("DeBottomMenuWidget", ">", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DeBottomMenuWidget: public Ui_DeBottomMenuWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEBOTTOMMENUWIDGET_H
