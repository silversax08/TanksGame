#include "TankR.h"
#include <array>

TankR::TankR(int inputXPos, int inputYPos)
{
    xPos = inputXPos;
    yPos = inputYPos;
    setPixmap(QPixmap(":/myicons/LittleTank3.png"));
    setPos(xPos,yPos);
}

std::array<int,2> TankR::get_position()
{
    return{xPos,yPos};
}

void TankR::move_tank(std::string direction)
{
    if(direction=="Left")
        xPos = xPos - 10;
    else
        xPos = xPos + 10;
    setPos(xPos,yPos);
}

void TankR::roate_tank(int inputAngle)
{
    setTransformOriginPoint(50,50);
    setRotation(inputAngle);
}
