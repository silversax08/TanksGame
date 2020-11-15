#ifndef PROJECTILEMOTIONEQUATIONS_HPP
#define PROJECTILEMOTIONEQUATIONS_HPP

#include <array>

namespace utility
{
std::array<double,2> calculate_new_velocity(std::array<double,2> oldVelocity, std::array<double,2> newAcceleration, double deltaT);
std::array<double,2> calculate_new_position(std::array<double,2> oldPosition, std::array<double,2> newVelocity, double deltaT);
std::array<double,2> calculate_vector_velocity(int inputVelocity,int inputAngle);
}

#endif // PROJECTILEMOTIONEQUATIONS_HPP
