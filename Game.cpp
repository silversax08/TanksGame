#include "Game.h"
#include "Bullet.h"


Game::Game(QGraphicsScene *inputScene)
{
    scene = inputScene;
    scene->addItem(tank);
    scene->addItem(tank2);
    scene->addItem(barrel);
    scene->addItem(barrel2);
}

void Game::move_left_tank(std::string direction)
{
    if(direction == "Left")
    {
        tank->move_tank_left();
        barrel->move_barrel_left();
    }
    else
    {
        tank->move_tank_right();
        barrel->move_barrel_right();
    }
}

void Game::move_right_tank(std::string direction)
{
    if(direction == "Left")
    {
        tank2->move_tank_left();
        barrel2->move_barrel_left();
    }
    else
    {
        tank2->move_tank_right();
        barrel2->move_barrel_left();
    }
}

void Game::rotate_left_barrel(int angle)
{
    barrel->rotate_barrel(angle);
}

void Game::rotate_right_barrel(int angle)
{
    barrel2->rotate_barrel(angle);
}

void Game::left_tank_fire(int velocity,int angle)
{
    Bullet* bullet{new Bullet(tank->get_position(),velocity,angle)};
    bullet->setRect(-10,0,5,5);
    scene->addItem(bullet);
}

void Game::right_tank_fire(int velocity, int angle)
{
    Bullet* bullet{new Bullet(tank2->get_position(),velocity,angle)};
    bullet->setRect(-10,0,5,5);
    scene->addItem(bullet);
}


