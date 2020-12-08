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
    void move_tank(std::string direction, int playerNumber);
    void rotate_barrel(int angle);
    void tank_fire(int velocity,int angle);
    void set_active_tank(int playerNumber);

private:
    int calculate_tank_rotation_angle(int xPos);
    void initialize_tanks();
    double find_tank_vertical_position(int xPoint);
    void add_tanks_to_screen();
    void rotate_tanks_with_landscape(int xPos, int playerNumber);
    Tank *activeTank;
    Barrel *activeBarrel;
    QGraphicsScene *scene;
    Bullet *bullet;
    TankL *tank;
    TankR *tank2;
    BarrelL *barrel;
    BarrelR *barrel2;
    Ground *ground{new Ground};
    int xPositionCorrection{50};
    QTimer* timer{new QTimer()};

signals:
    void tank1_hit();
    void tank2_hit();

private slots:
    void bullet_move();
};

#endif // GAME_H
