/********************************************************************************
** Form generated from reading UI file 'demenuwidget.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEMENUWIDGET_H
#define UI_DEMENUWIDGET_H

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

class Ui_DeMenuWidget
{
public:
    QGridLayout *gridLayout_10;
    QWidget *widget_2;
    QGridLayout *gridLayout_9;
    QGridLayout *gridLayout;
    QWidget *widget;
    QGridLayout *gridLayout_8;
    QGridLayout *gridLayout_7;
    QLabel *label_7;
    QPushButton *exitBtn;
    QGridLayout *gridLayout_4;
    QLabel *label_4;
    QPushButton *systemCfgBtn;
    QFrame *line_5;
    QFrame *line_2;
    QFrame *line_6;
    QFrame *line_3;
    QFrame *line_4;
    QGridLayout *gridLayout_3;
    QLabel *label_3;
    QPushButton *userBtn;
    QGridLayout *gridLayout_5;
    QLabel *label_5;
    QPushButton *systemTestBtn;
    QGridLayout *gridLayout_6;
    QLabel *label_6;
    QPushButton *logBtn;
    QLabel *label_8;
    QFrame *line;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *DeMenuWidget)
    {
        if (DeMenuWidget->objectName().isEmpty())
            DeMenuWidget->setObjectName(QString::fromUtf8("DeMenuWidget"));
        DeMenuWidget->resize(819, 527);
        DeMenuWidget->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"background-color: rgb(255, 255, 255);\n"
"border:0px solid gray;\n"
"font: 12pt \"\345\256\213\344\275\223\";\n"
"padding-top:15px;\n"
"padding-bottom:15px;\n"
"padding-left:25px;\n"
"width:150px;\n"
"text-align:left;\n"
"min-height:20px;\n"
"outline:none;\n"
"}\n"
"\n"
"QLabel\n"
"{\n"
"   min-height:45px;\n"
"   font: bold 12pt \"\345\256\213\344\275\223\";\n"
"}\n"
"\n"
"QWidget#widget\n"
"{\n"
"	background-color: rgb(255, 255, 255);\n"
"}\n"
""));
        gridLayout_10 = new QGridLayout(DeMenuWidget);
        gridLayout_10->setSpacing(6);
        gridLayout_10->setContentsMargins(0, 0, 0, 0);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        widget_2 = new QWidget(DeMenuWidget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        gridLayout_9 = new QGridLayout(widget_2);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(0, 0, 0, 0);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        widget = new QWidget(widget_2);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout_8 = new QGridLayout(widget);
        gridLayout_8->setSpacing(0);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        gridLayout_8->setContentsMargins(20, 0, 0, 0);
        gridLayout_7 = new QGridLayout();
        gridLayout_7->setSpacing(6);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        label_7 = new QLabel(widget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_7->addWidget(label_7, 0, 0, 1, 1);

        exitBtn = new QPushButton(widget);
        exitBtn->setObjectName(QString::fromUtf8("exitBtn"));

        gridLayout_7->addWidget(exitBtn, 0, 1, 1, 1);


        gridLayout_8->addLayout(gridLayout_7, 9, 0, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_4->addWidget(label_4, 0, 0, 1, 1);

        systemCfgBtn = new QPushButton(widget);
        systemCfgBtn->setObjectName(QString::fromUtf8("systemCfgBtn"));

        gridLayout_4->addWidget(systemCfgBtn, 0, 1, 1, 1);


        gridLayout_8->addLayout(gridLayout_4, 3, 0, 1, 1);

        line_5 = new QFrame(widget);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        gridLayout_8->addWidget(line_5, 6, 0, 1, 1);

        line_2 = new QFrame(widget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout_8->addWidget(line_2, 0, 0, 1, 1);

        line_6 = new QFrame(widget);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);

        gridLayout_8->addWidget(line_6, 8, 0, 1, 1);

        line_3 = new QFrame(widget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout_8->addWidget(line_3, 2, 0, 1, 1);

        line_4 = new QFrame(widget);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        gridLayout_8->addWidget(line_4, 4, 0, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_3->addWidget(label_3, 0, 0, 1, 1);

        userBtn = new QPushButton(widget);
        userBtn->setObjectName(QString::fromUtf8("userBtn"));

        gridLayout_3->addWidget(userBtn, 0, 1, 1, 1);


        gridLayout_8->addLayout(gridLayout_3, 1, 0, 1, 1);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setSpacing(6);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        label_5 = new QLabel(widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_5->addWidget(label_5, 0, 0, 1, 1);

        systemTestBtn = new QPushButton(widget);
        systemTestBtn->setObjectName(QString::fromUtf8("systemTestBtn"));

        gridLayout_5->addWidget(systemTestBtn, 0, 1, 1, 1);


        gridLayout_8->addLayout(gridLayout_5, 5, 0, 1, 1);

        gridLayout_6 = new QGridLayout();
        gridLayout_6->setSpacing(6);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        label_6 = new QLabel(widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_6->addWidget(label_6, 0, 0, 1, 1);

        logBtn = new QPushButton(widget);
        logBtn->setObjectName(QString::fromUtf8("logBtn"));

        gridLayout_6->addWidget(logBtn, 0, 1, 1, 1);


        gridLayout_8->addLayout(gridLayout_6, 7, 0, 1, 1);


        gridLayout->addWidget(widget, 1, 0, 1, 1);

        label_8 = new QLabel(widget_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(12);
        font.setBold(true);
        font.setItalic(false);
        font.setWeight(75);
        label_8->setFont(font);
        label_8->setStyleSheet(QString::fromUtf8("background-color: rgb(117, 117, 117);\n"
"color: rgb(255, 255, 255);"));
        label_8->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_8, 0, 0, 1, 1);

        line = new QFrame(widget_2);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 2, 0, 1, 1);


        gridLayout_9->addLayout(gridLayout, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 165, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_9->addItem(verticalSpacer, 1, 0, 1, 1);


        gridLayout_10->addWidget(widget_2, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(596, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_10->addItem(horizontalSpacer, 0, 1, 1, 1);


        retranslateUi(DeMenuWidget);

        QMetaObject::connectSlotsByName(DeMenuWidget);
    } // setupUi

    void retranslateUi(QWidget *DeMenuWidget)
    {
        DeMenuWidget->setWindowTitle(QApplication::translate("DeMenuWidget", "DeMenuWidget", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("DeMenuWidget", "x", 0, QApplication::UnicodeUTF8));
        exitBtn->setText(QApplication::translate("DeMenuWidget", "\351\200\200  \345\207\272", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("DeMenuWidget", "x", 0, QApplication::UnicodeUTF8));
        systemCfgBtn->setText(QApplication::translate("DeMenuWidget", "\347\263\273\347\273\237\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("DeMenuWidget", "x", 0, QApplication::UnicodeUTF8));
        userBtn->setText(QApplication::translate("DeMenuWidget", "\347\256\241  \347\220\206", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("DeMenuWidget", "x", 0, QApplication::UnicodeUTF8));
        systemTestBtn->setText(QApplication::translate("DeMenuWidget", "\347\263\273\347\273\237\346\265\213\350\257\225", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("DeMenuWidget", "x", 0, QApplication::UnicodeUTF8));
        logBtn->setText(QApplication::translate("DeMenuWidget", "\346\227\245  \345\277\227", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("DeMenuWidget", "\345\212\237\350\203\275\351\200\211\346\213\251", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DeMenuWidget: public Ui_DeMenuWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEMENUWIDGET_H
