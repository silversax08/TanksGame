#include "ProjectileMotionEquations.hpp"

std::array<double,2> utility::calculate_new_velocity(std::array<double,2> oldVelocity, std::array<double,2> newAcceleration, double deltaT)
{
    std::array<double,2> newVelocity;

    for (size_t i{0}; i < newVelocity.size(); i++)
    {
        newVelocity[i] = oldVelocity[i]+newAcceleration[i]*deltaT;
    }

    return newVelocity;
}
