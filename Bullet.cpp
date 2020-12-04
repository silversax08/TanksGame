#include "Bullet.h"
#include "ProjectileMotion.hpp"


Bullet::Bullet(std::array<int,2> inputPosition, int inputVelocity, int inputAngle)
{
    position[0] = inputPosition[0];
    position[1] = inputPosition[1];
    velocity = inputVelocity;
    angle = inputAngle;

    physics = new ProjectileMotion(velocity,angle,position);

    QGraphicsRectItem* bullet = new QGraphicsRectItem;
    bullet->setRect(position[0],position[1],10,10);
    setPos(position[0],position[1]);
}

double Bullet::get_vertical_position()
{
    return position[1];
}

double Bullet::move()
{
    position = physics->get_position();
    setPos(position[0],position[1]);
    return position[1];
}
