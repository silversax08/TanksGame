#ifndef BARRELL_H
#define BARRELL_H

#include <QGraphicsItem>

class BarrelL : public QGraphicsPixmapItem
{
public:
    BarrelL(int inputXPos, int inputYPos);
    void move_barrel(std::string direction);
    void rotate_barrel(int inputAngle);
    int xPos{250};

private:
    int yPos{250};
};

#endif // BARREL_H
