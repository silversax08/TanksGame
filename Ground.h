#ifndef GROUND_H
#define GROUND_H

#include <QGraphicsPolygonItem>
#include <QPolygon>

class Ground : public QGraphicsPolygonItem
{
public:
    Ground();
private:
    void create_ground_path();
    QPolygon ground;
    int graphicsViewWidth{616};
    int graphicsViewHeight{578};
};

#endif // GROUND_H
