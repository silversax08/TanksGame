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
    std::array<int,2> calculate_bullet_position(int angle, int tankNumber);
    int calculate_tank_rotation_angle(int xPos);
    void initialize_tanks();
    double find_tank_vertical_position(int xPoint);
    void add_tanks_to_screen();
    void rotate_tanks_with_landscape(int xPos, int playerNumber);
    QGraphicsScene *scene;
    Bullet *bullet;
    TankL *tank;
    TankR *tank2;
    BarrelL *barrel;
    BarrelR *barrel2;
    Ground *ground{new Ground};
    int deltaT{50};
    int oneMove{10};
    int xPositionCorrection{50};
    QTimer* timer{new QTimer()};

signals:
    void tank1_hit();
    void tank2_hit();

private slots:
    void bullet_move();
};

#endif // GAME_H
