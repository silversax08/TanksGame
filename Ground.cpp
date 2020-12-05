#include "Ground.h"
#include <cmath>

Ground::Ground()
{
    create_ground_path();
    setPolygon(ground);
}

void Ground::create_ground_path()
{
    ground << QPoint(0,startingHeight);
    for(int i{-20};i<graphicsViewWidth;i++)
    {
        ground << QPoint(i,return_height_at_point(i));
    }
    ground << QPoint(graphicsViewWidth,600) << QPoint(0,600) << QPoint(0,startingHeight);
}

int Ground::return_height_at_point(int xPoint)
{
    double e = 2.718;
    int yPoint;
    if(groundSelection==1)
        yPoint = startingHeight-.0005*pow(xPoint,2);
    else if(groundSelection==2)
        yPoint = startingHeight;
    else if(groundSelection==3)
        yPoint = startingHeight+.12*(e*xPoint+e-xPoint)*sin(.01*(xPoint-200));
    else if(groundSelection==4)
        yPoint = startingHeight-80*sin(.01*(xPoint-150));
    else
        yPoint = -xPoint;
    return yPoint;
}
