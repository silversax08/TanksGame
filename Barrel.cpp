#include "Barrel.h"
#include <QKeyEvent>
#include <QDebug>
#include <array>

Barrel::Barrel(int inputXPos, int inputYPos)
{
    xPos = inputXPos;
    yPos = inputYPos;
    setPixmap(QPixmap(":/myicons/Barrell.png"));
    setPos(xPos,yPos);
    setTransformOriginPoint(0,0);
}

void Barrel::move_barrel_left()
{
    xPos = xPos - 10;
    setPos(xPos,yPos);
}

void Barrel::move_barrel_right()
{
    xPos = xPos + 10;
    setPos(xPos,yPos);
}

void Barrel::rotate_barrel(int inputAngle)
{
    setTransformOriginPoint(50,50);
    setRotation(inputAngle);
}
