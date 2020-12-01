#ifndef TANKR_H
#define TANKR_H

#include <QGraphicsItem>
#include <QGraphicsRectItem>

class TankR : public QGraphicsPixmapItem
{
public:
    TankR(int inputXPos, int inputYPos, int tankId);
    std::array<int,2> get_position();
    void move_tank_left();
    void move_tank_right();
private:
    int xPos{250};
    int yPos{250};
};

#endif // TANK_H