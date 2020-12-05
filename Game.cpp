#include "Game.h"
#include "GameFunctions.h"

Game::Game(QGraphicsScene *inputScene)
{
    scene = inputScene;
    initialize_tanks();
    add_tanks_to_screen();
    connect(timer,SIGNAL(timeout()),this,SLOT(bullet_move()));
}

void Game::move_tank(std::string direction, int idNumber)
{
    if(idNumber==1)
    {
        if(direction=="Left")
        {
            tank->xPos = tank->xPos-10;
            barrel->xPos = barrel->xPos-10;
        }
        else
        {
            tank->xPos = tank->xPos+10;
            barrel->xPos = barrel->xPos+10;
        }
        tank->yPos = find_tank_vertical_position(tank->xPos);
        tank->setPos(tank->xPos,tank->yPos);
        barrel->setPos(barrel->xPos,find_tank_vertical_position(barrel->xPos));
    }
    else
    {
        if(direction=="Left")
        {
            tank2->xPos = tank2->xPos-10;
            barrel2->xPos = barrel2->xPos-10;
        }
        else
        {
            tank2->xPos = tank2->xPos+10;
            barrel2->xPos = barrel2->xPos+10;
        }
        tank2->yPos = find_tank_vertical_position(tank2->xPos);
        tank2->setPos(tank2->xPos,tank2->yPos);
        barrel2->setPos(barrel2->xPos,find_tank_vertical_position(barrel2->xPos));
    }
}

void Game::rotate_barrel(int angle, int idNumber)
{
    if(idNumber==1)
        barrel->rotate_barrel(angle);
    else
        barrel2->rotate_barrel(angle);
}

void Game::tank_fire(int velocity,int angle, int playerNumber)
{
    bullet = new Bullet(calculate_bullet_position(angle,playerNumber),velocity,angle);
    bullet->setRect(-10,0,5,5);
    scene->addItem(bullet);
    timer->start(deltaT);
}

void Game::initialize_tanks()
{
    tank1Position = {50,find_tank_vertical_position(50)};
    tank2Position = {450,find_tank_vertical_position(450)};
    tank = new TankL(tank1Position[0],tank1Position[1]);
    tank2 = new TankR(tank2Position[0],tank2Position[1]);
    barrel = new BarrelL(tank1Position[0],tank1Position[1]);
    barrel2 = new BarrelR(tank2Position[0],tank2Position[1]);
}

int Game::find_tank_vertical_position(int xPoint)
{
    return ground->return_height_at_point(xPoint)-60;
}

void Game::add_tanks_to_screen()
{
    scene->addItem(ground);
    scene->addItem(tank);
    scene->addItem(tank2);
    scene->addItem(barrel);
    scene->addItem(barrel2);
}

std::array<int,2> Game::calculate_bullet_position(int angle,int tankNumber)
{
    std::array<int,2> tankPosition;
    if(tankNumber==1)
        tankPosition = tank->get_position();
    else
        tankPosition = tank2->get_position();
    return GameFunctions::add_bullet_position_componants_together(angle,tankPosition);
}

void Game::bullet_move()
{
    double bulletPosition = bullet->move();

    QList<QGraphicsItem*> collisions{bullet->collidingItems()};
    for(int i = 0, n = collisions.size(); i < n; ++i)
    {
        if(typeid(*(collisions[i])) == typeid(TankR))
        {
            scene->removeItem(bullet);
            delete bullet;
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
            delete bullet;
            return;
        }
    }
}


