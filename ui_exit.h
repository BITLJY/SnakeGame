/********************************************************************************
** Form generated from reading UI file 'exit.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXIT_H
#define UI_EXIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Exit
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QSpacerItem *verticalSpacer;
    QPushButton *pB_Yes;
    QSpacerItem *verticalSpacer_2;
    QPushButton *pB_No;

    void setupUi(QWidget *Exit)
    {
        if (Exit->objectName().isEmpty())
            Exit->setObjectName(QString::fromUtf8("Exit"));
        Exit->resize(583, 433);
        widget = new QWidget(Exit);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(160, 100, 241, 221));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("font: 18pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";\n"
"border-color: rgb(255, 170, 255);"));

        verticalLayout->addWidget(label);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        pB_Yes = new QPushButton(widget);
        pB_Yes->setObjectName(QString::fromUtf8("pB_Yes"));

        verticalLayout->addWidget(pB_Yes);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        pB_No = new QPushButton(widget);
        pB_No->setObjectName(QString::fromUtf8("pB_No"));

        verticalLayout->addWidget(pB_No);


        retranslateUi(Exit);

        QMetaObject::connectSlotsByName(Exit);
    } // setupUi

    void retranslateUi(QWidget *Exit)
    {
        Exit->setWindowTitle(QApplication::translate("Exit", "Form", nullptr));
        label->setText(QApplication::translate("Exit", "\347\241\256\345\256\232\351\200\200\345\207\272\357\274\237", nullptr));
        pB_Yes->setText(QApplication::translate("Exit", "\347\241\256\345\256\232", nullptr));
        pB_No->setText(QApplication::translate("Exit", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Exit: public Ui_Exit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXIT_H
