/********************************************************************************
** Form generated from reading UI file 'detableview.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DETABLEVIEW_H
#define UI_DETABLEVIEW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DeTableView
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QPushButton *firstBtn;
    QPushButton *lastBtn;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *nextBtn;
    QPushButton *prevBtn;
    QLabel *label;
    QTableView *tableView;

    void setupUi(QWidget *DeTableView)
    {
        if (DeTableView->objectName().isEmpty())
            DeTableView->setObjectName(QString::fromUtf8("DeTableView"));
        DeTableView->resize(596, 330);
        DeTableView->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    \n"
"	font: 16pt \"\346\226\260\345\256\213\344\275\223\";\n"
"	background-color: rgb(244, 244, 244);\n"
"     border: 1px solid #8f8f91;\n"
"     border-radius: 6px;\n"
"     min-width: 80px;\n"
"     min-height: 30px;\n"
" }\n"
"\n"
"QLabel\n"
"{\n"
"    padding-left:15px;\n"
"    padding-right:15px;\n"
"    min-width:40px;\n"
"}\n"
"\n"
" QPushButton:pressed {\n"
"	background-color: rgb(255, 255, 255);\n"
" }\n"
"\n"
"QTableView\n"
"{\n"
"	font: bold 12pt \"\345\256\213\344\275\223\";\n"
"    border:none;\n"
"}\n"
"\n"
" QTableView QTableCornerButton::section\n"
" {\n"
"     background: white;\n"
"     border: 0px outset rgb(209, 209, 209);\n"
"     border-bottom-width:1px;\n"
"     border-right-width:1px;\n"
" }\n"
"\n"
"\n"
"QHeaderView::section\n"
"{\n"
"	background-color: rgb(130, 130, 130);\n"
"    color: rgb(255, 255, 255);\n"
"    border: 0px solid white;\n"
"	border-color: rgb(209, 209, 209);	\n"
"	border-top-width:0px;\n"
"	border-bottom-width:1px;	\n"
"	border-right-width:1px"
                        ";\n"
"	border-left-width:0px;\n"
"}\n"
"\n"
"QHeaderView\n"
"{\n"
"   min-height:25px;\n"
"   font: bold 12pt \"\345\256\213\344\275\223\";\n"
"}"));
        gridLayout_2 = new QGridLayout(DeTableView);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        firstBtn = new QPushButton(DeTableView);
        firstBtn->setObjectName(QString::fromUtf8("firstBtn"));

        gridLayout->addWidget(firstBtn, 0, 2, 1, 1);

        lastBtn = new QPushButton(DeTableView);
        lastBtn->setObjectName(QString::fromUtf8("lastBtn"));

        gridLayout->addWidget(lastBtn, 0, 6, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 7, 1, 1);

        nextBtn = new QPushButton(DeTableView);
        nextBtn->setObjectName(QString::fromUtf8("nextBtn"));

        gridLayout->addWidget(nextBtn, 0, 5, 1, 1);

        prevBtn = new QPushButton(DeTableView);
        prevBtn->setObjectName(QString::fromUtf8("prevBtn"));

        gridLayout->addWidget(prevBtn, 0, 3, 1, 1);

        label = new QLabel(DeTableView);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\256\213\344\275\223\";"));

        gridLayout->addWidget(label, 0, 4, 1, 1);


        gridLayout_2->addLayout(gridLayout, 1, 0, 1, 1);

        tableView = new QTableView(DeTableView);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setShowGrid(true);
        tableView->verticalHeader()->setVisible(false);
        tableView->verticalHeader()->setDefaultSectionSize(40);

        gridLayout_2->addWidget(tableView, 0, 0, 1, 1);


        retranslateUi(DeTableView);

        QMetaObject::connectSlotsByName(DeTableView);
    } // setupUi

    void retranslateUi(QWidget *DeTableView)
    {
        DeTableView->setWindowTitle(QApplication::translate("DeTableView", "DeTableView", 0, QApplication::UnicodeUTF8));
        firstBtn->setText(QApplication::translate("DeTableView", "\351\246\226\351\241\265", 0, QApplication::UnicodeUTF8));
        lastBtn->setText(QApplication::translate("DeTableView", "\346\234\253\351\241\265", 0, QApplication::UnicodeUTF8));
        nextBtn->setText(QApplication::translate("DeTableView", "\344\270\213\344\270\200\351\241\265", 0, QApplication::UnicodeUTF8));
        prevBtn->setText(QApplication::translate("DeTableView", "\344\270\212\344\270\200\351\241\265", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("DeTableView", "TextLabel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DeTableView: public Ui_DeTableView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DETABLEVIEW_H
