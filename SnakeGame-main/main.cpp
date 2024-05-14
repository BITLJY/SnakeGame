#include "mainwindow.h"
#include "level.h"
#include "login.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    login *lo=new login();
    lo->setWindowTitle("登录界面");
    lo->show();  //以登录界面开始
    MainWindow w;
    return a.exec();
}
