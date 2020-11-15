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

std::array<double,2> utility::calculate_vector_velocity(int inputVelocity, int inputAngle)
{
    std::array<double,2> velocity{0.0,0.0};

    if (inputAngle >= 0)
    {
        double angle{(90-inputAngle)*3.14/180};
        velocity[0] = inputVelocity*cos(angle);
        velocity[1] = inputVelocity*sin(angle);
    }
    else
    {
        double angle{(90+inputAngle)*3.14/180};
        velocity[0] = -inputVelocity*cos(-angle);
        velocity[1] = -inputVelocity*sin(-angle);
    }

    return velocity;
}
