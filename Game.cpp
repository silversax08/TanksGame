#include "Game.h"
#include "GameFunctions.h"

Game::Game(QGraphicsScene *inputScene)
{
    scene = inputScene;
    initialize_tanks();
    add_tanks_to_screen();
    connect(timer,SIGNAL(timeout()),this,SLOT(bullet_move()));
}

void Game::move_tank(std::string direction, int playerNumber)
{
    int oneMove{10};
    if(playerNumber==1)
    {
        if(direction=="Left")
        {
            tank->move_tank(tank->xPos-oneMove,find_tank_vertical_position(tank->xPos-oneMove+xPositionCorrection));
            barrel->move_barrel(barrel->xPos-oneMove,find_tank_vertical_position(barrel->xPos-oneMove+xPositionCorrection));
        }
        else
        {
            tank->move_tank(tank->xPos+oneMove,find_tank_vertical_position(tank->xPos+oneMove+xPositionCorrection));
            barrel->move_barrel(barrel->xPos+oneMove,find_tank_vertical_position(barrel->xPos+oneMove+xPositionCorrection));
        }
        rotate_tanks_with_landscape(tank->xPos,playerNumber);
    }
    else
    {
        if(direction=="Left")
        {
            tank2->move_tank(tank2->xPos-oneMove,find_tank_vertical_position(tank2->xPos-oneMove+xPositionCorrection));
            barrel2->move_barrel(barrel2->xPos-oneMove,find_tank_vertical_position(barrel2->xPos-oneMove+xPositionCorrection));
        }
        else
        {
            tank2->move_tank(tank2->xPos+oneMove,find_tank_vertical_position(tank2->xPos+oneMove+xPositionCorrection));
            barrel2->move_barrel(barrel2->xPos+oneMove,find_tank_vertical_position(barrel2->xPos+oneMove+xPositionCorrection));
        }
        rotate_tanks_with_landscape(tank2->xPos,playerNumber);
    }

}

void Game::rotate_barrel(int angle, int playerNumber)
{
    if(playerNumber==1)
        barrel->rotate_barrel(angle);
    else
        barrel2->rotate_barrel(angle);
}

void Game::tank_fire(int velocity,int angle, int playerNumber)
{
    bullet = new Bullet(calculate_bullet_position(angle,playerNumber),velocity,angle);
    bullet->setRect(-10,0,5,5);
    scene->addItem(bullet);
    int deltaT{50};
    timer->start(deltaT);
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

std::array<int,2> Game::calculate_bullet_position(int angle,int playerNumber)
{
    std::array<int,2> tankPosition;
    if(playerNumber==1)
        tankPosition = tank->get_position();
    else
        tankPosition = tank2->get_position();
    return GameFunctions::add_bullet_position_componants_together(angle,tankPosition);
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


