/********************************************************************************
** Form generated from reading UI file 'demodifyuserdlg.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEMODIFYUSERDLG_H
#define UI_DEMODIFYUSERDLG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
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

class Ui_DeModifyUserDlg
{
public:
    QGridLayout *gridLayout_4;
    QWidget *widget_3;
    QGridLayout *gridLayout_3;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *userLineEdit;
    QLabel *label_2;
    QLineEdit *passwdLineEdit;
    QLabel *label_3;
    DeComboBox *widgePermission;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QSpacerItem *horizontalSpacer_2;
    DeVirtualKeyboradWidget *keyBoradWidget;

    void setupUi(QDialog *DeModifyUserDlg)
    {
        if (DeModifyUserDlg->objectName().isEmpty())
            DeModifyUserDlg->setObjectName(QString::fromUtf8("DeModifyUserDlg"));
        DeModifyUserDlg->resize(685, 458);
        DeModifyUserDlg->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
"border:1px solid gray;\n"
"border-radius:5px;\n"
"min-height:30px;\n"
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
"min-width:60px;\n"
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
"     border: 0px solid #8f8f91;\n"
"     border-radius: 5px;\n"
"     m"
                        "in-width: 100px;\n"
"     min-height: 30px;\n"
" }\n"
"\n"
" QPushButton:pressed {\n"
"	background-color: rgb(255, 255, 255);\n"
" }\n"
""));
        gridLayout_4 = new QGridLayout(DeModifyUserDlg);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        widget_3 = new QWidget(DeModifyUserDlg);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setStyleSheet(QString::fromUtf8("\n"
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
""));
        gridLayout_3 = new QGridLayout(widget_3);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        widget = new QWidget(widget_3);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setStyleSheet(QString::fromUtf8("max-width: 320px;\n"
"max-height:180px;"));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        groupBox = new QGroupBox(widget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setVerticalSpacing(2);
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(60, 0));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        userLineEdit = new QLineEdit(groupBox);
        userLineEdit->setObjectName(QString::fromUtf8("userLineEdit"));
        userLineEdit->setMaxLength(32);
        userLineEdit->setReadOnly(true);

        gridLayout->addWidget(userLineEdit, 0, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(60, 0));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        passwdLineEdit = new QLineEdit(groupBox);
        passwdLineEdit->setObjectName(QString::fromUtf8("passwdLineEdit"));
        passwdLineEdit->setMaxLength(32);
        passwdLineEdit->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(passwdLineEdit, 1, 1, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(60, 0));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        widgePermission = new DeComboBox(groupBox);
        widgePermission->setObjectName(QString::fromUtf8("widgePermission"));

        gridLayout->addWidget(widgePermission, 2, 1, 1, 1);


        gridLayout_2->addWidget(groupBox, 0, 0, 1, 4);

        horizontalSpacer = new QSpacerItem(37, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 1, 0, 1, 1);

        okBtn = new QPushButton(widget);
        okBtn->setObjectName(QString::fromUtf8("okBtn"));

        gridLayout_2->addWidget(okBtn, 1, 1, 1, 1);

        cancelBtn = new QPushButton(widget);
        cancelBtn->setObjectName(QString::fromUtf8("cancelBtn"));

        gridLayout_2->addWidget(cancelBtn, 1, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(37, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 1, 3, 1, 1);


        gridLayout_3->addWidget(widget, 0, 0, 1, 1);


        gridLayout_4->addWidget(widget_3, 0, 0, 1, 1);

        keyBoradWidget = new DeVirtualKeyboradWidget(DeModifyUserDlg);
        keyBoradWidget->setObjectName(QString::fromUtf8("keyBoradWidget"));

        gridLayout_4->addWidget(keyBoradWidget, 1, 0, 1, 1);


        retranslateUi(DeModifyUserDlg);

        QMetaObject::connectSlotsByName(DeModifyUserDlg);
    } // setupUi

    void retranslateUi(QDialog *DeModifyUserDlg)
    {
        DeModifyUserDlg->setWindowTitle(QApplication::translate("DeModifyUserDlg", "DeModifyUserDlg", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("DeModifyUserDlg", "\344\277\256\346\224\271\347\224\250\346\210\267", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("DeModifyUserDlg", "\347\224\250\346\210\267\345\220\215:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("DeModifyUserDlg", "\345\257\206  \347\240\201:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("DeModifyUserDlg", "\346\235\203  \351\231\220:", 0, QApplication::UnicodeUTF8));
        okBtn->setText(QApplication::translate("DeModifyUserDlg", "\347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
        cancelBtn->setText(QApplication::translate("DeModifyUserDlg", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DeModifyUserDlg: public Ui_DeModifyUserDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEMODIFYUSERDLG_H
