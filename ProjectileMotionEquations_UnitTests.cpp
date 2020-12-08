#include "gtest/gtest.h"
#include "ProjectileMotionEquations.hpp"
#include <array>

std::array<double,2> run_position_calculation_function()
{
    std::array<double,2> initalPosition{0.0,0.0};
    std::array<double,2> updatedVelocity{1,1};
    double deltaT{1};

    return utility::calculate_new_position(initalPosition, updatedVelocity, deltaT);
}

std::array<double,2> run_velocity_calculation()
{
    std::array<double,2> initalVelocity{0.0,0.0};
    std::array<double,2> updatedAcceleration{1,-9.8};
    double deltaT{1};

    return utility::calculate_new_velocity(initalVelocity, updatedAcceleration,deltaT);
}

void test_calculate_vector_velocity_function(int angle, std::array<double,2> compare)
{
    int velocity{1};
    std::array<double,2> newVelocity{utility::calculate_vector_velocity(velocity,angle)};

    double tolerance{.001};
    EXPECT_NEAR(compare[0], newVelocity[0],tolerance);
    EXPECT_NEAR(compare[1], newVelocity[1],tolerance);
}

TEST(CalculateNewPosition,GivenNewVelocityIsOneAndPreviousPositionIsZero_WhenCalculatingNewPosition_ExpectCorrectValue)
{
    std::array<double,2> compare{1,1};
    EXPECT_EQ(compare, run_position_calculation_function());
}

TEST(CalculateNewPosition,GivenNewVelocityIsOneAndPreviousPositionIsZeroAndTwoIterationsAreRun_WhenCalculatingNewPosition_ExpectCorrectValue)
{
    std::array<double,2> compare{1,2};
    std::array<double,2> newPosition{run_position_calculation_function()};
    EXPECT_EQ(compare, utility::calculate_new_position(newPosition,{0.0,1.0},1));
}

TEST(CalculateNewVelocity,GivenNewAccelerationIsGravityAndPreviousVelocityIsZero_WhenCalculatingNewVelocity_ExpectCorrectValue)
{
    std::array<double,2> compare{1,9.8};
    EXPECT_EQ(compare,run_velocity_calculation());
}

TEST(CalculateNewVelocity,GivenNewAccelerationIsGravityAndPreviousVelocityIsZeroAndTwoIterationsAreRun_WhenCalculatingNewVelocity_ExpectCorrectValue)
{
    std::array<double,2> compare{1,19.6};
    std::array<double,2> newVelocity{run_velocity_calculation()};
    EXPECT_EQ(compare, utility::calculate_new_velocity(newVelocity,{0.0,-9.8},1));
}

TEST(CalculateVectorVelocity,GivenNewVelocityIsOneAndAngleIs90Degrees_WhenCalculatingVectorVelocity_ExpectCorrectValue)
{
    std::array<double,2> compare{1,0};
    int angle{90};
    test_calculate_vector_velocity_function(angle,compare);
}

TEST(CalculateVectorVelocity,GivenNewVelocityIsOneAndAngleIsNegative90Degrees_WhenCalculatingVectorVelocity_ExpectCorrectValue)
{
    std::array<double,2> compare{-1,0};
    int angle{-90};
    test_calculate_vector_velocity_function(angle,compare);
}

TEST(CalculateVectorVelocity,GivenNewVelocityIsOneAndAngleIs45Degrees_WhenCalculatingVectorVelocity_ExpectCorrectValue)
{
    std::array<double,2> compare{0.707388,-0.706825};
    int angle{45};
    test_calculate_vector_velocity_function(angle,compare);
}

TEST(CalculateVectorVelocity,GivenNewVelocityIsOneAndAngleIsNegative45Degrees_WhenCalculatingVectorVelocity_ExpectCorrectValue)
{
    std::array<double,2> compare{-0.707388,-0.706825};
    int angle{-45};
    test_calculate_vector_velocity_function(angle,compare);
}
