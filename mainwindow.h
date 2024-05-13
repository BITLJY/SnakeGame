#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QPaintEvent>
#include<QTime>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void paintevent(QPaintEvent *pevent);//绘制蛇和食物
    void keyPressEvent(QKeyEvent *kevent);//处理键盘输入（输入上下左右时赋给蛇移动的函数）

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
