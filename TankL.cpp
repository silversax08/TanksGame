#include "TankL.h"
#include <QKeyEvent>
#include <QDebug>
#include <array>

TankL::TankL(int inputXPos, int inputYPos, int tankId)
{
    xPos = inputXPos;
    yPos = inputYPos;
    setPixmap(QPixmap(":/myicons/LittleTank3.png"));
    setPos(xPos,yPos);

}

std::array<int,2> TankL::get_position()
{
    return{xPos,yPos};
}

void TankL::move_tank_left()
{
    xPos = xPos - 10;
    setPos(xPos,yPos);
}

void TankL::move_tank_right()
{
    xPos = xPos + 10;
    setPos(xPos,yPos);
}
