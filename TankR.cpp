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

void TankR::move_tank(int direction)
{
    if(direction==1)
        xPos = xPos - 10;
    else
        xPos = xPos + 10;
    setPos(xPos,yPos);
}
