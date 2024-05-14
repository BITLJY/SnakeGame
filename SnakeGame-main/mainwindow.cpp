#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "snake.h"
#include "Food.h"


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

void MainWindow::paintevent(QPaintEvent *pevent)//绘制蛇和食物
{

};
void MainWindow::keyPressEvent(QKeyEvent *kevent)//处理键盘输入（输入上下左右时赋给蛇移动的函数）
{

};
void MainWindow::ScoreCount() //把分数显示在计数器上
{
    int score = getscore();
    ui->Score->display(score);
};
