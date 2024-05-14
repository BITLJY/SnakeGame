#include "snake.h"

Snake::Snake(int xsnake,int ysnake)
{
     snakebody.push_back(QPoint(xsnake, ysnake));  //初始化位置
     direction = Left; // 初始方向向左
     //初始化大小（长度）
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
    ateFood();//调用是否吃到食物函数
    crashed();//调用是否碰撞函数
    update(); // 更新界面
};
void Snake::keyPressEvent(QKeyEvent *event) //自动获取键盘输入的方向信息
{
    switch (event->key()) {
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
}
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
