#ifndef TANK_H
#define TANK_H

#include <QGraphicsItem>
#include <QGraphicsRectItem>

class Tank : public QGraphicsRectItem
{
public:
    Tank();
    Tank(int newXPos, int newYPos);
    std::array<int,2> get_position();
    void move_tank_left();
    void move_tank_right();
private:
    int xPos{250};
    int yPos{212};
};

#endif // TANK_H
