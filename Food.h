#ifndef FOOD_H
#define FOOD_H
#include<QPoint>
#include <QVector>
#include <QRect>
#include <QRandomGenerator>
#include"Directions.h"

class Food
{
public:
    Food(int xfood, int yfood);//随机生成食物
    QPoint getPosition() const;
private:
    QPoint foodpoint;//食物的位置
};

#endif // FOOD_H
