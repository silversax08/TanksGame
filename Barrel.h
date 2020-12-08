#ifndef BARREL_H
#define BARREL_H

#include <QGraphicsItem>

class Barrel : public QGraphicsPixmapItem
{
public:
    Barrel(int inputXPos=0, int inputYPos=0);
    void move_barrel(int newXPos, int newYPos);
    void rotate_barrel(int inputAngle);
    int xPos{250};
    int yPos{250};
};

#endif // BARREL_H
