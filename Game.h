#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <array>
#include "TankL.h"
#include "TankR.h"
#include "BarrelL.h"
#include "BarrelR.h"

class Game
{
public:
    Game(QGraphicsScene* inputScene);
    void move_left_tank(std::string direction);
    void move_right_tank(std::string direction);
    void rotate_left_barrel(int angle);
    void rotate_right_barrel(int angle);
    void left_tank_fire(int velocity,int angle);
    void right_tank_fire(int velocity,int angle);
    void add_bullet();
private:
    QGraphicsScene* scene;
    std::array<int,2> tank1Position{50,350};
    std::array<int,2> tank2Position{450,350};
    TankL* tank{new TankL(tank1Position[0],tank1Position[1],1)};
    TankR* tank2{new TankR(tank2Position[0],tank2Position[1],2)};
    BarrelL* barrel{new BarrelL(tank1Position[0],tank1Position[1])};
    BarrelR* barrel2{new BarrelR(tank2Position[0],tank2Position[1])};
    std::array<int,2> calculate_left_bullet_position(TankL* tank, int angle);
    std::array<int,2> calculate_right_bullet_position(TankR* tank, int angle);
};

#endif // GAME_H
