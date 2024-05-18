#include <QMainWindow>
#include <QPaintEvent>
#include <QPainter>
#include <QTime>
#include <deque>
#include "snake.h"
#include "Directions.h"
#include "Food.h"
#include "level.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    inline int getScore() { return score; }

    void paintEvent(QPaintEvent *event1); // 绘制蛇和食物
    void keyPressEvent(QKeyEvent *event2); // 处理键盘输入（输入上下左右时赋给蛇移动的函数）
    void initGame(); // 初始化游戏

private slots:
    void on_pB_on_pushbutton_start_clicked();
    void on_pB_on_pushbutton_restart_clicked();
    void on_pB_on_pushbutton_select_clicked();
    void on_pB_on_pushbutton_stop_clicked();
    void on_pB_on_pushbutton_goon_clicked();
    void on_Score_overflow();

private:
    Ui::MainWindow *ui;
    QSize gameAreaSize;
    int score; // 得分
    Snake *snake;
    QList<Food*> foods;
    Food *food; // 食物数组
    Level *currentLevel;
    Direction direction;
    QVector<QPoint> foodPositions;
};
