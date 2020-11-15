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
    Bullet();
    ProjectileMotion* physics{new ProjectileMotion()};
private:
    int velocity{0};
    int angle{0};
    int deltaT{50};
    std::array<int,2> position{250,212};
private slots:
    void move();
};

#endif // BULLET_H
