#include "exit.h"
#include "ui_exit.h"

Exit::Exit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Exit)
{
    ui->setupUi(this);
    this->setStyleSheet("#Exit{border-image: url(:/new/prefix2/exitpicture.jpg);}");
}

Exit::~Exit()
{
    delete ui;
}

void Exit::on_pB_Yes_clicked()
{
     QApplication::exit();
     exitok=1;
}

void Exit::on_pB_No_clicked()
{
    this->close();
    exitok=0;
}
