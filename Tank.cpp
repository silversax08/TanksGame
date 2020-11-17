#include "Tank.h"
#include <QKeyEvent>
#include <QDebug>
#include <array>

Tank::Tank()
{
    QGraphicsRectItem* rect = new QGraphicsRectItem;
    rect->setRect(xPos,yPos,100,100);
    setPos(xPos,yPos);
}

Tank::Tank(int newXPos, int newYPos)
{
    QGraphicsRectItem* rect = new QGraphicsRectItem;
    rect->setRect(xPos,yPos,100,100);
    setPos(newXPos,newYPos);
}

std::array<int,2> Tank::get_position()
{
    return{xPos,yPos};
}

void Tank::move_tank_left()
{
    xPos = xPos - 10;
    setPos(xPos,yPos);
}

void Tank::move_tank_right()
{
    xPos = xPos + 10;
    setPos(xPos,yPos);
}
