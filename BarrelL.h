#ifndef BARRELL_H
#define BARRELL_H

#include <QGraphicsItem>

class BarrelL : public QGraphicsPixmapItem
{
public:
    BarrelL(int inputXPos, int inputYPos);
    void move_barrel_left();
    void move_barrel_right();
    void rotate_barrel(int inputAngle);

private:
    int xPos{250};
    int yPos{250};
};

#endif // BARREL_H
