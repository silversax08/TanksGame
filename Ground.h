#ifndef GROUND_H
#define GROUND_H

#include <QGraphicsPolygonItem>
#include <QPolygon>
#include <QPen>

class Ground : public QGraphicsPolygonItem
{
public:
    Ground();
    void create_ground_y_values();
    QPen create_pen();
    std::vector<int> groundYPoints;
    std::vector<int> groundXPoints;
private:
    QPolygon ground;
    int graphicsViewWidth{616};
    int graphicsViewHeight{578};
};

#endif // GROUND_H
