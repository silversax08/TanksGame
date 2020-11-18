#include "Bullet.h"
#include <QTimer>
#include "ProjectileMotion.hpp"
#include <QList>
#include "Tank.h"
#include <QGraphicsScene>


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

double Bullet::get_vertical_position()
{
    return position[1];
}

void Bullet::move()
{
    position = physics->get_position();

    if(position[1] >= 400)
    {
        scene()->removeItem(this);
        delete this;
        return;
    }

    QList<QGraphicsItem*> collisions{collidingItems()};
    for(int i = 0, n = collisions.size(); i < n; ++i)
    {
        if(typeid(*(collisions[i])) == typeid(Tank))
        {
            scene()->removeItem(collisions[i]);
            scene()->removeItem(this);
            delete collisions[i];
            delete this;
            return;
        }
    }

    setPos(position[0],position[1]);
}
