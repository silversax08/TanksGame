#include "gtest/gtest.h"
#include "ProjectileMotionEquations.hpp"

std::array<double,2> run_velocity_calculation()
{
    std::array<double,2> initalVelocity{0.0,0.0};
    std::array<double,2> updatedAcceleration{0.0,-9.8};
    double deltaT{1};

    return utility::calculate_new_velocity(initalVelocity, updatedAcceleration,deltaT);
}

TEST(updateBallVelocity,whenNewAccelerationIsGravityAndPreviousVelocityIsZero_ExpectCorrectValue)
{
    std::array<double,2> compare{0.0,-9.8};

    EXPECT_EQ(compare,run_velocity_calculation());
}

TEST(updateBallVelocity,whenNewAccelerationIsGravityAndPreviousVelocityIsZeroAndTwoIterationsAreRun_ExpectCorrectValue)
{
    std::array<double,2> compare{0.0,-19.6};

    std::array<double,2> newVelocity{run_velocity_calculation()};

    EXPECT_EQ(compare, utility::calculate_new_velocity(newVelocity,{0.0,-9.8},1));
}
