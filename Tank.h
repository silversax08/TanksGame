#ifndef TANK_H
#define TANK_H

#include <QGraphicsItem>
#include <QGraphicsRectItem>

class Tank : public QGraphicsRectItem
{
public:
    Tank();
    void key_press_event(QKeyEvent* event);
    void move_tank_left();
    void move_tank_right();
private:
    int xPos{250};
    int yPos{212};
};

#endif // TANK_H
