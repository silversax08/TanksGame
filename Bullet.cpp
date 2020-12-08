#include "Bullet.h"
#include "ProjectileMotion.hpp"


Bullet::Bullet(std::array<double,2> inputPosition, int inputVelocity, int inputAngle)
{
    physics = new ProjectileMotion(inputVelocity, inputAngle, inputPosition);

    QGraphicsRectItem* bullet = new QGraphicsRectItem;
    bullet->setRect(position[0],position[1],10,10);
    setPos(position[0],position[1]);
}

double Bullet::move()
{
    position = physics->get_position();
    setPos(position[0],position[1]);
    return position[1];
}
