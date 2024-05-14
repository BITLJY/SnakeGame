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

void login::on_pB_easy_clicked()
{
    this->hide();
    MainWindow *mainwindow = new MainWindow;
    mainwindow->show();
}
void login::on_pB_normal_clicked()
{
    this->hide();
    MainWindow *mainwindow = new MainWindow;
    mainwindow->show();
}
void login::on_pB_hard_clicked()
{
    this->hide();
    MainWindow *mainwindow = new MainWindow;
    mainwindow->show();
}

void login::on_pB_exit_clicked() //退出系统
{
     Exit *eexit = new Exit();
     eexit->show();
}
