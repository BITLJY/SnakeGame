#include "level.h"
#include <QDebug>

Level::Level(QObject *parent) : QObject(parent), foodCount() // 默认食物数量为1
{}

void Level::setFoodCount(int count)
{
    if (count != foodCount)
    {
        foodCount = count;
        emit foodCountChanged(foodCount); // 发射食物数量变化的信号
    }
}
int Level::getFoodCount() const
{
    return foodCount;
}

const QVector<QPoint>& Level::getObstacles() const
{
    return obstacles;
}
void Level::setObstacles(QString level)
{
    // 清空先前的障碍物
    obstacles.clear();

    // 根据不同的关卡设置障碍物
    if (level == "level1") {
        // 第一关无障碍物
    } else if (level == "level2")
    {
        // 第二关十个离散障碍物
        obstacles << QPoint(100, 100)
                   << QPoint(110, 100)
                   << QPoint(120, 100)
                   << QPoint(130, 100)
                   << QPoint(140, 100)
                   << QPoint(150, 100)
                   << QPoint(160, 100)
                   << QPoint(170, 100)
                   << QPoint(180, 100)
                   << QPoint(190, 100);
    } else if (level == "level3")
    {
        // 第三关四个连续的1*7墙壁
        obstacles << QPoint(100, 100) << QPoint(100, 110) << QPoint(100, 120) << QPoint(100, 130) << QPoint(100, 140) << QPoint(100, 150) << QPoint(100, 160)
                   << QPoint(200, 100) << QPoint(200, 110) << QPoint(200, 120) << QPoint(200, 130) << QPoint(200, 140) << QPoint(200, 150) << QPoint(200, 160)
                   << QPoint(100, 100) << QPoint(110, 100) << QPoint(120, 100) << QPoint(130, 100) << QPoint(140, 100) << QPoint(150, 100) << QPoint(160, 100)
                   << QPoint(100, 200) << QPoint(110, 200) << QPoint(120, 200) << QPoint(130, 200) << QPoint(140, 200) << QPoint(150, 200) << QPoint(160, 200);
    }
    // 可以根据需要添加更多关卡的设置
}
bool Level::isObstacle(const QPoint &point) const
{

    for (const QPoint &obstacle : obstacles)
    {
        int distance = qAbs(point.x() - obstacle.x()) + qAbs(point.y() - obstacle.y());
                if (distance < 10)
                {
            return true;
        }
    }
    return false;
}

