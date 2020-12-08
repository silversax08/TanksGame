#ifndef TANK_H
#define TANK_H

#include <QGraphicsItem>

class Tank : public QGraphicsPixmapItem
{
public:
    Tank(int inputXPos=0, int inputYPos=0);
    std::array<int,2> get_position();
    void move_tank(int newXPos, int newYPos);
    void roate_tank(int inputAngle);
    int xPos{250};
    int yPos{250};
};

#endif // TANK_H
