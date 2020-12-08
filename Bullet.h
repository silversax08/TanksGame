#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsRectItem>
#include <QObject>
#include "ProjectileMotion.hpp"

class Bullet : public QObject,public QGraphicsRectItem
{
        Q_OBJECT
public:
    Bullet(std::array<double,2> inputPosition, int inputVelocity, int inputAngle);
    double move();

private:
    ProjectileMotion *physics;
    int deltaT{50};
    std::array<double,2> position;
};

#endif // BULLET_H
