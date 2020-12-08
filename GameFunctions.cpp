#include "GameFunctions.h"

std::array<int,2> GameFunctions::add_bullet_position_componants_together(int angle, std::array<int,2> tankPosition)
{
    int imageHalfSize{60};
    std::array<int,2> position;
    std::array<int,2> correction{GameFunctions::calculate_correction_position(angle)};
    position[0] = tankPosition[0] + imageHalfSize + correction[0];
    position[1] = tankPosition[1] + imageHalfSize - correction[1];
    return position;
}


std::array<int,2> GameFunctions::calculate_correction_position(int angle)
{
    int imageHalfSize{60};
    std::array<int,2> correction;
    correction[0] = cos(convert_degrees_to_radians(angle))*imageHalfSize;
    correction[1] = sin(convert_degrees_to_radians(angle))*imageHalfSize;
    if(angle<0)
        correction[0]=-correction[0];
    return correction;
}

double GameFunctions::convert_degrees_to_radians(int angle)
{
    double radians;
    if(angle>=0)
        radians = (90-angle)*3.14/180;
    else
        radians = (90+angle)*3.14/180;
    return radians;
}

//int GameFunctions::rotate_tanks_with_landscape(int xPos, int playerNumber)
//{
//    int dX = 50;
//    int xPoint1 = xPos+2*dX;
//    int yPoint1 = find_tank_vertical_position(xPoint1);
//    double xPoint2 = xPos;
//    double yPoint2 = find_tank_vertical_position(xPoint2);
//    double radianAngle = atan((yPoint1-yPoint2)/(2*dX));
//    int angle = 180*radianAngle/3.14;
//    return angle;
//}
