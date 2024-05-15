#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "snake.h"
#include "Food.h"
#include<QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    setFocusPolicy(Qt::StrongFocus);
    snake = new Snake(10, 10, this);
    setWindowTitle("Snake Game");
    setGeometry(500, 500, 800, 600); // 设置窗口的位置和大小
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::paintEvent(QPaintEvent *event)//绘制蛇和食物
{QPainter painter(this);
    painter.setBrush(Qt::red);//画红色的蛇
    int gridSize = 10; // 设定一个合适的网格尺寸
    for (const QPoint &gridPoint : snake->getBody()) {
        QPoint pixelPoint = gridPoint ;
        painter.drawRect(QRect(pixelPoint, QSize(gridSize, gridSize)));
    }
    this->update();
}


void MainWindow::keyPressEvent(QKeyEvent *kevent)//处理键盘输入（输入上下左右时赋给蛇移动的函数）
{
    switch (kevent->key()) {
    case Qt::Key_Up:
        if (direction != Down) direction = Up;
        break;
    case Qt::Key_Down:
        if (direction != Up) direction = Down;
        break;
    case Qt::Key_Left:
        if (direction != Right) direction = Left;
        break;
    case Qt::Key_Right:
        if (direction != Left) direction = Right;
        break;
    }
    snake->setDirection(direction);
};
