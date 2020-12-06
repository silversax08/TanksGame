#include "Game.h"
#include "GameFunctions.h"
#include <QDebug>

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
        tank->yPos = find_tank_vertical_position(tank->xPos+50);
        tank->setPos(tank->xPos,tank->yPos);
        barrel->setPos(barrel->xPos,find_tank_vertical_position(barrel->xPos+50));
        rotate_tanks_with_landscape(tank->xPos,idNumber);
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
        tank2->yPos = find_tank_vertical_position(tank2->xPos+50);
        tank2->setPos(tank2->xPos,tank2->yPos);
        barrel2->setPos(barrel2->xPos,find_tank_vertical_position(barrel2->xPos+50));
        rotate_tanks_with_landscape(tank2->xPos,idNumber);
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
    tank1Position = {50,find_tank_vertical_position(100)};
    tank2Position = {450,find_tank_vertical_position(500)};
    tank = new TankL(tank1Position[0],tank1Position[1]);
    tank2 = new TankR(tank2Position[0],tank2Position[1]);
    barrel = new BarrelL(tank1Position[0],tank1Position[1]);
    barrel2 = new BarrelR(tank2Position[0],tank2Position[1]);
    rotate_tanks_with_landscape(50,1);
    rotate_tanks_with_landscape(450,2);
}

int Game::find_tank_vertical_position(int xPoint)
{
    return ground->return_height_at_point(xPoint)-70;
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
    int dX = 50;
    int xPoint1 = xPos+2*dX;
    int yPoint1 = find_tank_vertical_position(xPoint1);
    qDebug()<<yPoint1;
    double xPoint2 = xPos;
    double yPoint2 = find_tank_vertical_position(xPoint2);
    qDebug()<<yPoint2;
    double radianAngle = atan((yPoint1-yPoint2)/(2*dX));
    qDebug()<<radianAngle;
    int angle = 180*radianAngle/3.14;

    if(playerNumber==1)
        tank->roate_tank(angle);
    else
        tank2->roate_tank(angle);
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
    bullet->move();

    QList<QGraphicsItem*> collisions{bullet->collidingItems()};
    for(int i = 0, n = collisions.size(); i < n; ++i)
    {
        if(typeid(*(collisions[i])) == typeid(Ground))
        {
            scene->removeItem(bullet);
//            delete bullet;
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
//            delete bullet;
            return;
        }
    }
}


