#include "Game.h"
#include "Bullet.h"
#include "TankL.h"
#include "TankR.h"
#include <array>


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
    Bullet* bullet{new Bullet(calculate_left_bullet_position(tank,angle),velocity,angle)};
    bullet->setRect(-10,0,5,5);
    scene->addItem(bullet);
}

void Game::right_tank_fire(int velocity, int angle)
{
    Bullet* bullet{new Bullet(calculate_right_bullet_position(tank2,angle),velocity,angle)};
    bullet->setRect(-10,0,5,5);
    scene->addItem(bullet);
}

std::array<int,2> Game::calculate_left_bullet_position(TankL* tank, int angle)
{
    std::array<int,2> correction;
    int image_half_size{50};
    if(angle>=0)
    {
        correction[0] = cos((90-angle)*3.14/180)*image_half_size;
        correction[1] = sin((90-angle)*3.14/180)*image_half_size;
    }
    else
    {
        correction[0] = -cos((90+angle)*3.14/180)*image_half_size;
        correction[1] = sin((90+angle)*3.14/180)*image_half_size;
    }


    std::array<int,2> position;
    std::array<int,2> tankPosition{tank->get_position()};
    position[0] = tankPosition[0] + image_half_size + correction[0];
    position[1] = tankPosition[1] + image_half_size - correction[1];
    return position;
}

std::array<int,2> Game::calculate_right_bullet_position(TankR* tank, int angle)
{
    std::array<int,2> correction;
    int image_half_size{50};
    if(angle>=0)
    {
        correction[0] = cos((90-angle)*3.14/180)*image_half_size;
        correction[1] = sin((90-angle)*3.14/180)*image_half_size;
    }
    else
    {
        correction[0] = -cos((90+angle)*3.14/180)*image_half_size;
        correction[1] = sin((90+angle)*3.14/180)*image_half_size;
    }


    std::array<int,2> position;
    std::array<int,2> tankPosition{tank->get_position()};
    position[0] = tankPosition[0] + image_half_size + correction[0];
    position[1] = tankPosition[1] + image_half_size - correction[1];
    return position;
}


