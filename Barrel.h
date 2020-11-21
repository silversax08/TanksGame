#ifndef BARREL_H
#define BARREL_H

#include <QGraphicsItem>
#include <QGraphicsRectItem>

class Barrel : public QGraphicsPixmapItem
{
public:
    Barrel(int inputXPos, int inputYPos);
    void move_barrel_left();
    void move_barrel_right();
    void rotate_barrel(int inputAngle);
private:
    int xPos{250};
    int yPos{250};
};

#endif // BARREL_H
