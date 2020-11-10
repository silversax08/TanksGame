#include "Tank.h"
#include <QKeyEvent>
#include <QDebug>

Tank::Tank()
{
    QGraphicsRectItem* rect = new QGraphicsRectItem;
    rect->setRect(xPos,yPos,100,100);
    setPos(xPos,yPos);
}

void Tank::key_press_event(QKeyEvent* event)
{
    qDebug() << "Key Pushed";
    if (event->key() == Qt::Key_Left)
        setPos(x()-10,y());
}

void Tank::move_tank_left()
{
    xPos = xPos - 10;
    setPos(xPos,yPos);
}

void Tank::move_tank_right()
{
    xPos = xPos + 10;
    setPos(xPos,yPos);
}
