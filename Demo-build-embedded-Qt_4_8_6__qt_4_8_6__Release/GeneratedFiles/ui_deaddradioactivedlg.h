/********************************************************************************
** Form generated from reading UI file 'deaddradioactivedlg.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEADDRADIOACTIVEDLG_H
#define UI_DEADDRADIOACTIVEDLG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDateEdit>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>
#include <decombobox.h>
#include <devirtualkeyboradwidget.h>

QT_BEGIN_NAMESPACE

class Ui_DeAddRadioactiveDlg
{
public:
    QGridLayout *gridLayout_4;
    QWidget *widget_4;
    QGridLayout *gridLayout_3;
    QWidget *widget;
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_8;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QLineEdit *idLineEdit;
    QGridLayout *gridLayout_7;
    QLabel *label_3;
    QLineEdit *originalLineEdit;
    QGridLayout *gridLayout_5;
    QLabel *label_2;
    QDateEdit *dateEdit;
    QGridLayout *gridLayout_6;
    QLabel *label_4;
    DeComboBox *widget_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QSpacerItem *horizontalSpacer_2;
    DeVirtualKeyboradWidget *keyBoradWidget;

    void setupUi(QDialog *DeAddRadioactiveDlg)
    {
        if (DeAddRadioactiveDlg->objectName().isEmpty())
            DeAddRadioactiveDlg->setObjectName(QString::fromUtf8("DeAddRadioactiveDlg"));
        DeAddRadioactiveDlg->resize(694, 474);
        DeAddRadioactiveDlg->setStyleSheet(QString::fromUtf8("QDateEdit\n"
"{\n"
"   min-height:30px;\n"
"   border:1px solid gray;\n"
"   border-radius:5px;\n"
"   padding: 0px;\n"
"   font: 16pt \"\346\226\260\345\256\213\344\275\223\";\n"
"}\n"
"\n"
"QDateEdit::drop-down\n"
"{\n"
"   border:1px solid black;\n"
"   min-width:30px;\n"
"}\n"
"\n"
"QCalendarWidget\n"
"{\n"
"font: 20pt \"\346\226\260\345\256\213\344\275\223\";\n"
"}\n"
"\n"
"QCalendarWidget QAbstractButton\n"
"{\n"
"    min-width:40px;\n"
"}\n"
"\n"
"QLineEdit\n"
"{\n"
"border:1px solid gray;\n"
"border-radius:3px;\n"
"min-height:30px;\n"
"max-height:30px;\n"
"font: 16pt \"\346\226\260\345\256\213\344\275\223\";\n"
"}\n"
"\n"
"#widget_2\n"
"{\n"
"min-height:30px;\n"
"}\n"
"\n"
"QLabel\n"
"{\n"
"font: 14pt \"\346\226\260\345\256\213\344\275\223\";\n"
"min-width:100px;\n"
"}\n"
"\n"
"QGroupBox {\n"
"     border: 1px solid gray;\n"
"     border-radius: 3px;\n"
"     margin-top: 2ex; /* leave space at the top for the title */\n"
"     padding: 10px;\n"
" }\n"
"\n"
" QGroupBox::title {\n"
"     subcontrol-origi"
                        "n: margin;\n"
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
"     border: 1px solid #8f8f91;\n"
"     border-radius: 3px;\n"
"     min-width: 100px;\n"
"     min-height: 30px;\n"
" }\n"
"\n"
" QPushButton:pressed {\n"
"	background-color: rgb(255, 255, 255);\n"
" }"));
        gridLayout_4 = new QGridLayout(DeAddRadioactiveDlg);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        widget_4 = new QWidget(DeAddRadioactiveDlg);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        gridLayout_3 = new QGridLayout(widget_4);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        widget = new QWidget(widget_4);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setStyleSheet(QString::fromUtf8("max-width: 380px;\n"
"max-height:260px;"));
        gridLayout = new QGridLayout(widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox = new QGroupBox(widget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_8 = new QGridLayout(groupBox);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        idLineEdit = new QLineEdit(groupBox);
        idLineEdit->setObjectName(QString::fromUtf8("idLineEdit"));
        idLineEdit->setMaxLength(32);

        gridLayout_2->addWidget(idLineEdit, 0, 1, 1, 1);


        gridLayout_8->addLayout(gridLayout_2, 0, 0, 1, 1);

        gridLayout_7 = new QGridLayout();
        gridLayout_7->setSpacing(6);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_7->addWidget(label_3, 0, 0, 1, 1);

        originalLineEdit = new QLineEdit(groupBox);
        originalLineEdit->setObjectName(QString::fromUtf8("originalLineEdit"));
        originalLineEdit->setMaxLength(32);

        gridLayout_7->addWidget(originalLineEdit, 0, 1, 1, 1);


        gridLayout_8->addLayout(gridLayout_7, 1, 0, 1, 1);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setSpacing(6);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_5->addWidget(label_2, 0, 0, 1, 1);

        dateEdit = new QDateEdit(groupBox);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setMaximumSize(QSize(382, 262));
        dateEdit->setWrapping(false);
        dateEdit->setKeyboardTracking(true);
        dateEdit->setCalendarPopup(true);

        gridLayout_5->addWidget(dateEdit, 0, 1, 1, 1);


        gridLayout_8->addLayout(gridLayout_5, 2, 0, 1, 1);

        gridLayout_6 = new QGridLayout();
        gridLayout_6->setSpacing(6);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_6->addWidget(label_4, 0, 0, 1, 1);

        widget_3 = new DeComboBox(groupBox);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setMaximumSize(QSize(380, 260));

        gridLayout_6->addWidget(widget_3, 0, 1, 1, 1);


        gridLayout_8->addLayout(gridLayout_6, 3, 0, 1, 1);


        gridLayout->addWidget(groupBox, 0, 0, 1, 4);

        horizontalSpacer = new QSpacerItem(67, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        okBtn = new QPushButton(widget);
        okBtn->setObjectName(QString::fromUtf8("okBtn"));

        gridLayout->addWidget(okBtn, 1, 1, 1, 1);

        cancelBtn = new QPushButton(widget);
        cancelBtn->setObjectName(QString::fromUtf8("cancelBtn"));

        gridLayout->addWidget(cancelBtn, 1, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(67, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 3, 1, 1);


        gridLayout_3->addWidget(widget, 0, 0, 1, 1);


        gridLayout_4->addWidget(widget_4, 0, 0, 1, 1);

        keyBoradWidget = new DeVirtualKeyboradWidget(DeAddRadioactiveDlg);
        keyBoradWidget->setObjectName(QString::fromUtf8("keyBoradWidget"));
        keyBoradWidget->setMaximumSize(QSize(16777215, 220));

        gridLayout_4->addWidget(keyBoradWidget, 1, 0, 1, 1);

        gridLayout_4->setRowStretch(0, 10);
        gridLayout_4->setRowStretch(1, 1);

        retranslateUi(DeAddRadioactiveDlg);

        QMetaObject::connectSlotsByName(DeAddRadioactiveDlg);
    } // setupUi

    void retranslateUi(QDialog *DeAddRadioactiveDlg)
    {
        DeAddRadioactiveDlg->setWindowTitle(QApplication::translate("DeAddRadioactiveDlg", "DeAddRadioactiveDlg", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("DeAddRadioactiveDlg", "\346\267\273\345\212\240\346\224\276\345\260\204\346\272\220\350\256\260\345\275\225", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("DeAddRadioactiveDlg", "\347\274\226\345\217\267", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("DeAddRadioactiveDlg", "\345\216\237\345\247\213\346\264\273\345\272\246", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("DeAddRadioactiveDlg", "\347\224\237\344\272\247\346\227\245\346\234\237", 0, QApplication::UnicodeUTF8));
        dateEdit->setDisplayFormat(QApplication::translate("DeAddRadioactiveDlg", "yyyy-M-d", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("DeAddRadioactiveDlg", "\346\224\276\345\260\204\346\272\220\347\261\273", 0, QApplication::UnicodeUTF8));
        okBtn->setText(QApplication::translate("DeAddRadioactiveDlg", "Y", 0, QApplication::UnicodeUTF8));
        cancelBtn->setText(QApplication::translate("DeAddRadioactiveDlg", "N", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DeAddRadioactiveDlg: public Ui_DeAddRadioactiveDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEADDRADIOACTIVEDLG_H
