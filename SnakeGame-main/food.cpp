#include "Food.h"

Food::Food(int xfood,int yfood) //随机生成食物的坐标
{
    int x = QRandomGenerator::global()->bounded(xfood);
    int y = QRandomGenerator::global()->bounded(yfood);
    foodpoint = QPoint(x, y);
}
QPoint Food::getPosition()const //获取食物的坐标
{
    return foodpoint;
}
