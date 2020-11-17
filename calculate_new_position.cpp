#include "gtest/gtest.h"
#include "ProjectileMotionEquations.hpp"

std::array<double,2> run_position_calculation_function()
{
    std::array<double,2> initalPosition{0.0,0.0};
    std::array<double,2> updatedVelocity{1,1};
    double deltaT{1};

    return utility::calculate_new_position(initalPosition, updatedVelocity,deltaT);
}

TEST(updateBallPosition,whenNewVelocityIsOneAndPreviousPositionIsZero_ExpectCorrectValue)
{
    std::array<double,2> compare{1,1};

    EXPECT_EQ(compare, run_position_calculation_function());
}

TEST(updateBallPosition,whenNewVelocityIsOneAndPreviousPositionIsZeroAndTwoIterationsAreRun_ExpectCorrectValue)
{
    std::array<double,2> compare{1,2};

    std::array<double,2> newPosition{run_position_calculation_function()};

    EXPECT_EQ(compare, utility::calculate_new_position(newPosition,{0.0,1.0},1));
}
