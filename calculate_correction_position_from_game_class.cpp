#include "gtest/gtest.h"
#include "GameFunctions.h"
#include <array>

TEST(calculateCorrectionPosition,whenAngleIsZero_ExpectCorrectValue)
{
    std::array<int,2> compare{0,60};
    int input{0};
    std::array<int,2> position{GameFunctions::calculate_correction_position(input)};
    EXPECT_NEAR(compare[0],position[0],1);
    EXPECT_NEAR(compare[1],position[1],1);
}

TEST(calculateCorrectionPosition,whenAngleIsPositive_ExpectCorrectValue)
{
    std::array<int,2> compare{18,57};
    int input{18};
    std::array<int,2> position{GameFunctions::calculate_correction_position(input)};
    EXPECT_NEAR(compare[0],position[0],1);
    EXPECT_NEAR(compare[1],position[1],1);
}

TEST(calculateCorrectionPosition,whenAngleIsNegative_ExpectCorrectValue)
{
    std::array<int,2> compare{-18,57};
    int input{-18};
    std::array<int,2> position{GameFunctions::calculate_correction_position(input)};
    EXPECT_NEAR(compare[0],position[0],1);
    EXPECT_NEAR(compare[1],position[1],1);
}
