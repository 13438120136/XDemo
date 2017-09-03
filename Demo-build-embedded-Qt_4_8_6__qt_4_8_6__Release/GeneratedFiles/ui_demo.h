/********************************************************************************
** Form generated from reading UI file 'demo.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEMO_H
#define UI_DEMO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QStackedWidget>
#include <QtGui/QWidget>
#include <deinitwidget.h>

QT_BEGIN_NAMESPACE

class Ui_DemoClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QStackedWidget *contentWidget;
    QWidget *page;
    QGridLayout *gridLayout;
    DeInitWidget *widget;

    void setupUi(QMainWindow *DemoClass)
    {
        if (DemoClass->objectName().isEmpty())
            DemoClass->setObjectName(QString::fromUtf8("DemoClass"));
        DemoClass->resize(773, 594);
        DemoClass->setStyleSheet(QString::fromUtf8("QStatusBar {\n"
"	background-color: rgb(117, 161, 255);\n"
"}\n"
"\n"
"QStatusBar::item {\n"
"    border: 1px solid red;\n"
"    border-radius: 3px;\n"
"}\n"
""));
        centralWidget = new QWidget(DemoClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"     outline:none;\n"
"}"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        contentWidget = new QStackedWidget(centralWidget);
        contentWidget->setObjectName(QString::fromUtf8("contentWidget"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        gridLayout = new QGridLayout(page);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        widget = new DeInitWidget(page);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(widget, 0, 0, 1, 1);

        gridLayout->setRowStretch(0, 8);
        contentWidget->addWidget(page);

        gridLayout_2->addWidget(contentWidget, 0, 0, 1, 1);

        DemoClass->setCentralWidget(centralWidget);

        retranslateUi(DemoClass);

        contentWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(DemoClass);
    } // setupUi

    void retranslateUi(QMainWindow *DemoClass)
    {
        DemoClass->setWindowTitle(QApplication::translate("DemoClass", "Demo", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DemoClass: public Ui_DemoClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEMO_H
