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
