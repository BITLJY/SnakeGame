#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "snake.h"
#include "Food.h"
#include "level.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

