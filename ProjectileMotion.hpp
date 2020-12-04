#ifndef PROJECTILEMOTION_HPP
#define PROJECTILEMOTION_HPP

#include <array>

class ProjectileMotion
{
public:
    ProjectileMotion(int inputVelocity,int inputAngle,std::array<double,2>inputPosition);
    std::array<double,2> get_position();
private:
    std::array<double,2> position{0.0,1.0};
    std::array<double,2> velocity{0.0,0.0};
    std::array<double,2> acceleration{0,-9.81};
    double deltaT{.5};
};

#endif // PROJECTILEMOTION_HPP
