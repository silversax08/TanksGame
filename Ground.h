#ifndef GROUND_H
#define GROUND_H

#include <QGraphicsPolygonItem>
#include <QPolygon>

class Ground : public QGraphicsPolygonItem
{
public:
    Ground();
    int return_height_at_point(int xPoint);
private:
    void create_ground_path();
//    int groundSelection{rand() % 4 + 1};
    int groundSelection{4};
    QPolygon ground;
    int graphicsViewWidth{616};
    int graphicsViewHeight{578};
    int startingHeight{425};
};

#endif // GROUND_H
