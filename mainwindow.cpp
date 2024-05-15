#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "snake.h"
#include "Food.h"
#include<QDebug>
#include <QDesktopWidget>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    setFocusPolicy(Qt::StrongFocus);
    ui->setupUi(this);

    // 获取窗口的大小
    QSize windowSize = size();

    // 计算蛇头的初始位置，使其位于窗口中央
    int snakeInitialX = windowSize.width() / 3;
    int snakeInitialY = windowSize.height() / 2;

    // 创建蛇对象，并设置初始位置
    snake = new Snake(snakeInitialX, snakeInitialY, this);

    setWindowTitle("Snake Game");
    setGeometry(500, 500, 800, 600); // 设置窗口的位置和大小
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::paintEvent(QPaintEvent *event)//绘制蛇和食物
{   QPainter painter(this);
    painter.setBrush(Qt::white);//画红色的蛇

    painter.setPen(QPen(Qt::black, 5)); // 黑色，宽度为5
       QRect wallRect(0, 0, 500, 500); // 正方形墙
       painter.drawRect(wallRect);
 painter.setBrush(Qt::red);
    int gridSize = 10; // 设定一个合适的网格尺寸
    for (const QPoint &gridPoint : snake->getBody()) {
        QPoint pixelPoint = gridPoint ;
        painter.drawRect(QRect(pixelPoint, QSize(gridSize, gridSize)));
    }
    this->update();
    painter.setBrush(Qt::red);
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
