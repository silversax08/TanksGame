#ifndef TANKL_H
#define TANKL_H

#include <QGraphicsItem>

class TankL : public QGraphicsPixmapItem
{
public:
    TankL(int inputXPos, int inputYPos);
    std::array<int,2> get_position();
    void move_tank(std::string direction);
    int xPos{250};
    int yPos{250};
};

#endif // TANK_H
