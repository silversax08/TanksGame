#ifndef TANKR_H
#define TANKR_H

#include <QGraphicsItem>

class TankR : public QGraphicsPixmapItem
{
public:
    TankR(int inputXPos, int inputYPos);
    std::array<int,2> get_position();
    void move_tank(std::string direction);
    void roate_tank(int inputAngle);
    int xPos{250};
    int yPos{250};
};

#endif // TANK_H
