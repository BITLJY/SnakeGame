#include "login.h"
#include "ui_login.h"
#include "exit.h"
#include "mainwindow.h"

login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}
login::~login()
{
    delete ui;
}

void login::on_pB_in_clicked()
{
    this->hide();
    MainWindow *mainwindow = new MainWindow;
    mainwindow->show();
    QDesktopWidget* desktop = QApplication::desktop();
    mainwindow->move((desktop->width() - this->width())/2, (desktop->height() - this->height())/2);
}
void login::on_pB_exit_clicked() //退出系统
{
     Exit *eexit = new Exit();
     eexit->show();
     eexit->setStyleSheet("#Exit{border-image: url(:/new/prefix2/exit1.jpg);}");
}
