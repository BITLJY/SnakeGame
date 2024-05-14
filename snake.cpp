#include "snake.h"

Snake::Snake(int xsnake,int ysnake)
{
     snakebody.push_back(QPoint(xsnake, ysnake));  //初始化位置
     //初始化方向
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

};

bool Snake::ateFood()//是否吃到食物
{

    return true;
};
bool Snake::crashed()//是否碰撞
{

    return true;
};
