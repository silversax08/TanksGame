#ifndef BARRELR_H
#define BARRELR_H

#include <QGraphicsItem>

class BarrelR : public QGraphicsPixmapItem
{
public:
    BarrelR(int inputXPos, int inputYPos);
    void move_barrel_left();
    void move_barrel_right();
    void rotate_barrel(int inputAngle);

private:
    int xPos{250};
    int yPos{250};
};

#endif // BARREL_H
