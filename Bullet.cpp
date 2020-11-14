#include "Bullet.h"


Bullet::Bullet()
{
    QGraphicsRectItem* bullet = new QGraphicsRectItem;
    bullet->setRect(position[0],position[1],10,10);
    setPos(position[0],position[1]);
}
