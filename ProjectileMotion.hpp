#ifndef PROJECTILEMOTION_HPP
#define PROJECTILEMOTION_HPP

#include <array>

class ProjectileMotion
{
public:
    ProjectileMotion();
    std::array<double,2> get_position();
private:
//    std::array<double,2> calculate_new_velocity();
//    std::array<double,2> calculate_new_position();
    std::array<double,2> position{0.0,0.0};
    std::array<double,2> velocity{0.0,0.0};
    std::array<double,2> acceleration{0,-9.81};
    double deltaT;
//    double mass{10};
//    double dragForce{1};
};

#endif // PROJECTILEMOTION_HPP
