#include "BarrelR.h"
#include <QKeyEvent>
#include <QDebug>
#include <array>

BarrelR::BarrelR(int inputXPos, int inputYPos)
{
    xPos = inputXPos;
    yPos = inputYPos;
    setPixmap(QPixmap(":/myicons/Barrell.png"));
    setPos(xPos,yPos);
    setTransformOriginPoint(0,0);
}

void BarrelR::move_barrel_left()
{
    xPos = xPos - 10;
    setPos(xPos,yPos);
}

void BarrelR::move_barrel_right()
{
    xPos = xPos + 10;
    setPos(xPos,yPos);
}

void BarrelR::rotate_barrel(int inputAngle)
{
    setTransformOriginPoint(50,50);
    setRotation(inputAngle);
}
