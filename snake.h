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
#include <QMediaPlayer>
#include <QMediaPlaylist>

#include"Directions.h"
#include "level.h"

class Snake:public QWidget
{
public:
    Snake(){};
    explicit Snake(int xs, int ys, QWidget *parent = nullptr);
    void move();//蛇的移动
    int single=0;
    int single1=0;
    Direction direction;
    void timerEvent(QTimerEvent *event);
    void setDirection(Direction newDirection);
    const std::deque<QPoint>& getBody() const {return snakebody; }
    QTimer* getTimer() const { return timer; }
    QPoint getBoundingRect() const; // 获取蛇的包围矩形边界

    std::deque<QPoint> snakebody;//双端队列定义

    void adjustSpeed();
    void startGame();
    void stopGame();
    void reset();
    void setLevel(Level *level);
    void setFoodCount(int count);
    bool isSnakeBody(const QPoint &point) const;
    void setInitialSpeed(int speed)
    {
        initialSpeed = speed;
        adjustSpeed(); // 根据新的初始速度调整实际速度
    }
    //音乐播放器
    QMediaPlayer *gameSound = new QMediaPlayer;//创建播放器
    QMediaPlaylist *gameList = new QMediaPlaylist;//创建播放列表
    int flag=0;

private:
    int xsnake,ysnake;//初始化的位置（一般为界面中心）
    int maxL;//蛇的最大长度
    int foodEatenCount;
    void addhead(const QPoint& position);//增加新的一节在头
    void rmtail();//删除尾巴
    void grow();//吃到食物后增加一节蛇
    bool ateFood();//是否吃到食物
    bool crashed();//是否碰撞

    bool gameRunning;
    int speedLevel;
    QTimer* timer;//用于获取随机数
    QKeyEvent *eventK;
    QTimerEvent *eventT;
    int timerID ;//定时器
    int timeCounter;
    QVector<QPoint> body;
    Level *currentLevel;
    int initialSpeed;

};

#endif // SNAKE_H
