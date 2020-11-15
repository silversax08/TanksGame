#include "ProjectileMotion.hpp"
#include "ProjectileMotionEquations.hpp"

ProjectileMotion::ProjectileMotion()
{
    position[0] = 255;
    position[1] = 255;
    velocity = utility::calculate_vector_velocity(10,45);
    deltaT = 50;
}

std::array<double,2> ProjectileMotion::get_position()
{
    velocity = utility::calculate_new_velocity(velocity,acceleration,deltaT);
    position = utility::calculate_new_position(position,velocity,deltaT);
    return position;
}
