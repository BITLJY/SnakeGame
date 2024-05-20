#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "snake.h"
#include "Food.h"
#include "level.h"

#include<QDebug>
#include <QDesktopWidget>
#include <QMessageBox>
#include <QInputDialog>

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

    // 创建并设置关卡对象
    currentLevel = new Level(80); // 将初始速度设置为100

    QVector<QPoint> obstacles;
    // 添加障碍物坐标到 obstacles 中
    currentLevel->setObstacles(obstacles);

    // 创建食物对象
    food = new Food(490, 490);
    foods = QList<Food*>();        
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initGame() {
    score = 0;
    if (currentLevel) {
        // 根据当前关卡设置蛇的初始速度
        int initialSpeed = currentLevel->getInitialSpeed();
        snake->setInitialSpeed(initialSpeed);
    }
}

void MainWindow::paintEvent(QPaintEvent *event)//绘制蛇和食物
{
    if (!snake || !food || !currentLevel)
    {
        qDebug() << "Snake, food, or currentLevel is null";
        return;
    }
    //snake->single=0;
    QPainter painter(this);
    // 绘制边界（正方形墙）
    painter.setBrush(Qt::white);
    painter.setPen(QPen(Qt::black, 5));
    QRect wallRect(0, 0, 500, 500);
    painter.drawRect(wallRect);
    //绘制红色的蛇
    painter.setBrush(Qt::red);
    int gridSize = 10; // 设定一个合适的网格尺寸
    for (const QPoint &gridPoint : snake->getBody())
    {
        QPoint pixelPoint = gridPoint ;
        painter.drawRect(QRect(pixelPoint, QSize(gridSize, gridSize)));
    }
    this->update();
    painter.setBrush(Qt::red);
    // 绘制食物
    painter.setBrush(Qt::green);
    QPoint foodPos = food->getPosition();
    painter.drawRect(QRect(foodPos, QSize(gridSize, gridSize)));
    // 绘制障碍物
    painter.setBrush(Qt::black);
    for (const QPoint &obstacle : currentLevel->getObstacles())
    {
        painter.drawRect(QRect(obstacle, QSize(gridSize, gridSize)));
    }
    QPoint snakehead = snake->getBoundingRect();
    if (qAbs(snakehead.x()-foodPos.x())<10&&qAbs(snakehead.y()-foodPos.y())<10)//吃到食物后出现新的食物
    {
        snake->single=1;
        snake->single1=1;
        delete food;
        food = new Food(490, 490);
        on_Score_overflow();
    }
}

void MainWindow::keyPressEvent(QKeyEvent *kevent)//处理键盘输入（输入上下左右时赋给蛇移动的函数）
{
    switch (kevent->key())
    {
    case Qt::Key_Up:
        if (direction != Down) direction = Up;break;
    case Qt::Key_Down:
        if (direction != Up) direction = Down;break;
    case Qt::Key_Left:
        if (direction != Right) direction = Left;break;
    case Qt::Key_Right:
        if (direction != Left) direction = Right;break;
    }
    snake->setDirection(direction);
};


void MainWindow::on_pB_on_pushbutton_start_clicked()
{
    snake->startGame();
}

void MainWindow::on_pB_on_pushbutton_restart_clicked()
{
    ui->Score->display(0);
    snake->stopGame(); // 停止游戏
    // 重新设置蛇的位置等
    // 重新开始游戏
    snake->reset();
    snake->startGame(); // 开始游戏
}

void MainWindow::on_pB_on_pushbutton_stop_clicked()
{
    snake->flag=0;
    snake->stopGame(); // 停止游戏
    QMessageBox::critical(this, "游戏暂停", "游戏已暂停");
}

void MainWindow::on_pB_on_pushbutton_goon_clicked()
{
    snake->startGame(); // 开始游戏
}

// 在关卡选择的槽函数中设置关卡对象的初始速度并初始化游戏
void MainWindow::on_pB_on_pushbutton_select_clicked()
{
    ui->Score->display(0);
    QStringList levels;
    levels << "Level 1" << "Level 2" << "Level 3";
    bool ok;
    QString level = QInputDialog::getItem(this, "Select Level", "Choose a level:", levels, 0, false, &ok);
    if (ok) {
        int initialSpeed = 100; // 默认速度
        int foodCount = 1; // 默认食物数量
        QVector<QPoint> obstacles; // 障碍物坐标
        if (level == "Level 2") {
            initialSpeed = 80;
            foodCount = 2; // 第二关有两个食物
            // 设置第二关的障碍物坐标
            for(int i=50;i<350;i += 10)
            {
                obstacles <<QPoint(i,50);
            }
            for(int j=50;j<350;j +=10)
            {
                 obstacles <<QPoint(50,j);
            }
            for(int i=450;i>150;i -= 10)
            {
                obstacles <<QPoint(i,450);
            }
            for(int j=450;j>150;j -=10)
            {
                 obstacles <<QPoint(450,j);
            }

            for(int i=250;i<350;i += 10)
            {
                obstacles <<QPoint(i,150);
                obstacles <<QPoint(150,i);
            }

            for(int i=150;i<250;i += 10)
            {
                obstacles <<QPoint(i,350);
                obstacles <<QPoint(350,i);
            }
        } else if (level == "Level 3") {
            initialSpeed = 60;
            foodCount = 3; // 第三关有三个食物
            // 设置第三关的障碍物坐标
            for (int x = 40; x <= 490; x += 100) {
                for (int y = 40; y <= 490; y += 100) {
                    obstacles << QPoint(x, y);
                }
            }
        }
        // 创建关卡对象并设置初始速度和食物数量
        Level *selectedLevel = new Level(initialSpeed);
        selectedLevel->setFoodCount(foodCount);

        // 设置关卡的障碍物
        selectedLevel->setObstacles(obstacles);

        // 将选定的关卡对象设置为当前关卡对象
        currentLevel = selectedLevel;

        // 将关卡对象传递给Snake类
        snake->setLevel(selectedLevel);

        // 初始化游戏
        initGame();

        // 重置蛇的关卡对象
        snake->reset();
        update();
        qDebug()<<currentLevel;
    }
}

void MainWindow::on_Score_overflow()
{
    // 蛇吃到一个食物，得分加一

    int currentScore = ui->Score->intValue(); // 获取当前得分
        qDebug()<<currentScore;
    ui->Score->display(currentScore + 1); // 显示得分加一后的值
}

