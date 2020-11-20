#include "Tank.h"
#include <QKeyEvent>
#include <QDebug>
#include <array>

Tank::Tank(int inputXPos, int inputYPos, int tankId)
{
    xPos = inputXPos;
    yPos = inputYPos;
    if(tankId == 1)
        setPixmap(QPixmap(":/myicons/LittleTank.png"));
    else
        setPixmap(QPixmap(":/myicons/LittleTank2.png"));
    setPos(xPos,yPos);

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
