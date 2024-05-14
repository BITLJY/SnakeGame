#ifndef SNAKE_H
#define SNAKE_H
#include<QPoint>
#include<QKeyEvent>
#include <QWidget>
#include<QTime>
#include<QTimer>
#include<deque>

class Snake:public QWidget
{
public:
    Snake(){};
    Snake(int xsnake,int ysnake);// 初始化蛇
    Snake(QWidget *parent = nullptr) : QWidget(parent) {
            // 启动定时器
            timerID= startTimer(200);
        }
    void move();//蛇的移动
    enum Direction {
        Up,
        Down,
        Left,
        Right
    };
    void keyPressEvent(QKeyEvent *event);
    void timerEvent(QTimerEvent *event);
    int getlength()const;//获取蛇的长度
    const QPoint& at(int index) const;//获取蛇的身体节（按从头到尾的顺序）

private:
    std::deque<QPoint> snakebody;//双端队列定义

    int xsnake,ysnake;//初始化的位置（一般为界面中心）
    int maxL;//蛇的最大长度
    Direction direction;
    void addhead(const QPoint& position);//增加新的一节在头
    void rmtail();//删除尾巴
    void grow();//吃到食物后增加一节蛇

    bool ateFood();//是否吃到食物
    bool crashed();//是否碰撞

    QTimer* timer;//用于获取随机数
    QKeyEvent *eventK;
    QTimerEvent *eventT;
    int timerID ;//定时器
};

#endif // SNAKE_H
