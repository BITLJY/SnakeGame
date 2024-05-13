#ifndef LEVEL_H
#define LEVEL_H

#include <QMainWindow>

namespace Ui {
class Level;
}

class Level : public QMainWindow
{
    Q_OBJECT

public:
    explicit Level(QWidget *parent = nullptr);
    ~Level();

private:
    Ui::Level *ui;
};

#endif // LEVEL_H
