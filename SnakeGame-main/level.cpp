#include "level.h"
#include "ui_level.h"
#include "mainwindow.h"

Level::Level(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Level)
{
    ui->setupUi(this);
}

Level::~Level()
{
    delete ui;
}
