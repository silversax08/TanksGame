#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QTimer>
#include "TankL.h"
#include "TankR.h"
#include "BarrelL.h"
#include "BarrelR.h"
#include "Bullet.h"
#include "Ground.h"

class Game : public QObject
{ 
    Q_OBJECT
public:
    Game(QGraphicsScene* inputScene);
    void move_tank(std::string direction, int idNumber);
    void rotate_barrel(int angle, int idNumber);
    void tank_fire(int velocity,int angle, int playerNumber);

private:
    QGraphicsScene* scene;
    std::array<int,2> tank1Position;
    std::array<int,2> tank2Position;
    Bullet* bullet;
    TankL* tank{new TankL(tank1Position[0],tank1Position[1])};
    TankR* tank2{new TankR(tank2Position[0],tank2Position[1])};
    BarrelL* barrel{new BarrelL(tank1Position[0],tank1Position[1])};
    BarrelR* barrel2{new BarrelR(tank2Position[0],tank2Position[1])};
    Ground* ground{new Ground};
    std::array<int,2> calculate_bullet_position(int angle, int tankNumber);
    void initialize_tanks();
    int find_tank_vertical_position(int xPoint);
    void add_tanks_to_screen();
    void rotate_tanks_with_landscape(int xPos, int playerNumber);
    int deltaT{50};
    QTimer* timer{new QTimer()};
    int counter{0};

signals:
    void tank1_hit();
    void tank2_hit();

private slots:
    void bullet_move();
};

#endif // GAME_H
