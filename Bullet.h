#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsRectItem>
#include <array>

class Bullet : public QGraphicsRectItem
{
public:
    Bullet();
private:
    int Velocity{0};
    int angle{0};
    std::array<int,2> position{250,212};
};

#endif // BULLET_H
