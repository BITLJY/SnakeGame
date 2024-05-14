#include "exit.h"
#include "ui_exit.h"

Exit::Exit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Exit)
{
    ui->setupUi(this);
}

Exit::~Exit()
{
    delete ui;
}

void Exit::on_pB_Yes_clicked()
{
     QApplication::exit();
}

void Exit::on_pB_No_clicked()
{
    this->close();
}
