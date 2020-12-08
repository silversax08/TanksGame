#ifndef GAMEFUNCTIONS_H
#define GAMEFUNCTIONS_H
#include <array>

namespace GameFunctions
{
    std::array<int,2> add_bullet_position_componants_together(int angle, std::array<int,2> tankPosition);
    std::array<int,2> calculate_correction_position(int angle);
    double convert_degrees_to_radians(int angle);/*
    int rotate_tanks_with_landscape(int xPos, int playerNumber);*/
}

#endif // GAMEFUNCTIONS_H
