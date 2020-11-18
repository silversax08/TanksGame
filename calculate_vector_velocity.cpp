#include "gtest/gtest.h"
#include "ProjectileMotionEquations.hpp"
#include <array>

std::array<double,2> run_vector_velocity_function(int angle)
{
    int velocity{1};
    return utility::calculate_vector_velocity(velocity,angle);
}

TEST(calculateVectorVelocity,whenNewVelocityIsOneAndAngleIs90Degrees_ExpectCorrectValue)
{
    std::array<double,2> compare{1,0};
    int angle{90};
    EXPECT_EQ(compare, run_vector_velocity_function(angle));
}

TEST(calculateVectorVelocity,whenNewVelocityIsOneAndAngleIsNegative90Degrees_ExpectCorrectValue)
{
    std::array<double,2> compare{-1,0};
    int angle{-90};
    EXPECT_EQ(compare, run_vector_velocity_function(angle));
}

TEST(calculateVectorVelocity,whenNewVelocityIsOneAndAngleIs45Degrees_ExpectCorrectValue)
{
    std::array<double,2> compare{0.707388,-0.706825};
    int angle{45};
    double tolerance{.001};
    EXPECT_NEAR(compare[0], run_vector_velocity_function(angle)[0],tolerance);
    EXPECT_NEAR(compare[1], run_vector_velocity_function(angle)[1],tolerance);
}

TEST(calculateVectorVelocity,whenNewVelocityIsOneAndAngleIsNegative45Degrees_ExpectCorrectValue)
{
    std::array<double,2> compare{-0.707388,-0.706825};
    int angle{-45};
    double tolerance{.001};
    EXPECT_NEAR(compare[0], run_vector_velocity_function(angle)[0],tolerance);
    EXPECT_NEAR(compare[1], run_vector_velocity_function(angle)[1],tolerance);
}
