#ifndef LOGIN_H
#define LOGIN_H

#include <QApplication>
#include <QWidget>
#include <QPaintEvent>
#include <QPainter>
#include <QFont>
#include <QDesktopWidget>

namespace Ui {
class login;
}

class login : public QWidget
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();

private slots:
    void on_pB_in_clicked();
    void on_pB_exit_clicked();//退出游戏

private:
    Ui::login *ui;
};


#endif // LOGIN_H
