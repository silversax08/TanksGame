#ifndef BARRELR_H
#define BARRELR_H

#include <QGraphicsItem>

class BarrelR : public QGraphicsPixmapItem
{
public:
    BarrelR(int inputXPos, int inputYPos);
    void move_barrel(std::string direction);
    void rotate_barrel(int inputAngle);
    int xPos{250};

private:
    int yPos{250};
};

#endif // BARREL_H
