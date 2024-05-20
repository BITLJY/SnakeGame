#include "snake.h"
#include "Food.h"
#include "level.h"

Snake::Snake(int xs, int ys, QWidget *parent) : QWidget(parent)
{
    xsnake = xs;
    ysnake = ys;
    direction = Left; // 初始方向向左
    for (int i = 0; i < 5; ++i)
    {
        // 假设蛇的每个节段在水平方向上等距分布，垂直位置相同
        snakebody.push_back(QPoint(xsnake + i * 10, ysnake));
    } // 初始化大小（长度）
    timer = new QTimer(this); // 创建定时器对象
    connect(timer, SIGNAL(timeout()), this, SLOT(move())); // 连接定时器的超时信号到移动函数
    timer->start(100); // 启动定时器，初始速度
    timerID = startTimer(100); // 启动定时器，初始速度
    speedLevel = 1; // 初始速度c级别
    timeCounter = 0; // 初始化时间计数器
    foodEatenCount = 0;
    gameRunning = false;
    currentLevel = nullptr;
    Level *currentLevel;
    currentLevel = nullptr;
    gameList->addMedia(QUrl("qrc:/new/prefix1/bgm.wav"));//添加音乐
    gameList->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);//循环播放
    gameSound->setPlaylist(gameList);
    gameSound->setVolume(80);//音量
   }

void Snake::startGame()
{
    if (!gameRunning)
    {
        timerID = startTimer(100); // 启动定时器
        gameRunning = true; // 标记游戏正在运行
        gameSound->play();//音乐播放
    }
}
void Snake::stopGame()
{
    if (gameRunning)
    {
        if(flag==1)
        {
            QSound *startsound=new QSound("qrc:/new/prefix1/gameover.wav");//添加失败的音效
            startsound->play();startsound->setLoops(1);
        }
        killTimer(timerID); // 停止定时器
        gameRunning = false; // 标记游戏停止运行
        gameSound->stop();//音乐停止
    }
}
void Snake::setLevel(Level *level)
{
    currentLevel = level;
}
void Snake::reset()
{
    // 重置蛇的位置
    snakebody.clear();
    for (int i = 0; i < 5; ++i)
    {
        snakebody.push_back(QPoint(xsnake + i * 10, ysnake));
    }
    // 重置蛇的方向
    direction = Left;
    // 重置其他状态
    gameRunning = false;
    timeCounter = 0;
    foodEatenCount = 0;
    speedLevel = 1; // 重置为初始速度级别
    adjustSpeed(); // 根据初始速度调整实际速度

}

void Snake::setFoodCount(int count)
{
    if (currentLevel)
    {
        currentLevel->setFoodCount(count);
    }
}
void Snake::addhead(const QPoint& position) //增加新的一节在头
{
    snakebody.push_front(position);
}

void Snake::rmtail() //删除尾巴
{
    snakebody.pop_back();
}

void Snake::grow() //增加一节蛇
{
    QPoint newHeadPosition = snakebody.front(); // 假设新头部位置与当前头部相同
    addhead(newHeadPosition); // 在头部添加新的身体节
}
void Snake::setDirection(Direction newDirection) //从mainwindow中获取方向更新
{
    this->direction = newDirection;
}

void Snake::move()
{
    if (gameRunning)
    {
        timeCounter++; // 增加时间计数器
        QPoint newHead = snakebody.front();
        switch (direction)
        {
            case Up:
                newHead.ry() -= 10;
                break;
            case Down:
                newHead.ry() += 10;
                break;
            case Left:
                newHead.rx() -= 10;
                break;
            case Right:
                newHead.rx() += 10;
                break;
            case None:
                break;
        }

        // 检查新头部位置是否超出边界
        if (newHead.x() < 0 || newHead.x() >= 500 || newHead.y() < 0 || newHead.y() >= 500)
        {
            // 超出边界，游戏结束
            flag=1;stopGame();
            QMessageBox::critical(this, "Game Over", "You hit the wall! Game Over.");
            return;
        }
        // 检查新头部位置是否与蛇身相撞
        std::size_t size = snakebody.size();
        for (std::size_t i = 1; i < size; ++i)
        {
            if (newHead == snakebody.at(i))
            {
                // 与蛇身相撞，游戏结束
                flag=1;stopGame();
                QMessageBox::critical(this, "Game Over", "You crashed into yourself! Game Over.");
                return;
            }
        }
        // 检查新头部位置是否与障碍物相撞
        qDebug()<<newHead;
        if (currentLevel && currentLevel->isObstacle(newHead))
        {
            flag=1;stopGame();
            QMessageBox::critical(this, "Game Over", "You hit an obstacle! Game Over.");
            return;
         }
        // 如果没有碰撞，则更新蛇的位置
        addhead(newHead);
        rmtail();
        update(); // 更新移动

        // 吃到食物和调整速度的逻辑不变
        if (ateFood()) {
            qDebug() << "蛇的长度增加了";
            grow();
        }
        adjustSpeed();
    }
}

