#include "BarrelL.h"

BarrelL::BarrelL(int inputXPos, int inputYPos)
{
    xPos = inputXPos;
    yPos = inputYPos;
    setPixmap(QPixmap(":/myicons/Barrell.png"));
    setPos(xPos,yPos);
    setTransformOriginPoint(0,0);
}

void BarrelL::move_barrel(int direction)
{
    if(direction==1)
        xPos = xPos - 10;
    else
        xPos = xPos + 10;
    setPos(xPos,yPos);
}

void BarrelL::rotate_barrel(int inputAngle)
{
    setTransformOriginPoint(50,50);
    setRotation(inputAngle);
}
