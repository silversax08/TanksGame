#include "gtest/gtest.h"
#include "GameFunctions.h"

void test_add_bullet_componants_together(int angle,std::array<int,2> position, std::array<int,2> compare)
{

    std::array<double,2> newPosition{GameFunctions::add_bullet_position_componants_together(angle,position)};
    int tolerance{1};
    EXPECT_NEAR(compare[0],newPosition[0],tolerance);
    EXPECT_NEAR(compare[1],newPosition[1],tolerance);
}

void test_calculate_correction_position(int angle, std::array<int,2> compare)
{
    std::array<int,2> position{GameFunctions::calculate_correction_position(angle)};
    int tolerance{1};
    EXPECT_NEAR(compare[0],position[0],tolerance);
    EXPECT_NEAR(compare[1],position[1],tolerance);
}

void test_convert_degrees_to_radians(int angle, double compare)
{
    double calculatedAngle{GameFunctions::convert_degrees_to_radians(angle)};
    double tolerance{.001};
    EXPECT_NEAR(compare,calculatedAngle,tolerance);
}

TEST(AddBulletPositionComponantsTogether,GivenTankPositionIs0AndAngleIs0_WhenAddingBulletPositionComponantsTogether_ExpectCorrectValue)
{
    std::array<int,2> compare{60,0};
    int angle{0};
    std::array<int,2> position{0,0};
    test_add_bullet_componants_together(angle,position,compare);
}

TEST(AddBulletPositionComponantsTogether,GivenTankPositionIs0AndAngleIsPositive_WhenAddingBulletPositionComponantsTogether_ExpectCorrectValue)
{
    std::array<int,2> compare{120,60};
    int angle{90};
    std::array<int,2> position{0,0};
    test_add_bullet_componants_together(angle,position,compare);
}

TEST(AddBulletPositionComponantsTogether,GivenTankPositionIs0AndAngleIsNegative_WhenAddingBulletPositionComponantsTogether_ExpectCorrectValue)
{
    std::array<int,2> compare{0,60};
    int angle{-90};
    std::array<int,2> position{0,0};
    test_add_bullet_componants_together(angle,position,compare);
}

TEST(AddBulletPositionComponantsTogether,GivenTankPositionIs100100AndAngleIs0_WhenAddingBulletPositionComponantsTogether_ExpectCorrectValue)
{
    std::array<int,2> compare{160,100};
    int angle{0};
    std::array<int,2> position{100,100};
    test_add_bullet_componants_together(angle,position,compare);
}

TEST(CalculateCorrectionPosition,GivenAngleIsZero_WhenCalculatingCorrectionPosition_ExpectCorrectValue)
{
    std::array<int,2> compare{0,60};
    int angle{0};
    test_calculate_correction_position(angle,compare);
}

TEST(CalculateCorrectionPosition,GivenAngleIsPositive_WhenCalculatingCorrectionPosition_ExpectCorrectValue)
{
    std::array<int,2> compare{18,57};
    int angle{18};
    test_calculate_correction_position(angle,compare);
}

TEST(CalculateCorrectionPosition,GivenAngleIsNegative_WhenCalculatingCorrectionPosition_ExpectCorrectValue)
{
    std::array<int,2> compare{-18,57};
    int angle{-18};
    test_calculate_correction_position(angle,compare);
}

TEST(ConvertDegreesToRadians,GivenDegreesAreZero_WhenConvertingDegreesToRadians_ExpectCorrectValue)
{
    double compare{1.5708};
    int angle{0};
    test_convert_degrees_to_radians(angle,compare);
}

TEST(ConvertDegreesToRadians,GivenDegreesArePositive_WhenConvertingDegreesToRadians_ExpectCorrectValue)
{
    double compare{1.09956};
    int angle{27};
    test_convert_degrees_to_radians(angle,compare);
}

TEST(ConvertDegreesToRadians,GivenDegreesAreNegative_WhenConvertingDegreesToRadians_ExpectCorrectValue)
{
    double compare{1.09956};
    int angle{-27};
    test_convert_degrees_to_radians(angle,compare);
}
