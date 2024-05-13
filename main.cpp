#include "mainwindow.h"
#include "level.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Level l;
    l.show();
    return a.exec();
}
