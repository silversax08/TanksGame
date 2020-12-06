#include "Ground.h"
#include <cmath>
#include <QPen>
#include <QBrush>

Ground::Ground()
{
    create_ground_path();
    setPolygon(ground);
    set_brush_and_pen();
}

void Ground::create_ground_path()
{
    ground << QPoint(-30,startingHeight);
    for(int i{-30};i<graphicsViewWidth;i++)
    {
        ground << QPoint(i,return_height_at_point(i));
    }
    ground << QPoint(graphicsViewWidth,600) << QPoint(-30,600) << QPoint(-30,startingHeight);
}

void Ground::set_brush_and_pen()
{
   linePen.setWidth(8);
   linePen.setColor(Qt::darkGreen);

   fillBrush.setColor(Qt::darkGreen);
   fillBrush.setStyle(Qt::SolidPattern);

   setPen(linePen);
   setBrush(fillBrush);
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
    else if(groundSelection==5)
        yPoint = startingHeight-50-100*sin(.01*xPoint);
    else if(groundSelection==6)
        yPoint = startingHeight-200-60*sin(.02*(-450+xPoint))+.000002*pow(xPoint,3);
    else if(groundSelection==7)
        yPoint = startingHeight-100-100*sin(.04*xPoint)-100*sin(.01*xPoint);
    else if(groundSelection==8)
        yPoint = startingHeight-100-20*cos(.02*xPoint);
    else if(groundSelection==9)
        yPoint = startingHeight-200-20*cos(.04*(xPoint+150))-200*cos(.015*(xPoint+150));
    else if(groundSelection==10)
        yPoint = startingHeight-100-20*cos(.02*xPoint);
    else
        yPoint = -xPoint;
    return yPoint;
}