void Snake::timerEvent(QTimerEvent *event) //按计时器的时间间隔触发蛇的移动函数
{
    if (event->timerId() == timerID) {
        move();
        adjustSpeed(); // 调整速度
        timeCounter++; // 增加时间计数器
    }
}

bool Snake::ateFood() {
    if (single == 1) {
        single = 0;
        QSound *startsound=new QSound("qrc:/new/prefix1/atefoodmusic.wav");//添加吃食物的音效
        startsound->play();startsound->setLoops(1);
        foodEatenCount++;
        // 增加吃到食物的次数
        return true;
    }
    return false;
}

bool Snake::crashed() //是否碰撞
{
    if (Snake::single1 == 1)
    {
        Snake::single1 = 0;
        return false;
    }
    QPoint newHead = snakebody.front();
    if (newHead.x() > 490 || newHead.x() < 10 || newHead.y() < 10 || newHead.y() > 490)
    {
        return true;
    }
    std::size_t size = snakebody.size();
    for (std::size_t i = 1; i < size; ++i)
    {
        if (newHead == snakebody.at(i))
            return true;
    }
    return false;
}

QPoint Snake::getBoundingRect() const
{
    QPoint newHead = snakebody.front();
    return newHead;
}
void Snake::adjustSpeed()
{
     if (gameRunning)
     {
    // 根据时间计数器的值调整速度级别
    if (timeCounter >= 100 && speedLevel < 2) {
        speedLevel = 2; // 在游戏运行100个时间单位后，切换到速度级别2
    }
    if (timeCounter >= 300 && speedLevel < 3) {
        speedLevel = 3; // 在游戏运行300个时间单位后，切换到速度级别3
    }

    // 根据速度级别调整定时器的时间间隔
    int interval;
    switch (speedLevel) {
        case 1: interval = initialSpeed*1; break; // 速度级别1，间隔100ms
        case 2: interval = initialSpeed*0.8; break; // 速度级别2，间隔80ms
        case 3: interval = initialSpeed*0.6; break; // 速度级别3，间隔60ms
        // 可以继续添加更多速度级别
        default: break;
    }

    // 根据吃到食物的次数调整定时器的时间间隔
    if (foodEatenCount > 0) {
        // 如果吃到食物，则减少定时器的时间间隔，但不受速度级别的影响
        interval -= foodEatenCount *0.3; // 假设每次吃到食物减少1毫秒间隔
        if (interval < 40) {
            interval = 40; // 最小间隔不低于40毫秒
        }
    }

    // 设置定时器的时间间隔
    if (timerID != 0) {
        // 只有当 timerID 不为 0 时才设置定时器的时间间隔
        // 否则可能会导致未创建定时器时的错误
        interval = qMax(interval, 40); // 限制最小间隔为 20 毫秒
        killTimer(timerID); // 先停止之前的定时器
        timerID = startTimer(interval); // 重新启动定时器并获取新的 timerID
    }
     }
}

bool Snake::isSnakeBody(const QPoint &point) const
{

    for (const QPoint &Snakebody : snakebody)
    {
        int distance = qAbs(point.x() - Snakebody.x()) + qAbs(point.y() - Snakebody.y());
        if (distance < 1)
        {
            return true;
        }
    }
    return false;
}
