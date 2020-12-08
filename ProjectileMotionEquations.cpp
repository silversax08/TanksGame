#include "ProjectileMotionEquations.hpp"

std::array<double,2> utility::calculate_new_velocity(std::array<double,2> oldVelocity, std::array<double,2> newAcceleration, double deltaT)
{
    std::array<double,2> newVelocity;

    newVelocity[0] = oldVelocity[0]+newAcceleration[0]*deltaT;
    newVelocity[1] = oldVelocity[1]-newAcceleration[1]*deltaT;

    return newVelocity;
}

std::array<double, 2> utility::calculate_new_position(std::array<double, 2> oldPosition, std::array<double, 2> newVelocity, double deltaT)
{
    std::array<double,2> newPosition;

    for (size_t i{0}; i < newPosition.size(); i++)
    {
        newPosition[i] = oldPosition[i]+newVelocity[i]*deltaT;
    }

    return newPosition;
}

std::array<double,2> utility::calculate_vector_velocity(int inputVelocity, int inputAngle)
{
    std::array<double,2> velocity{0.0,0.0};
    double degreeToRadianConversion{3.14/180};

    if (inputAngle >= 0)
    {
        double angle{(90-inputAngle)*degreeToRadianConversion};
        velocity[0] = inputVelocity*cos(angle);
        velocity[1] = -inputVelocity*sin(angle);
    }
    else
    {
        double angle{(90+inputAngle)*degreeToRadianConversion};
        velocity[0] = -inputVelocity*cos(-angle);
        velocity[1] = inputVelocity*sin(-angle);
    }

    return velocity;
}
