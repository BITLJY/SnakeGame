#include "mainwindow.h"
#include "login.h"
#include "exit.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    login l;
    l.show();
    return a.exec();
}
