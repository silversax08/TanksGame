#include "ProjectileMotion.hpp"
#include "ProjectileMotionEquations.hpp"

ProjectileMotion::ProjectileMotion(int inputVelocity,int inputAngle,std::array<double,2>inputPosition)
{
    position[0] = inputPosition[0];
    position[1] = inputPosition[1];
    velocity = utility::calculate_vector_velocity(inputVelocity,inputAngle);
}

std::array<double,2> ProjectileMotion::get_position()
{
    velocity = utility::calculate_new_velocity(velocity,acceleration,deltaT);
    position = utility::calculate_new_position(position,velocity,deltaT);
    return position;
}

