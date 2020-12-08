#include "Barrel.h"

Barrel::Barrel(int inputXPos, int inputYPos)
{
    xPos = inputXPos;
    yPos = inputYPos;
    setPixmap(QPixmap(":/myicons/Barrell.png"));
    setPos(xPos,yPos);
    setTransformOriginPoint(0,0);
}

void Barrel::move_barrel(int newXPos, int newYPos)
{
    xPos = newXPos;
    yPos = newYPos;
    setPos(xPos,yPos);
}

void Barrel::rotate_barrel(int inputAngle)
{
    setTransformOriginPoint(50,50);
    setRotation(inputAngle);
}
