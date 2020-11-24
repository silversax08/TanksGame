#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QTimer>
#include <array>
#include "TankL.h"
#include "TankR.h"
#include "BarrelL.h"
#include "BarrelR.h"
#include "Bullet.h"

class Game : public QObject
{ 
    Q_OBJECT
public:
    Game(QGraphicsScene* inputScene);
    void move_left_tank(std::string direction);
    void move_right_tank(std::string direction);
    void rotate_left_barrel(int angle);
    void rotate_right_barrel(int angle);
    void left_tank_fire(int velocity,int angle);
    void right_tank_fire(int velocity,int angle);
private:
    QGraphicsScene* scene;
    std::array<int,2> tank1Position{50,350};
    std::array<int,2> tank2Position{450,350};
    int velocity{0};
    int angle{0};
    Bullet* bullet;
    TankL* tank{new TankL(tank1Position[0],tank1Position[1],1)};
    TankR* tank2{new TankR(tank2Position[0],tank2Position[1],2)};
    BarrelL* barrel{new BarrelL(tank1Position[0],tank1Position[1])};
    BarrelR* barrel2{new BarrelR(tank2Position[0],tank2Position[1])};
    std::array<int,2> calculate_left_bullet_position(TankL* tank, int angle);
    std::array<int,2> calculate_right_bullet_position(TankR* tank, int angle);
    int deltaT{50};
    QTimer* timer{new QTimer()};
    int counter{0};

private slots:
    void bullet_move();
};

#endif // GAME_H
