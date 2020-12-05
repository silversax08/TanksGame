#include "Ground.h"
#include <QDebug>


Ground::Ground()
{
    create_ground_y_values();
    setPolygon(ground);
    setPos(-20,100);
}

void Ground::create_ground_y_values()
{
    for(int i=0;i<100;i++)
    {
        ground << QPoint(i,10-i);
    }
    ground << QPoint{5,0} << QPoint(0,10);
}

QPen Ground::create_pen()
{
    QPen pen(Qt::red, 3, Qt::DashDotLine, Qt::RoundCap, Qt::RoundJoin);
    return pen;
}
