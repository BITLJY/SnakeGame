#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "snake.h"
#include "Food.h"
#include "level.h"
#include "exit.h"

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
    currentLevel = new Level(100); // 将初始速度设置为100

    QVector<QPoint> obstacles;
    // 添加障碍物坐标到 obstacles 中
    currentLevel->setObstacles(obstacles);

    // 创建食物对象
    initGame();

    this->setStyleSheet("#MainWindow{border-image: url(:/new/prefix2/snakepicture.jpg);}");
}

MainWindow::~MainWindow()
{
    delete ui;
    delete snake;
    delete currentLevel;
    qDeleteAll(foods);
}

void MainWindow::initGame()
{
    score = 0;
    if (currentLevel)
    {
        // 根据当前关卡设置蛇的初始速度
        int initialSpeed = currentLevel->getInitialSpeed();
        snake->setInitialSpeed(initialSpeed);
        // 创建食物对象并添加到 foods 向量中
        foods.clear();
        for (int i = 0; i < currentLevel->getFoodCount(); ++i)
        {
             QPoint foodPos;
             Food *food = nullptr;
             // 生成随机位置直到找到一个合适的位置为止
             do
             {
                // 使用QRandomGenerator生成随机数
                int x = QRandomGenerator::global()->bounded(500); // 生成0到499之间的随机数
                int y = QRandomGenerator::global()->bounded(500); // 生成0到499之间的随机数
                foodPos = QPoint(x, y);
                // 创建食物对象
                food = new Food(foodPos.x(), foodPos.y());
                qDebug() << "Trying food at position:" << foodPos;
                // 检查食物位置是否与障碍物或蛇体重叠
                if (currentLevel->isObstacle(foodPos))
                {
                    qDebug() << "Food position overlaps with obstacle.";
                 }
                else if (snake->isSnakeBody(foodPos))
                {
                    qDebug() << "Food position overlaps with snake body.";
                }
             }
             while (currentLevel->isObstacle(foodPos) || snake->isSnakeBody(foodPos));
             qDebug() << "Found valid food position:" << foodPos;
             // 存储有效的食物对象
             foods.append(food);
         }
    }
}

void MainWindow::paintEvent(QPaintEvent *event1)//绘制蛇和食物
{
    if (!snake || foods.isEmpty() || !currentLevel)
    {
        qDebug() << "Snake is null:" << (snake == nullptr);
        qDebug() << "Foods is empty:" << foods.isEmpty();
        qDebug() << "CurrentLevel is null:" << (currentLevel == nullptr);
        return;
    }
    QPainter painter(this);
    // 绘制边界（正方形墙）
    painter.setBrush(Qt::white);
    painter.setPen(QPen(Qt::black, 5));
    QRect wallRect(0, 0, 500, 500);
    painter.drawRect(wallRect);
    update();
    //绘制红色的蛇
    painter.setBrush(Qt::red);
    int gridSize = 10; // 设定一个合适的网格尺寸
    for (const QPoint &gridPoint : snake->getBody())
    {
        painter.drawRect(QRect(gridPoint, QSize(gridSize, gridSize)));
    }
    update();
    // 绘制食物
    painter.setBrush(Qt::green);
    for (const Food *food : foods)
    {
        painter.drawRect(QRect(food->getPosition(), QSize(gridSize, gridSize)));
    }
    update();
    // 绘制障碍物
    painter.setBrush(Qt::black);
    for (const QPoint &obstacle : currentLevel->getObstacles())
    {
        painter.drawRect(QRect(obstacle, QSize(gridSize, gridSize)));
    }
    // 检查蛇是否吃到食物
    QPoint snakeHead = snake->getBoundingRect();
    for (int i = 0; i < foods.size(); ++i)
    {
        QPoint foodPos = foods[i]->getPosition();
        if (qAbs(snakeHead.x() - foodPos.x()) < gridSize && qAbs(snakeHead.y() - foodPos.y()) < gridSize) // 吃到食物后出现新的食物
        {
            snake->single=1;
            snake->single1=1;
            delete foods[i];
            foods.removeAt(i);
            // 生成新的食物
            Food *newFood = new Food(490, 490);
            foodPos = newFood->getPosition();
            while (currentLevel->isObstacle(foodPos) || snake->isSnakeBody(foodPos))
            {
            delete newFood;  // 删除旧的食物对象
            newFood = new Food(490, 490);  // 创建新的食物对象
            foodPos = newFood->getPosition();  // 更新食物位置
            }
           foods.append(newFood);  // 添加新的食物到 foods 向量中
           on_Score_overflow();  // 更新得分
           break;  // 只处理一次食物碰撞，避免多次处理
        }
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event2)//处理键盘输入（输入上下左右时赋给蛇移动的函数）
{
    switch (event2->key())
    {
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

void MainWindow::closeEvent(QCloseEvent *event3)
{
    Exit *exit=new Exit();
    exit->show();
    if(exit->exitok)
    {
         event3->accept();
    }
    else
    {
        event3->ignore();
    }
}

void MainWindow::on_pB_on_pushbutton_start_clicked()
{
    snake->startGame();
}

void MainWindow::on_pB_on_pushbutton_restart_clicked()
{
    ui->Score->display(0);
    snake->stopGame(); // 停止游戏
    snake->reset();// 重新设置蛇的位置等
    initGame();// 重新初始化游戏
    snake->startGame(); // 开始游戏
}

void MainWindow::on_pB_on_pushbutton_stop_clicked()
{
    snake->flag=0;
    snake->stopGame(); // 停止游戏
    QMessageBox::information(this, "游戏暂停", "游戏已暂停");
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
            initialSpeed = 100;
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
