#include "TankR.h"
#include <QKeyEvent>
#include <QDebug>
#include <array>

TankR::TankR(int inputXPos, int inputYPos, int tankId)
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

void TankR::move_tank_left()
{
    xPos = xPos - 10;
    setPos(xPos,yPos);
}

void TankR::move_tank_right()
{
    xPos = xPos + 10;
    setPos(xPos,yPos);
}
