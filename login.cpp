#include "login.h"
#include "ui_login.h"
#include "exit.h"
#include "mainwindow.h"
#include <QPainter>


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

void login::on_pB_exit_clicked() //退出系统
{
     Exit *eexit = new Exit();
     eexit->show();
}

void login::on_pB_enter_clicked()
{
    this->hide();
    MainWindow *mainwindow = new MainWindow;
    mainwindow->show();
}
void login::paintEvent(QPaintEvent *e)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &amp;opt, &amp;p, this);
}
