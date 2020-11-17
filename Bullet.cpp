#include "Bullet.h"
#include <QTimer>
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

    QTimer* timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(deltaT);
}

void Bullet::move()
{
    std::array<double,2> tempPosition{physics->get_position()};
    setPos(tempPosition[0],tempPosition[1]);
}
