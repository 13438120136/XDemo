/********************************************************************************
** Form generated from reading UI file 'decombobox.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DECOMBOBOX_H
#define UI_DECOMBOBOX_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DeComboBox
{
public:
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    QLineEdit *lineEdit;
    QGridLayout *gridLayout;
    QPushButton *subBtn;
    QPushButton *addBtn;

    void setupUi(QWidget *DeComboBox)
    {
        if (DeComboBox->objectName().isEmpty())
            DeComboBox->setObjectName(QString::fromUtf8("DeComboBox"));
        DeComboBox->resize(363, 47);
        DeComboBox->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"border:1px solid gray;\n"
"border-radius:0px;\n"
"min-width:30px;\n"
"min-height:30px;\n"
"}\n"
"\n"
"QLineEdit\n"
"{\n"
"border:1px solid gray;\n"
"min-height:30px;\n"
"border-top-left-radius:3px;\n"
"border-top-right-radius:0px;\n"
"border-bottom-right-radius:0px;\n"
"border-bottom-left-radius:3px;\n"
"}"));
        gridLayout_3 = new QGridLayout(DeComboBox);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setHorizontalSpacing(0);
        lineEdit = new QLineEdit(DeComboBox);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setMinimumSize(QSize(0, 32));
        lineEdit->setAlignment(Qt::AlignCenter);
        lineEdit->setReadOnly(true);

        gridLayout_2->addWidget(lineEdit, 0, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(5);
        subBtn = new QPushButton(DeComboBox);
        subBtn->setObjectName(QString::fromUtf8("subBtn"));

        gridLayout->addWidget(subBtn, 0, 0, 1, 1);

        addBtn = new QPushButton(DeComboBox);
        addBtn->setObjectName(QString::fromUtf8("addBtn"));

        gridLayout->addWidget(addBtn, 0, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 0, 1, 1);


        retranslateUi(DeComboBox);

        QMetaObject::connectSlotsByName(DeComboBox);
    } // setupUi

    void retranslateUi(QWidget *DeComboBox)
    {
        DeComboBox->setWindowTitle(QApplication::translate("DeComboBox", "DeComboBox", 0, QApplication::UnicodeUTF8));
        subBtn->setText(QApplication::translate("DeComboBox", "-", 0, QApplication::UnicodeUTF8));
        addBtn->setText(QApplication::translate("DeComboBox", "+", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DeComboBox: public Ui_DeComboBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DECOMBOBOX_H
