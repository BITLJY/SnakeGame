#ifndef LEVEL_H
#define LEVEL_H

#include <QObject>
#include <QList>
#include "Food.h"
#include <QPoint>

class Level:public QObject
{
    Q_OBJECT
public:
    explicit Level(QObject *parent = nullptr);

    // 添加设定食物数量的函数
    void setFoodCount(int count);
    int getFoodCount() const;
    Level(int initialSpeed) : m_initialSpeed(initialSpeed){};
    int getInitialSpeed() const { return m_initialSpeed; };// 设置障碍物的位置
    const QVector<QPoint>& getObstacles() const; // 获取障碍物的位置
    void setObstacles(QString level);
    void setObstacles(const QVector<QPoint> &obstacles) {this->obstacles = obstacles;}
    bool isObstacle(const QPoint &point) const;

signals:
    // 发射食物数量变化的信号
    void foodCountChanged(int count);

private:
    int foodCount; // 食物数量
    int m_initialSpeed;
    QVector<QPoint> obstacles;
};

#endif // LEVEL_H
