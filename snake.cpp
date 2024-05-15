#include "snake.h"


Snake::Snake(int xs, int ys, QWidget *parent) : QWidget(parent) {
    xsnake = xs;
    ysnake = ys;
    direction = Right; // 初始方向向右
    for (int i = 0; i < 5; ++i) {
        // 假设蛇的每个节段在水平方向上等距分布，垂直位置相同
        snakebody.push_back(QPoint(xsnake + i * 10, ysnake));
    } // 初始化大小（长度）
    timerID = startTimer(300); // 启动定时器，每500毫秒触发一次

}
int Snake::getlength()const //获取蛇的长度
{
    return snakebody.size();
}
const QPoint& Snake::at(int index)const // 获取蛇的身体节（按从头到尾的顺序）
{
    return snakebody.at(index);
}
void Snake::addhead(const QPoint& position)//增加新的一节在头
{
    snakebody.push_front(position);
};
void Snake::rmtail()//删除尾巴
{
    snakebody.pop_back();
};
void Snake::grow()//增加一节蛇
{
    QPoint newHeadPosition = snakebody.front(); // 假设新头部位置与当前头部相同
    addhead(newHeadPosition); // 在头部添加新的身体节
};
void Snake::setDirection(Direction newDirection) //从mainwindow中获取方向更新
{
    this->direction = newDirection;
}

void Snake::move()//蛇的移动
{
    QPoint newHead = snakebody.front();
    switch (direction) {
    case Up:    newHead.setY(newHead.y() - 10); break;
    case Down:  newHead.setY(newHead.y() + 10); break;
    case Left:  newHead.setX(newHead.x() - 10); break;
    case Right: newHead.setX(newHead.x() + 10); break;
    }
    snakebody.push_front(newHead);rmtail();
    update();//更新移动
    ateFood();//调用是否吃到食物函数
    crashed();//调用是否碰撞函数

};

void Snake::timerEvent(QTimerEvent *event) //按计时器的时间间隔触发蛇的移动函数
{
    if (event->timerId() == timerID) move();
}
bool Snake::ateFood()//是否吃到食物
{

    return true;
};
bool Snake::crashed()//是否碰撞
{

    return true;
};
