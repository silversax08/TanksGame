#include "Game.h"
#include "GameFunctions.h"
#include "Tank.h"
#include "Barrel.h"

Game::Game(QGraphicsScene *inputScene)
{
    scene = inputScene;
    initialize_tanks();
    add_tanks_to_screen();
    connect(timer,SIGNAL(timeout()),this,SLOT(bullet_move()));
}

void Game::move_tank(std::string direction, int playerNumber)
{
    int oneMove;
    if(direction=="Left")
        oneMove = -10;
    else
        oneMove = 10;

    activeTank->move_tank(activeTank->xPos+oneMove,find_tank_vertical_position(activeTank->xPos+oneMove+xPositionCorrection));
    activeBarrel->move_barrel(activeBarrel->xPos+oneMove,find_tank_vertical_position(activeBarrel->xPos+oneMove+xPositionCorrection));
    rotate_tanks_with_landscape(activeTank->xPos,playerNumber);
}

void Game::rotate_barrel(int angle)
{
    activeBarrel->rotate_barrel(angle);
}

void Game::tank_fire(int velocity,int angle)
{
    bullet = new Bullet(GameFunctions::add_bullet_position_componants_together(angle,activeTank->get_position()),velocity,angle);
    bullet->setRect(-10,0,5,5);
    scene->addItem(bullet);
    int deltaT{50};
    timer->start(deltaT);
}

void Game::set_active_tank(int playerNumber)
{
    if(playerNumber==1)
    {
        activeTank = tank;
        activeBarrel = barrel;
    }
    else
    {
        activeTank = tank2;
        activeBarrel = barrel2;
    }
}

int Game::calculate_tank_rotation_angle(int xPos)
{
    int dX{100};
    double radianToDegreeConversion{180/3.14};

    double point1YPos{find_tank_vertical_position(xPos+dX)};
    double point2YPos{find_tank_vertical_position(xPos)};

    return radianToDegreeConversion*atan((point1YPos-point2YPos)/(dX));
}

void Game::initialize_tanks()
{
    int tankOneStartingPosition{50};
    int tankTwoStartingPosition{450};
    tank = new TankL(tankOneStartingPosition,find_tank_vertical_position(tankOneStartingPosition + xPositionCorrection));
    tank2 = new TankR(tankTwoStartingPosition,find_tank_vertical_position(tankTwoStartingPosition + xPositionCorrection));
    barrel = new BarrelL(tankOneStartingPosition,find_tank_vertical_position(tankOneStartingPosition + xPositionCorrection));
    barrel2 = new BarrelR(tankTwoStartingPosition,find_tank_vertical_position(tankTwoStartingPosition + xPositionCorrection));
    rotate_tanks_with_landscape(tankOneStartingPosition,1);
    rotate_tanks_with_landscape(tankTwoStartingPosition,2);
}

double Game::find_tank_vertical_position(int xPoint)
{
    int correctionHeight{-70};
    return ground->return_height_at_point(xPoint)+correctionHeight;
}

void Game::add_tanks_to_screen()
{
    scene->addItem(ground);
    scene->addItem(tank);
    scene->addItem(tank2);
    scene->addItem(barrel);
    scene->addItem(barrel2);
}

void Game::rotate_tanks_with_landscape(int xPos, int playerNumber)
{
    int angle{calculate_tank_rotation_angle(xPos)};

    if(playerNumber==1)
        tank->roate_tank(angle);
    else
        tank2->roate_tank(angle);
}

void Game::bullet_move()
{
    bullet->move();

    QList<QGraphicsItem*> collisions{bullet->collidingItems()};
    for(int i = 0, n = collisions.size(); i < n; ++i)
    {
        if(typeid(*(collisions[i])) == typeid(Ground))
        {
            scene->removeItem(bullet);
        }
        if(typeid(*(collisions[i])) == typeid(TankL)||typeid(*(collisions[i])) == typeid(TankR)||typeid(*(collisions[i])) == typeid(BarrelL)||typeid(*(collisions[i])) == typeid(BarrelR))
        {
            if(typeid(*(collisions[i])) == typeid(TankL))
            {
                scene->removeItem(barrel);
                delete barrel;
                emit tank1_hit();
            }
            else if(typeid(*(collisions[i])) == typeid(TankR))
            {
                scene->removeItem(barrel2);
                delete barrel2;
                emit tank2_hit();
            }
            else if(typeid(*(collisions[i])) == typeid(BarrelL))
            {
                scene->removeItem(tank);
                delete tank;
                emit tank1_hit();
            }
            else if(typeid(*(collisions[i])) == typeid(BarrelR))
            {
                scene->removeItem(tank2);
                delete tank2;
                emit tank2_hit();
            }
            scene->removeItem(collisions[i]);
            scene->removeItem(bullet);
            delete collisions[i];
            return;
        }
    }
}


