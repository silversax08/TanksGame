#ifndef GROUND_H
#define GROUND_H

#include <QGraphicsPolygonItem>
#include <QPolygon>
#include <QPen>
#include <QBrush>

class Ground : public QGraphicsPolygonItem
{
public:
    Ground();
    int return_height_at_point(int xPoint);
private:
    void create_ground_path();
    void set_brush_and_pen();
//    int groundSelection{rand() % 4 + 1};
    int groundSelection{4};
    QPolygon ground;
    int graphicsViewWidth{616};
    int graphicsViewHeight{578};
    int startingHeight{425};
    QPen linePen;
    QBrush fillBrush;
};

#endif // GROUND_H
