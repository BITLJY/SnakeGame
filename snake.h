#ifndef SNAKE_H
#define SNAKE_H
#include<QPoint>
#include<QKeyEvent>
#include <QWidget>
#include<QTime>
#include<QTimer>
#include<deque>
#include <QVector>
#include <QRect>
#include"Directions.h"
class Snake:public QWidget
{
public:
    Snake(){};
    Snake(int xs, int ys, QWidget *parent = nullptr);
    void move();//蛇的移动
    int single=0;
    int single1=0;
    Direction direction;
    void timerEvent(QTimerEvent *event);
    void setDirection(Direction newDirection);
    int getlength()const;//获取蛇的长度
    const QPoint& at(int index) const;//获取蛇的身体节（按从头到尾的顺序）
    const std::deque<QPoint>& getBody() const {return snakebody;}
    QPoint getBoundingRect() const; // 获取蛇的包围矩形边界

    std::deque<QPoint> snakebody;//双端队列定义
    ;
private:
    int xsnake,ysnake;//初始化的位置（一般为界面中心）
    int maxL;//蛇的最大长度
    void addhead(const QPoint& position);//增加新的一节在头
    void rmtail();//删除尾巴
    void grow();//吃到食物后增加一节蛇
    bool ateFood();//是否吃到食物
    bool crashed();//是否碰撞
    QTimer* timer;//用于获取随机数
    QKeyEvent *eventK;
    QTimerEvent *eventT;
    int timerID ;//定时器
    QVector<QPoint> body;
};

#endif // SNAKE_H
