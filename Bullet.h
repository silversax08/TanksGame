#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsRectItem>
#include <array>
#include <QObject>
#include "ProjectileMotion.hpp"
#include "ProjectileMotionEquations.hpp"

class Bullet : public QObject,public QGraphicsRectItem
{
        Q_OBJECT
public:
    Bullet(std::array<int,2> inputPosition);
    ProjectileMotion* physics;
private:
    int velocity{0};
    int angle{0};
    int deltaT{50};
    std::array<double,2> position;
private slots:
    void move();
};

#endif // BULLET_H
