#include "BarrelL.h"

BarrelL::BarrelL(int inputXPos, int inputYPos)
{
    xPos = inputXPos;
    yPos = inputYPos;
    setPixmap(QPixmap(":/myicons/Barrell.png"));
    setPos(xPos,yPos);
    setTransformOriginPoint(0,0);
}

void BarrelL::move_barrel(std::string direction)
{
    int stepSize{10};
    if(direction=="Left")
        xPos = xPos - stepSize;
    else
        xPos = xPos + stepSize;
    setPos(xPos,yPos);
}

void BarrelL::rotate_barrel(int inputAngle)
{
    setTransformOriginPoint(50,50);
    setRotation(inputAngle);
}
