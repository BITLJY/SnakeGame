/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLCDNumber *Score;
    QLabel *label;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pB_on_pushbutton_restart;
    QPushButton *pB_on_pushbutton_start;
    QPushButton *pB_on_pushbutton_stop;
    QPushButton *pB_on_pushbutton_select;
    QPushButton *pB_on_pushbutton_goon;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(759, 503);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Score = new QLCDNumber(centralwidget);
        Score->setObjectName(QString::fromUtf8("Score"));
        Score->setGeometry(QRect(610, 10, 111, 51));
        Score->setStyleSheet(QString::fromUtf8("border-color: rgb(0, 0, 0);\n"
"background-color: rgb(107, 214, 158);\n"
""));
        Score->setSegmentStyle(QLCDNumber::Filled);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(530, 10, 81, 51));
        label->setStyleSheet(QString::fromUtf8("font: 16pt \"\345\271\274\345\234\206\";"));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(580, 140, 160, 261));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pB_on_pushbutton_restart = new QPushButton(gridLayoutWidget);
        pB_on_pushbutton_restart->setObjectName(QString::fromUtf8("pB_on_pushbutton_restart"));
        pB_on_pushbutton_restart->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\271\274\345\234\206\";"));

        gridLayout->addWidget(pB_on_pushbutton_restart, 4, 0, 1, 1);

        pB_on_pushbutton_start = new QPushButton(gridLayoutWidget);
        pB_on_pushbutton_start->setObjectName(QString::fromUtf8("pB_on_pushbutton_start"));
        pB_on_pushbutton_start->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\271\274\345\234\206\";"));

        gridLayout->addWidget(pB_on_pushbutton_start, 0, 0, 1, 1);

        pB_on_pushbutton_stop = new QPushButton(gridLayoutWidget);
        pB_on_pushbutton_stop->setObjectName(QString::fromUtf8("pB_on_pushbutton_stop"));
        pB_on_pushbutton_stop->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\271\274\345\234\206\";"));

        gridLayout->addWidget(pB_on_pushbutton_stop, 1, 0, 1, 1);

        pB_on_pushbutton_select = new QPushButton(gridLayoutWidget);
        pB_on_pushbutton_select->setObjectName(QString::fromUtf8("pB_on_pushbutton_select"));
        pB_on_pushbutton_select->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\271\274\345\234\206\";"));

        gridLayout->addWidget(pB_on_pushbutton_select, 3, 0, 1, 1);

        pB_on_pushbutton_goon = new QPushButton(gridLayoutWidget);
        pB_on_pushbutton_goon->setObjectName(QString::fromUtf8("pB_on_pushbutton_goon"));
        pB_on_pushbutton_goon->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\271\274\345\234\206\";"));

        gridLayout->addWidget(pB_on_pushbutton_goon, 2, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 759, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QApplication::translate("MainWindow", "\345\276\227\345\210\206\357\274\232", nullptr));
        pB_on_pushbutton_restart->setText(QApplication::translate("MainWindow", "\351\207\215\346\226\260\345\274\200\345\247\213", nullptr));
        pB_on_pushbutton_start->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213\346\270\270\346\210\217", nullptr));
        pB_on_pushbutton_stop->setText(QApplication::translate("MainWindow", "\346\232\202\345\201\234\346\270\270\346\210\217", nullptr));
        pB_on_pushbutton_select->setText(QApplication::translate("MainWindow", "\351\200\211\346\213\251\345\205\263\345\215\241", nullptr));
        pB_on_pushbutton_goon->setText(QApplication::translate("MainWindow", "\347\273\247\347\273\255\346\270\270\346\210\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
