#ifndef GAMEVISUAL_H
#define GAMEVISUAL_H

#include <QWidget>
#include <QGraphicsScene>
#include "Game.h"

namespace Ui {
class GameVisual;
}

class GameVisual : public QWidget
{
    Q_OBJECT

public:
    explicit GameVisual(QWidget *parent = nullptr);
    ~GameVisual();
    Ui::GameVisual *ui;
    Game* game;

private:
    void move_tank(std::string direction);
    QPixmap startScreen{QPixmap(":/myicons/startscreen.png")};
    void fire_bullet();
    void rotate_barrel();
    QGraphicsScene* scene{new QGraphicsScene};
    int velocity{10};
    int angle{0};
    int playerNumber{1};
    int moveCount{0};
    int maxMovementPerTurn{5};

private slots:
    void on_LaunchButton2_clicked();
    void on_VelocitySlider2_sliderMoved(int position);
    void on_AngleSlider2_sliderMoved(int position);
    void on_VelocitySlider2_valueChanged(int value);
    void on_AngleSlider2_valueChanged(int value);
    void on_leftButton2_clicked();
    void on_rightButton2_clicked();

};



#endif // GAMEVISUAL_H
