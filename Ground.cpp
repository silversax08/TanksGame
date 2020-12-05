#include "Ground.h"

Ground::Ground()
{
    create_ground_path();
    setPolygon(ground);
}

void Ground::create_ground_path()
{
    for(int i=0;i<100;i++)
    {
        ground << QPoint(i,graphicsViewHeight-i);
    }
    ground << QPoint(5,0) << QPoint (0,graphicsViewHeight);
}
