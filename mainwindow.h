#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QPaintEvent>
#include<QPainter>
#include<QTime>
#include<deque>
#include"snake.h"
#include"Direction.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    Snake *snake;
    ~MainWindow();
    inline int getscore(){return this->score;};
    void paintEvent(QPaintEvent *pevent);//绘制蛇和食物
    void keyPressEvent(QKeyEvent *kevent);//处理键盘输入（输入上下左右时赋给蛇移动的函数）
    Direction direction;
private:
    Ui::MainWindow *ui;
    int score;//得分
};
#endif // MAINWINDOW_H
